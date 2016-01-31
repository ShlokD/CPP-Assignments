//////////////////////////////////////////////////////////////////////////
// FileName:	Point.cpp
// Description: Definition of methods to implement Point class
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition of Point class constructors and methods
//////////////////////////////////////////////////////////////////////////
#include"Point.h"

// Default Constructor
Point::Point()
{
	x = 0;
	y = 0;
}// end default constructor

// Constructor with initial values
Point::Point(int xc, int yc)
{
	x = xc;
	y = yc;
}// end constructor

// Function to set the x-coordinate of the point
void Point::setX(int xc)
{
	x = xc;
}// end function setX

// Function to get the x-coordinate of the point
int Point::getX()
{
	return x;
}// end function getX

// Function to set the y-coordinate of the point
void Point::setY(int yc)
{
	y = yc;
}// end function setY

// Function to get the y-coordinate of the point
int Point::getY()
{
	return y;
}// end function getY