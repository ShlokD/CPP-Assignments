//////////////////////////////////////////////////////////////////////////
// FileName:	Set.cpp
// Description: Definition of methods to implement Set class
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition of Set class constructors and methods
//////////////////////////////////////////////////////////////////////////

#include "Set.h"
#include <iostream>
#include <vector>
using namespace std;

// Default constructor
Set::Set() :members(21) // Create vector of enough space using initializer list
{
	// Set all members to false i.e empty set
	for (int i = 0; i <= 20; ++i)
	{
		members.at(i) = false;
	}
}// end default constructor

// Constructor using vector
Set::Set(vector<bool> &v)
{
	members = v; // assign vector to member vector
}//end constructor

// Function to add member to set
void Set::setTrue(int loc)
{
	members.at(loc) = true;
}// end function setTrue

// Function to remove member from set
void Set::setFalse(int loc)
{
	members.at(loc) = false;
}// end function setFalse

// Function to print set
void Set::print()
{
	cout << "{ ";
	for (int i = 0; i <members.size(); ++i)
	{
		if (members.at(i)) cout << i << " ";
	}
	cout << "}" << endl;
}// end function print

// Function to check if a number is member of set
bool Set::isMember(int x)
{
	return members.at(x);
} // end function isMember

// Function to carry out union of two sets
Set Set::Union(Set& s)
{
	vector<bool> newv(21);// New set's members
	for (int i = 0; i <= 20; ++i)
	{
		if (s.isMember(i) || this->isMember(i)) // if member is in either set, it is in the union
		{
			newv.at(i) = true;
		}
	}
	Set snew(newv); // create new set
	return snew;
} // end function Union

// Function to carry out intersection of two sets
Set Set::Intersection(Set& s)
{
	vector<bool> newv(21);// New set's members
	for (int i = 0; i <= 20; ++i)
	{
		if (s.isMember(i) && this->isMember(i)) // If member is in both sets, it is in the intersection
		{
			newv.at(i) = true;
		}
	}
	Set snew(newv); // create new set
	return snew;
}// end function Intersection