///////////////////////////////////////////////////////////////////////
// Class MyCircle Implementation
// FileName:	MyCircle.cpp
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition of MyCircle class constructors and methods
// Description - This file defines functions to create and draw a circle
///////////////////////////////////////////////////////////////////////
#include "MyCircle.h"

using std::cout;
using std::cin;
using std::endl;


///////////////////////////////////////////////////////////////////////////////
// MyCircle default constructor
///////////////////////////////////////////////////////////////////////////////
MyCircle::MyCircle()
// initialize default circle radius
: circleRadius(WINDOW_MAXX/8)
{}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::Draw
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::Draw()
{
	// set up attributes of circle using FilledShapes
	fs.SetPenColor(borderColor);
	fs.SetBrushColor(fillColor);

	// draw circle with set attributes
	// when drawing, take into account the border width by subtracting the border
	// width appropriately from the radius. that way, the given radius includes the
	// width of the border
	fs.FilledCircle(position, circleRadius - 2 * borderWidth);

	return true;
}// end function MyCircle::Draw()

///////////////////////////////////////////////////////////////////////////////
// MyRect::SetRadius()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetRadius(unsigned int radius)
{
	// need to account for a min radius depending upon the border width
	if ((radius <= 2 * borderWidth) ) return false;

	// check to make sure the new radius is valid based on current position
	// and window height and width. The validity is checked in both directions from
	// the center
	if (
		(position.x + radius<GetWindowWidth()) && 
		(position.x - radius<GetWindowWidth()) && 
		(position.y + radius<GetWindowHeight()) &&
		(position.y - radius < GetWindowHeight())
		)
	{
		circleRadius = radius;
		return true;
	}
	else
	{
		return false;
	}
}// end function MyCircle::SetRadius


///////////////////////////////////////////////////////////////////////////////
// MyCircle::SetPosition()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetPosition(POINT & p)
{
	// make sure new position is valid based on current radius and window size
	// the position has to be checked in both directions by adding radius and subtracting
	// radius
	if (
		(p.x+ circleRadius + borderWidth  < GetWindowWidth()) &&
		(((p.x - circleRadius) + borderWidth) < GetWindowWidth()) &&
		(p.y+circleRadius + borderWidth  < GetWindowHeight()) &&
		(((p.y - circleRadius) + borderWidth < GetWindowHeight()))
		)
	{
		position.x = p.x;
		position.y = p.y;
		return true;
	}
	else
	{
		return false;
	}
} // end function MyCircle::SetPosition()


///////////////////////////////////////////////////////////////////////////////
// MyRect::GetRadius()
///////////////////////////////////////////////////////////////////////////////
unsigned int MyCircle::GetRadius()
{
	return circleRadius;
}// end function MyCircle::GetRadius()