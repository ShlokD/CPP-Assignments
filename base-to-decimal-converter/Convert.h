//////////////////////////////////////////////////////////////////////////
// FileName:	Convert.h
// Description: Definition of Convert class which converts a number
//				in a specific base to decimal
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Convert class with public constructor and conversion methods
//////////////////////////////////////////////////////////////////////////


// Convert class definition
class Convert
{

public:
	Convert(int n, int b); // Constructor
	void doConversion(); // Convert number to decimal

private:
	void display(int val); // Helper function to display value;
	int number; // Number to be converted
	int base;// Base in which number is entered
}; // end class Convert