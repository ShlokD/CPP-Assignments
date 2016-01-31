///////////////////////////////////////////////////////////////////////
// Class MyCircle Definition
// FileName:	MyCircle.h
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Declaration of MyCircle class constructors and methods
// Description - This file declares a class to draw a circle
///////////////////////////////////////////////////////////////////////
#ifndef __MY_CIRCLE__
#define __MY_CIRCLE__

// include appropriate prototypes
#include "FilledShapes.h"
#include "Shape.h"
#include <windows.h>

class MyCircle: public Shape {

	// Public Interace
public:


	///////////////////////////////////////////////////////////////////////////////
	// Function: Default Constructor
	// Purpose: Construct a circle
	//
	// Inputs: None
	// Outputs: None
	// 
	// Returns: None
	///////////////////////////////////////////////////////////////////////////////
	MyCircle();

	///////////////////////////////////////////////////////////////////////////////
	// Function: Draw
	// Purpose: Draw the circle with the current attributes
	//
	// Inputs: None
	// Outputs: None
	// 
	// Returns: true if successful, false otherwise
	///////////////////////////////////////////////////////////////////////////////
	virtual bool Draw();


	///////////////////////////////////////////////////////////////////////////////
	// Function: SetRadius
	// Purpose: Set the radius of the rectangle 
	//
	// Inputs: int radius - desired radius of rectangle
	// Outputs: None
	// 
	// Returns: true if successful, false otherwise
	///////////////////////////////////////////////////////////////////////////////
	bool SetRadius(unsigned int radius);

	///////////////////////////////////////////////////////////////////////////////
	// Function: GetRadius
	// Purpose: Get the radius of the circle
	//
	// Inputs: None
	// Outputs: None
	// 
	// Returns: current radius of the circle
	///////////////////////////////////////////////////////////////////////////////
	unsigned int GetRadius();



	///////////////////////////////////////////////////////////////////////////////
	// Function: SetPosition
	// Purpose: Set the position of the circle. This specifies an x,y coordinate
	//          which is the center of the circle
	//
	// Inputs: POINT point - x,y coordinates 
	// Outputs: None
	// 
	// Returns: true if successful, false otherwise
	///////////////////////////////////////////////////////////////////////////////
	virtual bool SetPosition(POINT &point);

	// Private Stuff
private:
	unsigned int circleRadius; // radius of the circle

}; // end class MyRect declaration

#endif __MY_CIRCLE__
