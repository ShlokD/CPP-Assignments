//////////////////////////////////////////////////////////////////////////
// FileName:	SelectionSort.cpp
// Description: Implementation of methods and constructor of class to implement Selection Sort
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Description of methods for iterative and recursive selection sort on arrays and vectors
//////////////////////////////////////////////////////////////////////////


#include "SelectionSort.h"
using namespace std;

// Constructor
SelectionSort::SelectionSort(int o)
{
	order = o; // set order for sorting, ascending or descending
}//end constructor

// Function to sort array iteratively
void SelectionSort::sortIterative(int arr[], int size)
{
	int index = 0; // variable to get index of item to be swapped
	for (int i = 0; i < size; ++i)
	{
		index = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (order == 0) // sort ascending i.e high to low
			{
				if (arr[j] < arr[index]) // if current index is less, swap
				{
					index = j;
				}
			}
			else if (order == 1) // sort descending i.e low to high
			{
				if (arr[j] > arr[index]) // if current index is higher, swap
				{
					index = j;
				}
			}
		} // end j loop

		if (i != index) // swap elements
		{
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		} //end if
	}// end i loop
}// end function sortIterative(int[],int)

// Function to sort vector iteratively
void SelectionSort::sortIterative(vector<int>& vec, int size)
{
	int index = 0; // index to point to element to be swapped
	for (int i = 0; i < size; ++i)
	{
		index = i; // get current element
		for (int j = i + 1; j < size; ++j)  // compare with rest of elements
		{
			if (order == 0) // sort ascending i.e low to high
			{
				if (vec.at(j) < vec.at(index)) // if next element is lower, it has to be swapped
				{
					index = j;
				}
			}
			else if (order == 1) // sort descending i.e high to low
			{
				if (vec.at(j) > vec.at(index)) // if next element is higher, it has to be swapped
				{
					index = j;
				}
			}
		}// end j loop

		if (i != index) // Swap elements
		{
			int temp = vec.at(i);
			vec.at(i)= vec.at(index);
			vec.at(index) = temp;
		}// end if
	}// end i loop
}// end function sortIterative(vector&, int)

// Function to sort arrays recursively
void SelectionSort::sortRecursive(int arr[], int size)
{
	int index = 0; // index of element to be swapped in current array

	for (int i = index; i < size; ++i) // Loop through elements
	{
		if (order == 0) // Ascending sort
		{
			if (arr[i] > arr[index]) // If element is higher, it has to be swapped
			{
				index = i;
			}
		}
		else if (order == 1) // Descending sort
		{
			if (arr[i]<arr[index]) // If element is lower, it has to be swapped
			{
				index = i;
			}
		}
	} // end loop

	// Swap the element with the last element of the array
	int temp = arr[index];
	arr[index] = arr[size - 1];
	arr[size - 1] = temp;
	
	// Reduce the size of the array by 1 and repeat the process
	if (size > 1)
	{
		sortRecursive(arr, size - 1);
	}
	else
	{
		return; // If there is only element in the array, go back to the previous call
	} 
} // end function sortRecursive(int[],int)

// Function to sort vector recursively
void SelectionSort::sortRecursive(vector<int>& vec,int size)
{
	int index = 0; // Index of swapped element

	for (int i = index; i < size; ++i)
	{
		if (order == 0) // Ascending sort
		{
			if (vec.at(i) > vec.at(index)) //If element is higher, it has to be swapped
			{
				index = i;
			}
		}
		else if (order == 1) // Descending sort
		{
			if (vec.at(i)<vec.at(index)) // If element is lower, it has to be swapped
			{
				index = i;
			}
		}
	} // end loop

	// Swap the indexed element and the last element
	int temp = vec.at(index);
	vec.at(index) = vec.at(size - 1);
	vec.at(size - 1) = temp;

	// Reduce the size of the vector and run the function again
	if (size > 1)
	{
		sortRecursive(vec, size - 1);
	}
	else // If vector only has 1 element, return to the earlier function call
	{
		return;
	}
} // end function sortRecursive(vector&, int)