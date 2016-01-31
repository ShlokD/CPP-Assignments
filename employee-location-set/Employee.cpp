//////////////////////////////////////////////////////////////////////////
// FileName:	Employee.cpp
// Description: Definition of methods to implement Set class
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition of Employee class constructors and methods
//////////////////////////////////////////////////////////////////////////

#include "Employee.h"

// Constructor
Employee::Employee(string name, int x, int y)
{
	empName = name;
	p.setX(x);
	p.setY(y);
} // end constructor

// Function to get point representing co-ordinates of employee
Point Employee::getCoordinates()
{
	return p;
}// end function getCoordinates

// Function to set coordinates of the employee
void Employee::setCoordinates(Point &pt)
{
	p.setX(pt.getX());
	p.setY(pt.getY());
}// end function setCoordinates

// Function to get the name of the employee
string Employee::getName()
{
	return empName;
}// end function getName

// Function to set the name of the employee
void Employee::setName(string name)
{
	empName = name;
}// end function setName