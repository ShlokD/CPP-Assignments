//////////////////////////////////////////////////////////////////////////
// FileName:	Main.cpp
// Description: Driver Program with helper functions
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Use of WordFont class with helper functions for checking inputs
//////////////////////////////////////////////////////////////////////////

#include "WordFont.h" // WordFont object
#include <iostream>
#include <vector> 
#include <algorithm> // To manipulate vectors
#include <string> // To manipulate strings
using namespace std;

// Helper Function Declarations
void getCorrectString(vector<char>&);
bool checkString(char[],unsigned int);
int getPixelLength();
char getPixel();
bool getBold();

// Main Function
int main(int argc, char* argv[])
{
	vector<char> buffer;
	getCorrectString(buffer); // get the correct string with valid format in buffer from user
	int pixelSize = getPixelLength(); // get correct pixel size from user
	char pixel = getPixel(); // get pixel representation from user
	bool bold = getBold(); // get option for bold from user
	WordFont wf(buffer, pixelSize,pixel, buffer.size(),bold); // WordFont Object
	wf.displayPixellatedString(); // Display the string 
	return 0;
}// end function main

// Function to get string from user
void getCorrectString(vector<char>& buffer)
{
	char temp[100]; // temporary string 
	while (true) // loop till proper string is entered
	{
		cout << "Allowed Characters: a,e,i,o,u,b,c,f,h,j,l,n,t,x,y,z" << endl;
		cout << "Enter String( 8 letters or less): ";
		cin >> temp;
		unsigned int length = strlen(temp); // Get String Length
		if (checkString(temp, length)) // If string is of correct format
		{
			buffer = vector<char>(length); // the buffer is redefined to have only the length equal to that of the string
			for (unsigned int i = 0; i < length; ++i) // copy string to buffer
			{
				buffer.at(i) = temp[i];
			}
			break; // end the input loop
		}
		else // string is not proper, ask again
		{
			cout << "Invalid String Entered. Please Enter Again" << endl;
		}
	}// end while loop
	
}// end function getCorrectString

// Function to get String from user and check if it is in correct format
bool checkString(char temp[],unsigned int length) // For checking string, it is better to use array as it can be manipulated easily
{
	
	vector<char> allowed = { 'a', 'e', 'i', 'o', 'u', 'b', 'c', 'f', 'h','j', 'l', 'n', 't', 'x','y','z' }; // Allowed characters
	vector<char>::iterator it; // Iterator for the vector
	bool returnVal = true;
	if (length > 8) // Length is more than 8 letters, not allowed
	{
		returnVal = false;
	}

	for (unsigned int i = 0; i <length; ++i) // Check if each character of string belongs to list of allowed characters
	{
		it = find(allowed.begin(), allowed.end(), temp[i]); // function to check if character belongs to vector
		if (it == allowed.end()) // character not found, not allowed
		{
			returnVal = false;
		}
	}
	return returnVal; // return if string is correct or not
} // end function checkString

// Function to get the size of pixels for displaying character
int getPixelLength()
{
	int pixel = 0;
	while (true) // Loop till user inputs correct value
	{
		cout << "Enter pixel size between 8 and 12: ";
		cin >> pixel;
		
		if (pixel >= 8 && pixel <= 12) // Pixel is in proper size range
		{
			break;
		}
		else // pixel size is not in proper range
		{
			cout << "Invalid Value. Please enter again" << endl;
		}
	} // end while loop
	return pixel; // return the pixel size
}// end function getPixelLength

// Function to get the character representation of pixel in displayed string
char getPixel()
{
	char pixel = '?';
	cout << "Enter character for pixel: "; // get the character from user
	cin >> pixel;
	return pixel; // return pixel character
}// end function getPixel

// Function to get bold option settings
bool getBold()
{
	bool bold = false;
	int input = 0;
	while (true) // Ask user for bold option 
	{
		cout << "Bold? Enter 0 for No, 1 for Yes:";
		cin >> input;
		if (input == 0) { bold = false; break; }
		else if (input == 1) {
			bold = true; break;
		}
		else cout << "Invalid Choice.Try Again" << endl; // Incorrect value entered, ask user to enter again
	}//end while
	return bold; // return correct bold option
}// end function getBold
