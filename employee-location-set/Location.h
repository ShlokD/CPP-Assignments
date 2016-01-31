//////////////////////////////////////////////////////////////////////////
// FileName:	Location.h
// Description: Class declaration and methods to implement Location class
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Declaration of Location class and its constructor and methods
//////////////////////////////////////////////////////////////////////////

#ifndef LOCATION_H
#define LOCATION_H

#include "Set.h"
#include "Point.h"
class Location
{
public:
	enum LOCATION{ NOT_FOUND, NEWYORK, SANFRANCISCO, LOSANGELES, CHICAGO }; // enum of locations
	Location(); // Constructor
	LOCATION getLocation(Point &p); // Get Location from points
private:
	// Sets to represent X and Y co-ordinates of various cities
	// New York
	Set NYX;
	Set NYY;
	// San Francisco
	Set SFX;
	Set SFY;
	// Los Angeles
	Set LAX;
	Set LAY;
	// Chicago
	Set CHX;
	Set CHY;
};// end class Location
#endif