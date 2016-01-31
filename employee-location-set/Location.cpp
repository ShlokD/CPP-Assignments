//////////////////////////////////////////////////////////////////////////
// FileName:	Location.cpp
// Description: Definition of methods to implement Set class
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition of Location class constructors and methods
//////////////////////////////////////////////////////////////////////////
#include "Location.h"
#include <vector>
using namespace std;

// Constructor to intialize all sets of the class
Location::Location()
{

	for (int i = 0; i <= 20; ++i)
	{
		if (i >= 0 && i <= 5) // New York
		{
			NYX.setTrue(i);
			NYY.setTrue(i);
		}
		if (i >= 6 && i <= 10) // San Francisco
		{
			SFX.setTrue(i);
			SFY.setTrue(i);
		}
		if (i >= 11 && i <= 15) // Los Angeles
		{
			LAX.setTrue(i);
			LAY.setTrue(i);
		}
		if (i >= 16 && i <= 20) // Chicago
		{
			CHX.setTrue(i);
			CHY.setTrue(i);
		}
	}

}// end constructor

// Function to get the location from a point
Location::LOCATION Location::getLocation(Point &p)
{
	// Out-of-range points
	if (p.getX() > 20 || p.getY() > 20)
	{
		return NOT_FOUND;
	}

	// Point is in New York
	if (NYX.isMember(p.getX()) && NYY.isMember(p.getY()))
	{
		return NEWYORK;
	}
	// Point is in San Francisco
	else if (SFX.isMember(p.getX()) && SFY.isMember(p.getY()))
	{
		return SANFRANCISCO;
	}
	// Point is in Los Angeles
	else if (LAX.isMember(p.getX()) && LAY.isMember(p.getY()))
	{
		return LOSANGELES;
	}
	// Point is in Chicago
	else if (CHX.isMember(p.getX()) && CHY.isMember(p.getY()))
	{
		return CHICAGO;
	}
	// Point not found
	else
	{
		return NOT_FOUND;
	}
}// end functiong getLocation