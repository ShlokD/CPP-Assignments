//////////////////////////////////////////////////////////////////////////
// FileName:	Convert.cpp
// Description: Implementation of Convert class methods
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition for methods of Convert class
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Convert.h" // include definition of convert
using namespace std;

// Constructor for initializing the values of number and base
Convert::Convert(int n, int b)
{
	number = n;
	base = b;
}// end constructor

// Function to convert number to decimal
void Convert::doConversion()
{
	int decimal = 0; // the decimal number to be converted
	int exp = 1; // multiplication factor which is multiplied with base

	while (number >= 1) //Loop till all digits are retrieved
	{
		int digit = number % 10;//get rightmost digit
		if (digit >= base) // Invalid number format
		{
			decimal = -1;
			break; // End the loop
		}
		else
		{
			decimal = decimal + (digit * exp); // Add decimal form of digit to final number
			exp *= base; // Advance the multiplication factor
			number = number / 10; // Remove the rightmost digit
		}
	}
	display(decimal);// Return the correct decimal form 
}// end function doConversion

// Helper function to display the decimal value
void Convert::display(int value)
{
	if (value == -1) // Check if error in format
	{
		cout << "Error! Invalid Number Format"<<endl;
	}
	else
	{
		cout << "Decimal Value: " << value<<endl;
	}
} // end function display