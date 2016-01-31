//////////////////////////////////////////////////////////////////////////
// FileName:	EmployeeLoc.cpp
// Description: Driver program to get employee's name and location
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Main and helper functions to implement the driver program
//////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <string>
#include "Employee.h"
#include "Location.h"
#include "Point.h"
using namespace std;

void printEmployeeLocation(Employee &e, Location &l); // Helper function to print the location

// Main function
int main(int argc, char* argv[])
{
	// Create the objects to be used
	Location l;
	Employee e("default", 0, 0);
	Point p;
	// Values to be entered by user
	string name;
	int x = 0;
	int y = 0;

	while (true) // Until user enters -1 for X or Y, keep asking for input
	{
		cout << "Enter Employee Name: ";
		cin >> name;
		cout << "Enter X(-1 to exit):";
		cin >> x;
		cout << "Enter Y(-1 to exit):";
		cin >> y;
		if (x == -1 || y == -1)
		{
			break;
		}
		// Reset the point where employee is
		p.setX(x);
		p.setY(y);
		// Set the employee name
		e.setName(name);
		// Set the employee coordinates
		e.setCoordinates(p);
		// Print the location
		printEmployeeLocation(e, l);
	
	}
	return 0;
}// end function main

// Function to print the employee location
void printEmployeeLocation(Employee &e, Location &l)
{
	// get the location of the point where employee is
	int loc = l.getLocation(e.getCoordinates());
	string ename = e.getName();
	cout << endl;
	// Print out appropriate message
	if (loc == 1)
	{
		cout << ename << " is in New York" << endl;
	}
	else if (loc == 2)
	{
		cout << ename << " is in San Francisco" << endl;
	}
	else if (loc == 3)
	{
		cout << ename << " is in Los Angeles" << endl;
	}
	else if (loc == 4)
	{
		cout << ename << " is in Chicago" << endl;
	}
	else
	{
		cout << ename << "\'s location not found" << endl;
	}
	cout << endl;
}// end function printEmployeeLocation