// sortingAlgorithm.cpp : Defines the entry point for the console application.

#include <iostream>
#include <ctime> 
#include <vector>
#include <queue>
#include <set>
#include <iterator>

//Function prototypes

//Function that will print the contents of our vector
void display(std::vector<int> & myVect);





//These are my sorting algorithms. NOTE:(pass-by-reference)
//Lets run the function and determine the running time for each sorting alogrithm.
void minSort(std::vector<int> & myVect, int size);

void bubbleSort(std::vector<int> & vect, int size);

void insertionSort(std::vector<int> & A, int size);

void Rmerge(std::queue<int> & A, std::queue<int> & B,std::queue<int> & C);






int main()
{
	std::cout << "\n\nThis program will go over the different types of Sorting Algorithms.\n"<< std::endl;

        std::cout << "\n\nLets get an vector with random values:\n";
	std::cout << "Pick the size of the array(1-20)? ";
	int size;
	std::cin >> size;
	
	

	while (size < 1 || size > 20)
	{
		std::cout << "\n\nTry again: Pick the size of the vector(1-20)? ";
		std::cin >> size;
	}
	//We got the size that the user wants.


	
	std::cout << "\n\n\nLets do minSort on this vector with random values.\n";
	std::cout << "\nThis vector will be sorted using the minSort algorithm:\n\n";

	//Create our vector and populate it with random numbers. (Running time is O(n) )	
	std::vector<int> myVect;

	srand(time(NULL));

	for (int m = 0; m < size; m++)
	{
		myVect.push_back( (rand() % 500) + 1 ); //Produce an element between 1-500.
	} 

	//We now have the vector that we wanted so diplay the element and state that this step is k = 0
	std::cout << "At k = 0\n";
	display(myVect);


	//Run the minSort function.
	//What is the running time for minSort?    =   
	minSort(myVect,size);
	//We are done with minSort
	



	


	//Now lets create a new vector and do bubbleSort on this new vector.

	std::vector<int> vect;

	for (int m = 0; m < size; m++)
	{
		vect.push_back((rand() % 500) + 1); //Produce an element between 1-500.
	}
	std::cout << "\n\n\n\n\nThis vector will be sorted using the bubbleSort algorithm\n\n";

	//We now have the vector that we wanted so diplay the element and state that this step is k = 0
	std::cout << "\nAt k = 0\n";
	display(vect);


	bubbleSort(vect, size);


	//Now lets create a new vector and do insertionSort on this new vector.

	std::vector<int> A;

	for (int m = 0; m < size; m++)
	{
		A.push_back((rand() % 500) + 1); //Produce an element between 1-500.
	}
	std::cout << "\n\n\n\n\nThis vector will be sorted using the insertionSort algorithm\n\n";

	//We now have the vector that we wanted so diplay the element and state that this step is k = 0
	std::cout << "\nAt k = 0\n";
	display(A);


	insertionSort(A, size);





	//Nows lets write code for my Recursive merge algorithm


	//Create 3 vectors of the same lenght

	std::queue<int> queueA;
	std::queue<int> queueB;	
	std::set<int> setA;
	std::set<int> setB;

	for (int r = 0; r < 6; r++)
	{
		setA.insert((rand() % 5000) + 1);
		setB.insert((rand() % 5000) + 1);
	}

	std::set<int>::iterator it = setA.begin();
	std::set<int>::iterator itEnd = setA.end();
	std::cout << "\n\n\nFor the recursive merge, \nA = ";

	while (it != itEnd)
	{
		if (it != std::prev(itEnd))
		{
			std::cout << *it << ",";
		}
		else
		{
			std::cout << *it;

		}
		
		
		queueA.push(*it);

		++it;
	}
	std::cout << "\nB = ";

	std::set<int>::iterator itB = setB.begin();
	std::set<int>::iterator itBEnd = setB.end();

	while (itB != itBEnd)
	{
		if (itB != std::prev(itBEnd))
		{
			std::cout << *itB << ",";
		}
		else 
		{
			std::cout << *itB << "\n\n";

		}
		queueB.push(*itB);

		++itB;
	}




	std::queue<int> queueC;

	

	//Now lets recursive merge A and B in order to get C as a sorted vector
	//C will be printed
	Rmerge(queueA, queueB, queueC);

	std::cout << "The resulting array of the Recursive Merge of A and B is:\nC = ";

	int temporary;
	//C should now be sorted, so lets display the values
	while (!queueC.empty())
	{
		temporary = queueC.front();
		queueC.pop();
		std::cout << temporary << "   ";
	}
	std::cout << "\n\n";

    return 0;
}



//Function to display the vector.
//The runnning time for the display function is: O(n)
void display(std::vector<int> & myVect)
{
	for (int n = 0; n < myVect.size(); n++)
	{
		if (n != myVect.size() - 1)
		{

			std::cout << myVect[n] << ",";
		}
		else
		{
			std::cout << myVect[n] << "\n\n";
		}
	}

}


//The loop invariant of the minSort:
//After the kth pass thorugh the outer for loop
//the first k positions A[1] to A[k]
//contain the first k smallest elements in order
//The running time for the the selection sort algorithm is: O(n^2)
void minSort(std::vector<int> & myVect, int size)
{

	//For all the positions except the last postion
	for (int k = 0; k < size-1; k++)
	{
		//Set the min to be equal to the element in that position k
		//Set the index to be the kth position
		int min = myVect[k];
		int index = k;
		
		//Traverse through all the elements in the vector or array except the values that already have been previously setup
		//Use j to keep track of this loop
		for (int j = k + 1; j < size ; j++)
		{

			//If we find a smaller element in the array than the min.
			//Set the smaller element to be the min and then save the index value j.
			if (myVect[j] < min)
			{
				min = myVect[j];
				index = j;
			}
			
		}


		std::cout << "At k = " << k + 1 << "\n";

		//We now have the min to swap with the position k.

		//First place the position kth element into the min position index
		//Then place the min value into the kth position.
		myVect[index] = myVect[k];
		myVect[k] = min;

		display(myVect);
	}
}


// THe loop invariant of the BubbleSort
//After the kth run through the outer for loop 
//The last i elements are the largest elements in the array and in sorted order.


//Function that uses the bubbleSort algorithm
//The running time for bubble sort is:  O(n^2)
void bubbleSort(std::vector<int> & vect, int size)
{
	int temp;

	//For all the elements in the array, except the last two elements
	for (int i = 0; i < size - 2; i++)
	{
		//For all the elements, except the last element. 
		for (int j = 0; j < size - i -1 ; j++)
		{
			//If we find that the visisted element is greater than the next element
			//Then we must swap these two elements.
			if (vect[j] > vect[j + 1])
			{
				temp = vect[j + 1];
				vect[j + 1] = vect[j];
				vect[j] = temp;
			}
			
		}
		//This comparison goes on for the all the elements, so in the end the last kth elements must be sorted
		std::cout << "At k = " << i + 1 << "\n";

		display(vect);
	}
}


//The loop invariant of the insertion sort
//After the ith iteration through the outer forloop 
//the first i+1 elements are sorted.


//Function that uses the insertionSort algorithm
void insertionSort(std::vector<int> & A, int size)
{
	for (int i = 1; i < size; i++) 
	{
		int element = A[i];
		int j = i;

		while (j > 0 && A[j - 1] > element)
		{
			A[j] = A[j - 1];
			j = j - 1;
		}
		
		A[j] = element;
		std::cout << "At k = " << i << "\n";

		display(A);
	
	}

}

//Recursive merge function
void Rmerge(std::queue<int> & A, std::queue<int> & B, std::queue<int> & C)
{

	//If array A is empty, place the remaining elementsof B into the C array and we are done
	if (A.empty())
	{
		int tempB;
		//Place the rest of the B elements into the C vector
		while (!B.empty())
		{
			tempB = B.front();
			C.push(tempB);
			B.pop();
		}
		return;
	}
	
	
	//If array B is empty, place the remaining elements of A into the C array and we are done
	if (B.empty())
	{
		int tempA;
		//Place the rest of the A elements into the C vector
		while (!A.empty())
		{
			tempA = A.front();
			C.push(tempA);
			A.pop();
		}
		return ;
	}



	//This is where we compare the values of A[0] and B[0]
	//The smaller element will be placed in the C array 

	if ((A.front()) <= (B.front()))
	{
		C.push(A.front());
		A.pop();
		Rmerge(A, B, C);
	}
	else
	{

		C.push(B.front());
		B.pop();
		Rmerge(A, B, C);
	}

}

