//////////////////////////////////////////////////////////////////////////
// FileName:	Main.cpp
// Description: Driver program to run selection sort on vectors and arrays as well as
//              helper functions to print their contents.
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Main function which is the entry point of the program and helper functions
//////////////////////////////////////////////////////////////////////////

#include "TimeStamp.h" // TimeStamp class
#include "SelectionSort.h" // SelectionSort class
#include <cstdlib> // system
#include <ctime> // time
#include <iostream> // cin, cout
#include<vector> // STL Vector library
#include<iomanip>

using namespace std;


// Function declarations
template<class T> 
void printData(T, unsigned int); // Print contents of array or vector

template<class T> 
void fillData(T, unsigned int); // Add random elements to array or vector

void copyArray(int[], int[], int); // Helper function to copy an array to another
int getOrder(void); // Helper function to get ascending or descending order from user

int main(int argc, char* argv[])
{
	const unsigned int SMALL_SIZE = 20; //Size of small array or vector
	const unsigned int LARGE_SIZE = 28000;// Size of large array or vector
	int order = getOrder(); // Get order of sorting whether ascending or descending
	srand((unsigned int)time(0)); // Seed for rand() functions
	SelectionSort sorter(order); //Create a selection sort object with sorting order value
	TimeStamp ts; // TimeStamp object
	int arrSmall[SMALL_SIZE]; // Small Array
	int arrLarge[LARGE_SIZE]; // Large Array
	vector<int> vecSmall(SMALL_SIZE); // Small Vector
	vector<int> vecLarge(LARGE_SIZE);// Large Vector

	// Fill data in small array and create its copy
	fillData<int[]>(arrSmall, SMALL_SIZE);
	int arrSmallCopy[SMALL_SIZE] = {0};
	copyArray(arrSmall, arrSmallCopy, SMALL_SIZE);

	// Fill data in large array and create its copy
	fillData<int[]>(arrLarge, LARGE_SIZE);
	int arrLargeCopy[LARGE_SIZE] = { 0 };
	copyArray(arrLarge, arrLargeCopy, LARGE_SIZE);

	// Fill data in small vector and create its copy
	fillData<vector<int>&>(vecSmall, vecSmall.size());
	vector<int> vecSmallCopy = vecSmall;
	
	// Fill data in large vector and create its copy
	fillData<vector<int>&>(vecLarge, vecLarge.size());
	vector<int> vecLargeCopy = vecLarge;

	// Perform Selection Sort on small array using iteration and print sorted array
	cout << endl;
	cout << "Printing Unsorted Array" << endl;
	printData(arrSmall, SMALL_SIZE);
	cout << endl;
	sorter.sortIterative(arrSmall, SMALL_SIZE); 
	cout << "Printing Sorted Array Using Iteration" << endl;
	printData(arrSmall, SMALL_SIZE);
	cout << endl;

	// Perform Selection Sort on small array using recursion and print sorted array
	cout << endl;
	cout << "Printing Unsorted Array" << endl;
	printData(arrSmallCopy, SMALL_SIZE);
	cout << endl;
	sorter.sortRecursive(arrSmallCopy, SMALL_SIZE);
	cout << "Printing Sorted Array Using Recursion" << endl;
	printData(arrSmallCopy, SMALL_SIZE);
	cout << endl;

	// Perform Selection Sort on small vector using iteration and print vector
	cout << endl;
	cout << "Printing Unsorted Vector" << endl;
	printData(vecSmall, vecSmall.size());
	cout << endl;
	sorter.sortIterative(vecSmall,vecSmall.size());
	cout << "Printing Sorted Vector Using Iteration" << endl;
	printData(vecSmall,vecSmall.size());
	cout << endl;

	// Perform Selection Sort on small vector using recursion and print vector
	cout << endl;
	cout << "Printing Unsorted Vector" << endl;
	printData(vecSmallCopy, vecSmallCopy.size());
	cout << endl;
	sorter.sortRecursive(vecSmallCopy, vecSmallCopy.size());
	cout << "Printing Sorted Vector Using Recursion" << endl;
	printData(vecSmallCopy, vecSmallCopy.size());
	cout << endl;

	// Perform Selection Sort on large array using iteration and print time stamps before and after
	// sort is called
	cout << endl;
	cout << "Start sort of large array using iteration" << endl;
	cout << ts.GetTime() << endl;
	sorter.sortIterative(arrLarge, LARGE_SIZE);
	cout << "Sorting ended" << endl;
	cout << ts.GetTime() << endl;
	cout << endl;

	// Perform Selection Sort on large array using recursion and print time stamps before and after
	// sort is called
	cout << endl;
	cout << "Start sort of large array using recursion" << endl;
	cout << ts.GetTime() << endl;
	sorter.sortRecursive(arrLargeCopy, LARGE_SIZE);
	cout << "Sorting ended" << endl;
	cout << ts.GetTime() << endl;
	cout << endl;

	// Perform Selection Sort on large vector using iteration and print time stamps before and after
	// sort is called
	cout << endl;
	cout << "Start sort of large vector using iteration" << endl;
	cout << ts.GetTime() << endl;
	sorter.sortIterative(vecLarge, vecLarge.size());
	cout << "Sorting ended" << endl;
	cout << ts.GetTime() << endl;
	cout << endl;

	// Perform Selection Sort on large vector using recursion and print time stamps before and after
	// sort is called
	cout << endl;
	cout << "Start sort of large vector using recursion" << endl;
	cout << ts.GetTime() << endl;
	sorter.sortIterative(vecLargeCopy, vecLargeCopy.size());
	cout << "Sorting ended" << endl;
	cout << ts.GetTime() << endl;
	cout << endl;

	return 0;
} // end main

// Function to print data of array or vector
template <class T>
void printData(T data, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i) 
	{
		cout << data[i] << " "; //[] can be used to reference elements of vectors and arrays
	}
} // end function printData

// Function to insert data in array or vector
template <class T>
void fillData(T data, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		data[i] = 20 + rand() % 1000; // Inserts random integers between 20 and 1000
	}

}// end function fillData

// Function to copy one array into another
void copyArray(int source[], int dest[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		dest[i] = source[i]; // Copy each element of source array to destination array
	}
} // end function copyArrat

// Function to get sorting order
int getOrder()
{
	int order = -1;
	while (order != 0 && order != 1) // Until user enters correct order, keep asking for input
	{
		cout << "Please enter sorting order. 0 for ascending, 1 for descending:";
		cin >> order;
		if (order != 0 && order != 1) // Print message as incorrect value inputted
		{
			cout << "Incorrect Selection" << endl;
		}
	}
	return order;
}// end function getOrder