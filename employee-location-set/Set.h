//////////////////////////////////////////////////////////////////////////
// FileName:	Set.h
// Description: Class declaration and methods to implement Set class
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Declaration of Set class and its constructor and methods
//////////////////////////////////////////////////////////////////////////

#ifndef SET_H
#define SET_H

#include<vector>
using namespace std;

// Class definition
class Set
{
public:
	Set(); // default constructor
	Set(vector<bool> &v); // constructor from vector
	bool isMember(int x); // check if member is present
	Set Union(Set &s); // Union operation
	Set Intersection(Set &s); // Interesection operation
	void print(); // print the set
	void setTrue(int loc); // adds member to set
	void setFalse(int loc); // removes member from set
private:
	vector<bool> members; // members of the set
};// end class Set
#endif