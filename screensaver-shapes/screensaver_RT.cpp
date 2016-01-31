///////////////////////////////////////////////////////////////////////
// FileName:	screensaver_RT.cpp
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Main driver function and random attributes generator function
// Description: Simple screensaver which draw circles, triangles and squares
// Reference:   Screensaver.cpp authored by Joe Waclawski
///////////////////////////////////////////////////////////////////////
#include "MyRect.h" // Rectangle object
#include "MyTriangle.h" // Triangle Object
#include "MyCircle.h" // Circle object
#include <stdlib.h> // rand and srand
#include <time.h> // time funciton
#include <windows.h>  // POINT object
#include <map> // map object
#include <vector> // vector object

// how many times will the program cycle
#define PROGRAM_RUN 20

// small delay between drawing rectangles during each run
#define DRAW_DELAY 100

// small delay between each iteration of drawing rectangles
#define ITERATION_DELAY 250

// total types of shapes
#define NUM_SHAPES 3
// function prototypes

// enumeration for shape types
enum SHAPES{RECTANGLE,TRIANGLE,CIRCLE};
Shape* RandomAttributes(SHAPES);


void main()
{

	// seed the random number generator
	srand((unsigned int)time(0));

	// allow the user time to move the console window away
	// from the FilledShapes window are
	cout << "Move this window to the lower right of the screen, and press ENTER to continue:\n";
	cin.get();


	// Create the map for storing shape pointers
	map<SHAPES, vector<Shape*>> shapeMap;

	// Create the vectors for each shape of size equal to number of shapes to be displayed
	vector<Shape*> rectVector(PROGRAM_RUN);
	vector<Shape*> triVector(PROGRAM_RUN);
	vector<Shape*> circVector(PROGRAM_RUN);

	// Pointers for different types
	MyRect* rect;
	MyTriangle* triangle;
	MyCircle* circle;

	// Initialize the map
	shapeMap.insert(pair<SHAPES, vector<Shape*>>(RECTANGLE, rectVector));
	shapeMap.insert(pair<SHAPES, vector<Shape*>>(TRIANGLE, triVector));
	shapeMap.insert(pair<SHAPES, vector<Shape*>>(CIRCLE, circVector));

	// Iterator for the map
	map<SHAPES, vector<Shape*>>::iterator mapIter;

	// Initialize the shape vectors
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		SHAPES currShape = (SHAPES)i; // get current shape from enum
		mapIter=shapeMap.find(currShape);
		for (int j = 0; j < PROGRAM_RUN; j++) // add 20 shapes for each type
		{
			switch (currShape)
			{
			case RECTANGLE: // add rectangles to map vector
				rect = dynamic_cast<MyRect*>(RandomAttributes(currShape));
				if (mapIter != shapeMap.end())
				{
					mapIter->second.push_back(rect);
				}
				break;
			case TRIANGLE: // add triangles to map's triangle vector
				triangle = dynamic_cast<MyTriangle*>(RandomAttributes(currShape));
				if (mapIter != shapeMap.end())
				{
					mapIter->second.push_back(triangle);
				}
				break;
			case CIRCLE: // add circles to map's circle vector
				circle = dynamic_cast<MyCircle*>(RandomAttributes(currShape));
				if (mapIter != shapeMap.end())
				{
					mapIter->second.push_back(circle);
				}
				break;
			}// end switch
		} // end j loop
	} // end i loop

	// Loop through the map and draw shapes
	for (int i = 0; i < PROGRAM_RUN; i++)
	{
		mapIter = shapeMap.find(RECTANGLE); // find a rectangle
		if (mapIter != shapeMap.end())
		{
			if (!mapIter->second.empty())
			{
				// Draw the rectangle and remove it from the map
				MyRect* shape = dynamic_cast<MyRect*> (mapIter->second.back()); 
				shape->ClearScreen();
				shape->Draw();
				delete mapIter->second.back();
				mapIter->second.pop_back();
			}
		}

		mapIter = shapeMap.find(TRIANGLE); // find a triangle
		if (mapIter != shapeMap.end())
		{
			if (!mapIter->second.empty())
			{
				// Draw the triangle and remove it from the map
				MyTriangle* shape = dynamic_cast<MyTriangle*> (mapIter->second.back());
				shape->Draw();
				delete mapIter->second.back();
				mapIter->second.pop_back();
			}
		}

		mapIter = shapeMap.find(CIRCLE); // find a circle
		if (mapIter != shapeMap.end())
		{
			if (!mapIter->second.empty())
			{
				// Draw the circle and remove it from the map
				MyCircle* shape = dynamic_cast<MyCircle*> (mapIter->second.back());
				shape->Draw();
				delete mapIter->second.back();
				mapIter->second.pop_back();
			}
		}
		// Delays between drawings
		if (DRAW_DELAY > 0)
			Sleep(DRAW_DELAY);
		if (ITERATION_DELAY > 0)
			Sleep(ITERATION_DELAY);
	}// end loop

} // end main

/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomly choose parameters for a shape 
//				depending on the type of shape and return a shape pointer
// 
// Inputs: SHAPES enumeration value indicating type of shape
// Outputs: None
// Returns: Shape pointer
/////////////////////////////////////////////////////////////////////

Shape* RandomAttributes(SHAPES shape)
{
	// Set up initial values which will be used for all shapes
	POINT p;
	p.x = 50;
	p.y = 50;

	SHAPE_COLOR firstColor = RED;
	SHAPE_COLOR lastColor = PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;
	unsigned int width;
	unsigned int radius;
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);
		
	

	if (shape == RECTANGLE) // Shape is rectangle, set up length and width attributes
	{
		MyRect* rect = new MyRect;

		// Initialize rectangle
		rect->SetPosition(p);
		rect->SetLength(rect->GetWindowHeight() / 10);
		rect->SetWidth(rect->GetWindowWidth() / 10);
		rect->SetBorderColor((SHAPE_COLOR)myPen);
		rect->SetFillColor((SHAPE_COLOR)myBrush);
		// length
		do {
			length = 1 + rand() % rect->GetWindowHeight();
		} while (!rect->SetLength(length));

		// width
		do {
			width = 1 + rand() % rect->GetWindowWidth();
		} while (!rect->SetWidth(width));

		// position
		do {
			p.x = 1 + rand() % rect->GetWindowWidth();
			p.y = 1 + rand() % rect->GetWindowHeight();
		} while (!rect->SetPosition(p));

		return rect; // Return the pointer to the rectangle object
	}
	if (shape == TRIANGLE)
	{
	
		MyTriangle* triangle = new MyTriangle;
		// Initialize triangle
		triangle->SetPosition(p);
		triangle->SetLength(triangle->GetWindowHeight() / 10);
		triangle->SetBorderColor((SHAPE_COLOR)myPen);
		triangle->SetFillColor((SHAPE_COLOR)myBrush);
		// length
		do {
			length = 1 + rand() % triangle->GetWindowHeight();
		} while (!triangle->SetLength(length));

		// position
		do {
			p.x = 1 + rand() % triangle->GetWindowWidth();
			p.y = 1 + rand() % triangle->GetWindowHeight();
		} while (!triangle->SetPosition(p));
		return triangle; // return pointer to triangle object
	}
	if (shape == CIRCLE)
	{
		MyCircle* circle = new MyCircle;
		// Initialize circle
		circle->SetPosition(p);
		circle->SetRadius(circle->GetWindowHeight() / 10);
		circle->SetBorderColor((SHAPE_COLOR)myPen);
		circle->SetFillColor((SHAPE_COLOR)myBrush);

		// radius
		do {
			radius = (rand() % 200) + 2; // select a random value for radius within 2 to 200 so that it is displayed properly
		} while (!circle->SetRadius(radius));


		// position
		do {
			p.x = 1 + rand() % circle->GetWindowWidth();
			p.y = 1 + rand() % circle->GetWindowHeight();
		} while (!circle->SetPosition(p));
		return circle; // return pointer to circle object
	}
	return NULL; // return NULL if shape not found
} // end function RandomAttributes
