//////////////////////////////////////////////////////////////////////////
// FileName:	Point.h
// Description: Class declaration and methods to implement Point class
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Declaration of Point class and its constructor and methods
//////////////////////////////////////////////////////////////////////////

#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point(); // Default constructor
	Point(int xc, int yc); // Constructor
	int getY();// get y-coordinate
	void setY(int yc);// set y-coordinate
	int getX();// get x-coordinate
	void setX(int xc); // set x-coordinate
private:
	int x;// x-coordinate
	int y;// y-coordinate
};//end class Point
#endif