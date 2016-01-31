//////////////////////////////////////////////////////////////////////////
// FileName:	WordFont.cpp
// Description: Definition of methods and constructors to print string with special characters
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition of public and private methods of WordFont class
//////////////////////////////////////////////////////////////////////////
#include "WordFont.h"
#include <iostream>
using namespace std;

// Constructor
WordFont::WordFont(vector<char> input, int pSize, char pix, unsigned int len, bool b)
{
	inputString = input;
	pixelSize = pSize;
	pixel = pix;
	length = len;
	bold = b;
	int screenSize = (pixelSize+1)*length; // Screen size is the display area which is
											//size of pixels multiplied by string length plus one column for spacing between characters
	displayString = vector<vector<char>>(pixelSize, vector<char>(screenSize)); // Initializing 2D vector with number of rows equal to size of pixels and number of columns
																			  // equal to the screen size
} // end constructor


// Function to convert user-inputted string to proper display format
// and then display the string
void WordFont::displayPixellatedString()
{
	// Iterate through the user-inputted string
	for (unsigned int i = 0; i < length; i++)
	{
		char cur = inputString.at(i);
		vector<vector<char>> pixelChar; // Temporary vector to store the representation of each character
		switch (cur) // Call appropriate manipulation function for each character
		{
		case 'a': pixelChar = getPixelA(); break;
		case 'e': pixelChar = getPixelE(); break;
		case 'i': pixelChar = getPixelI(); break;
		case 'o': pixelChar = getPixelO(); break;
		case 'u': pixelChar = getPixelU(); break;
		case 'b': pixelChar = getPixelB(); break;
		case 'c': pixelChar = getPixelC(); break;
		case 'f': pixelChar = getPixelF(); break;
		case 'h': pixelChar = getPixelH(); break;
		case 'j': pixelChar = getPixelJ(); break;
		case 'l': pixelChar = getPixelL(); break;
		case 'n': pixelChar = getPixelN(); break;
		case 't': pixelChar = getPixelT(); break;
		case 'x': pixelChar = getPixelX(); break;
		case 'y': pixelChar = getPixelY(); break;
		case 'z': pixelChar = getPixelZ(); break;
		}//end switch
		appendToDisplayString(pixelChar,i); // After getting the 2D vector representing a character, add it to the final string
	}
	display(displayString); // Display the final string
} // end function displayPixellatedString

// Function to Display the 2D vector
void WordFont::display(vector<vector<char>> vec2D)
{
	int rowLength = vec2D.size(); // get length of the row
	for (int i = 0; i < rowLength; ++i)
	{
		vector<char> currVec = vec2D.at(i);
		for (unsigned int j = 0; j < currVec.size(); ++j) // For each vector in the row, display the vector contents
		{
			cout << currVec.at(j);
		}// end j loop
		cout << endl;
	}//end i loop
}// end function display

// Function to add the pixellated character to the final string
void WordFont::appendToDisplayString(vector<vector<char>> symbol,int marker)
{
	int startPoint = marker + (pixelSize*marker); // Marker is the point at which the character is to be added
	// The character is added from the starting point to the starting point + size of the pixel
	for (int i = 0; i < pixelSize; ++i)
	{
		for (int j = 0; j < pixelSize; ++j)
		{
			displayString.at(i).at(j+startPoint) = symbol.at(i).at(j); // copy the symbol into appropriate location in final string
		}// end j loop
	}//end i loop
}

// Function to create pixellated version of 'a'
vector<vector<char>> WordFont::getPixelA() 
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D Vector Representation of A
	int mid = (int)pixelSize / 2; // midpoint of the representation

	// First loop to fill in the first row and middle row
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		font.at(mid).at(i) = pixel;
		if (bold) // If bold option is selected, fill adjoining columns to the end columns
		{
			font.at(1).at(i) = pixel;
			font.at(mid+1).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill in remaining pixels at start and end
	for (int i = 1; i < pixelSize; ++i)
	{
		if (i == mid) continue;
		font.at(i).at(0) = pixel;
		font.at(i).at(pixelSize - 1) = pixel;
		if (bold) // for bold option, fill adjoining pixels also
		{
			font.at(i).at(1) = pixel;
			font.at(i).at(pixelSize - 2) = pixel;
		}
	} // end second loop
	return font; // return the representation
}// end function getPixelA

// Function to create pixellated version of 'e'
vector<vector<char>> WordFont::getPixelE()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D vector representation of E
	int mid = (int)pixelSize / 2;

	// First loop to Fill up pixels for top,middle and bottom rows
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		font.at(mid).at(i) = pixel;
		font.at(pixelSize - 1).at(i) = pixel;
		if (bold) // fill adjoining lines
		{
			font.at(1).at(i) = pixel;
			font.at(mid - 1).at(i) = pixel;
			font.at(pixelSize - 2).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill one pixel each in first column
	for (int i = 1; i < pixelSize-1; ++i)
	{
		if (i == mid) continue;
		font.at(i).at(0) = pixel;
		if (bold) font.at(i).at(1) = pixel; // fill adjoining pixels
	}// end second loop
	return font; // return representation
}// end function getPixelE

// Function to create pixellated version of 'i'
vector<vector<char>> WordFont::getPixelI()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); //Representative vector
	int mid = (int)pixelSize / 2;

	// First loop to fill top and bottom rows
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		font.at(pixelSize - 1).at(i) = pixel;
		if (bold) // fill adjoining rows
		{
			font.at(1).at(i) = pixel;
			font.at(pixelSize - 2).at(i) = pixel;
		}
	} // end first loop

	// Second loop to fill middle column
	for (int i = 1; i < pixelSize - 1; ++i)
	{
		font.at(i).at(mid) = pixel;
		if (bold) // fill adjoining column
		{
			font.at(i).at(mid+1) = pixel;
		}
	}// end second loop
	return font;//return representation
}// end function getPixelI

// Function to create pixellated version of 'o'
vector<vector<char>> WordFont::getPixelO()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D vector representation of O

	// First loop to fill top and bottom rows
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		font.at(pixelSize - 1).at(i) = pixel;
		if (bold) // fill adjoining rows
		{
			font.at(1).at(i) = pixel;
			font.at(pixelSize-2).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill first and last columns
	for (int i = 1; i < pixelSize - 1; ++i)
	{

		font.at(i).at(0) = pixel;
		font.at(i).at(pixelSize - 1) = pixel;
		if (bold) // fill adjoining columns
		{
			font.at(i).at(1) = pixel;
			font.at(i).at(pixelSize - 2) = pixel;
		}
	}// end second loop
	return font;
}// end function getPixelO

// Function to create pixellated version of 'u'
vector<vector<char>> WordFont::getPixelU()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D vector representation of U
	
	// First loop to fill the last row
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(pixelSize - 1).at(i) = pixel;
		if (bold) // fill adjoining row
		{
			font.at(pixelSize - 2).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill first and last pixel in all columns
	for (int i = 0; i < pixelSize - 1; ++i)
	{
		
		font.at(i).at(0) = pixel;
		font.at(i).at(pixelSize - 1) = pixel;
		if (bold) // fill adjoining pixels
		{
			font.at(i).at(1) = pixel;
			font.at(i).at(pixelSize - 2) = pixel;
		}
	}// end second loop
	return font;
}// end function getPixelU

// Function to create pixellated version of 'b'
vector<vector<char>> WordFont::getPixelB()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D vector representation of B
	int mid = (int)pixelSize / 2;

	// First loop to fill first, middle and bottom rows
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		font.at(mid).at(i) = pixel;
		font.at(pixelSize - 1).at(i) = pixel;
		if (bold) // fill adjoining pixels also
		{
			font.at(1).at(i) = pixel;
			font.at(mid-1).at(i) = pixel;
			font.at(pixelSize - 2).at(i) = pixel;
		}
	}//end first loop

	// Second loop to fill first and last columns
	for (int i = 1; i < pixelSize - 1; ++i)
	{
		if (i == mid) continue;
		font.at(i).at(0) = pixel;
		font.at(i).at(pixelSize - 1) = pixel;
		if (bold)
		{
			font.at(i).at(1) = pixel;
			font.at(i).at(pixelSize - 2) = pixel;
		}

	}// end second loop
	return font;
} // end function getPixelB

// Function to create pixellated version of 'c'
vector<vector<char>> WordFont::getPixelC()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D Vector representation of C

	// First loop to fill first and last row
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		font.at(pixelSize - 1).at(i) = pixel;
		if (bold) // fill adjoining rows
		{
			font.at(1).at(i) = pixel;
			font.at(pixelSize - 2).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill first column
	for (int i = 1; i < pixelSize - 1; ++i)
	{

		font.at(i).at(0) = pixel;
		if (bold) // fill adjoining column also
		{
			font.at(i).at(1) = pixel;
		}
	}// end second loop
	return font;
}// end function getPixelC

// Function to create pixellated version of 'f'
vector<vector<char>> WordFont::getPixelF()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D Vector Representation of F
	int mid = (int)pixelSize / 2;

	//First loop to fill first and middle rows
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		font.at(mid).at(i) = pixel;
		if (bold) // fill adjoining rows also
		{
			font.at(1).at(i) = pixel;
			font.at(mid-1).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill first column
	for (int i = 1; i < pixelSize; ++i)
	{
		if (i == mid) continue;
		font.at(i).at(0) = pixel;
		if (bold) // fill adjoining columns
		{
			font.at(i).at(1) = pixel;
		}

	} // end second loop
	return font;
}// end function getPixelF

// Function to create pixellated version of 'h'
vector<vector<char>> WordFont::getPixelH()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D Vector Representation of H
	int mid = (int)pixelSize / 2;

	// First loop to fill middle row
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(mid).at(i) = pixel;
		if (bold) // fill adjoining rows
		{
			font.at(mid-1).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill first and last column
	for (int i = 0; i < pixelSize; ++i)
	{
		if (i == mid) continue;
		font.at(i).at(0) = pixel;
		font.at(i).at(pixelSize - 1) = pixel;
		if (bold) // fill adjoining columns
		{
			font.at(i).at(1) = pixel;
			font.at(i).at(pixelSize - 2) = pixel;
		}
	}
	return font;
} // end function getPixelH

// Function to create pixellated version of 'j'
vector<vector<char>> WordFont::getPixelJ()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D Vector Representation of J
	int mid = (int)pixelSize / 2;

	// First loop to fill top row
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		if (bold) // fill adjoining row
		{
			font.at(1).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill only half of bottom row
	for (int i = 0; i < pixelSize/2; ++i)
	{
		font.at(pixelSize-1).at(i) = pixel;
		if (bold) // fill adjoining half-row
		{
			font.at(pixelSize-2).at(i) = pixel;
		}
	}// end second loop

	// Third loop to fill middle column
	for (int i = 1; i < pixelSize - 1; ++i)
	{
		font.at(i).at(mid) = pixel;
		if (bold) // fill adjoining column
		{
			font.at(i).at(mid-1) = pixel;
		}
	}// end third loop
	return font;
}// end function getPixelJ

// Function to create pixellated version of 'l'
vector<vector<char>> WordFont::getPixelL()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); // 2D vector representation of L
	
	// Loop to fill up first column and last row
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(i).at(0) = pixel;
		font.at(pixelSize - 1).at(i) = pixel;
		if (bold) // fill adjoining column and row
		{
			font.at(i).at(1) = pixel;
			font.at(pixelSize - 2).at(i) = pixel;
		}
	}	
	return font;
} // end function getPixelL

//// Function to create pixellated version of 'n'
vector<vector<char>> WordFont::getPixelN()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); //2D Vector representation of N

	// First loop to fill first and last columns
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(i).at(0) = pixel;
		font.at(i).at(pixelSize-1)= pixel;
		
		if (bold) // Fill adjoining columns
		{
			font.at(i).at(1) = pixel;
		    font.at(i).at(pixelSize-2)= pixel;
		}
	}// end first loop

	// Second loop to fill diagonal
	for (int i = 1; i < pixelSize - 1; ++i)
	{
		font.at(i).at(i) = pixel;
		if (bold) // fill adjoining diagonal
		{
			font.at(i).at(i+1) = pixel;
		}
	}//end second loop
	return font;
}// end function getPixelN

// Function to create pixellated version of 't'
vector<vector<char>> WordFont::getPixelT()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize));//2D Vector representation of T
	int mid = (int)pixelSize / 2;

	// First loop to fill first row
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		if (bold) // fill adjoining row
		{
			font.at(1).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill middle column
	for (int i = 1; i < pixelSize; ++i)
	{
		font.at(i).at(mid) = pixel;
		if (bold)// Fill adjoining column
		{
			font.at(i).at(mid-1) = pixel;
		}
	}// end second loop
	return font;
}// end function getPixelT

// Function to create pixellated version of 'x'
vector<vector<char>> WordFont::getPixelX() 
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); //2D Vector representation of X
	// First loop to fill upper and lower diagonals
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(i).at(i) = pixel;
		font.at(i).at(pixelSize - i - 1) = pixel;
	}// end first loop

	if (bold) // Fill adjoining diagonals
	{
		// Second loop for adjoining diagonals
		for (int i = 1; i < pixelSize - 1; ++i)
		{
			font.at(i).at(i + 1) = pixel;
			font.at(i).at(pixelSize - i - 2) = pixel;
		}// end second loop
	}
	return font;
}// end function getPixelX

// Function to create pixellated version of 'y'
vector<vector<char>> WordFont::getPixelY()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize)); //2D Vector representation of Y
	int mid = (int)pixelSize / 2;

	// First loop to half-fill middle column 
	for (int i = mid; i < pixelSize; ++i)
	{
		font.at(i).at(mid) = pixel;
		if (bold) // fill adjoining column
		{
			font.at(i).at(mid-1) = pixel;
		}
	}// end first loop

	//Second loop to half-fill upper and lower diagonal
	for (int i = 0; i < mid; ++i)
	{
		font.at(i).at(i) = pixel;
		font.at(i).at(pixelSize - i - 1) = pixel;
		if (bold) // Fill adjoining diagonals
		{

			font.at(i).at(i + 1) = pixel;
			font.at(i).at(pixelSize - i - 2) = pixel;
		}
	}// end second loop
	
	return font;
}// end function getPixelY

// Function to create pixellated version of 'z'
vector<vector<char>> WordFont::getPixelZ()
{
	vector<vector<char>> font(pixelSize, vector<char>(pixelSize));//2D Vector representation of Z

	//First loop to fill top and bottom rows
	for (int i = 0; i < pixelSize; ++i)
	{
		font.at(0).at(i) = pixel;
		font.at(pixelSize - 1).at(i) = pixel;
		if (bold) // fill adjoining rows
		{
			font.at(1).at(i) = pixel;
			font.at(pixelSize - 2).at(i) = pixel;
		}
	}// end first loop

	// Second loop to fill diagonal
	for (int i = 1; i < pixelSize - 1; ++i)
	{
		font.at(i).at(pixelSize - i - 1) = pixel;
		if (bold) // fill adjoining diagonal
		{
			font.at(i).at(pixelSize - i - 2) = pixel;
		}
	}
	return font;
}// end function getPixelZ