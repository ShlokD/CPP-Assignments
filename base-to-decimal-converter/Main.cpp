//////////////////////////////////////////////////////////////////////////
// FileName:    Main.cpp
// Description: Driver program for converting numbers
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	main() function which is the entry point of the program
//////////////////////////////////////////////////////////////////////////

#include "Convert.h" //Uses Convert class
#include<iostream>
using namespace std;

// Starting point of program
int main(int argc, char* argv[])
{
	int num = 0; // Initializing Values
	int base = 0;
	cout << "Enter Number: ";
	cin >> num;
	cout << "Enter Base: ";
	cin >> base;
	Convert c(num, base); // Create object with values entered by user
	c.doConversion(); // Convert to decimal and print result
	return 0;
} // end main

