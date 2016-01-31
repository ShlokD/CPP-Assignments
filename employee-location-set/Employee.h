//////////////////////////////////////////////////////////////////////////
// FileName:	Employee.h
// Description: Class declaration and methods to implement Employee class
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Declaration of Employee class and its constructor and methods
//////////////////////////////////////////////////////////////////////////
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Point.h"
#include<string>
using namespace std;

class Employee
{
public:
	Employee(string name, int x, int y); // Constructor
	Point getCoordinates(); // get co-ordinates of employee
	void setCoordinates(Point &pt); // set co-ordinates of employee
	string getName(); // get employee name
	void setName(string name);// set employee name
private:
	string empName; // employee's name
	Point p; // Point where employee is located
};//end class Employee

#endif