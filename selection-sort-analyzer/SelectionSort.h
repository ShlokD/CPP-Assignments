//////////////////////////////////////////////////////////////////////////
// FileName:	SelectionSort.h
// Description: Declaration of methods and constructor of class to implement Selection Sort
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Declaration of methods for iterative and recursive selection sort and private
//              data member to fix order
//////////////////////////////////////////////////////////////////////////

#include <vector>
using namespace std;

class SelectionSort
{
public:
	SelectionSort(int order = 0); // Constructor, order is defaulted to ascending
	void sortIterative(int arr[], int size); // Sort array using iteration
	void sortRecursive(int arr[], int size); // Sort array using recursion
	void sortIterative(vector<int>& vec,int size); // Sort vector using iteration
	void sortRecursive(vector<int>& vec, int size); // Sort vector using recursion
private:
	int order; // variable to enforce sorting order, 0 for ascending, 1 for descending

};