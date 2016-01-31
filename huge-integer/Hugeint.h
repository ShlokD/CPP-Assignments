// Exercise 11.9 Solution: Hugeint.h
// HugeInt class declaration
///////////////////////////////////////////////////////////////////////
// Class HugeInt Declaration
// FileName:	Hugeint.h
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Declaration of HugeInt class and methods with friend functions
// Description - This file defines a class to store numbers larger than 32 bits
// Reference:		Exercise 11.9, C++ How to Program
///////////////////////////////////////////////////////////////////////
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
   friend ostream &operator<<( ostream &, const HugeInt & );
public:
   static const int digits = 30; // maximum digits in a HugeInt

   HugeInt( long = 0); // conversion/default constructor
   HugeInt( const string & ); // conversion constructor
   // addition operator; HugeInt + HugeInt
   HugeInt operator+( const HugeInt & ) const;

   // addition operator; HugeInt + int
   HugeInt operator+( int ) const; 

   // addition operator; 
   // HugeInt + string that represents large integer value
   HugeInt operator+( const string & ) const;

   // subtraction operator; HugeInt - HugeInt
   HugeInt operator-(const HugeInt &) const;

   // subtraction operator; HugeInt - int
   HugeInt operator-(int) const;

   // subtraction operator; 
   // HugeInt - string that represents large integer value
   HugeInt operator-(const string &) const;

   // multiplication operator; HugeInt * HugeInt
   HugeInt operator*(const HugeInt &) const;

   // multiplication operator; HugeInt * int
   HugeInt operator*(int) const;

   // multiplication operator; 
   // HugeInt * string that represents large integer value
   HugeInt operator*(const string &) const;

   // division operator; HugeInt / HugeInt
   HugeInt operator/(const HugeInt &) const;

   // division operator; HugeInt / int
   HugeInt operator/(int) const;

   // division operator; 
   // HugeInt / string that represents large integer value
   HugeInt operator/(const string &) const;

   // equality operator; HugeInt - HugeInt
   bool operator==(const HugeInt &) const;

   // equality operator; HugeInt - int
   bool operator==(int) const;

   // equality operator; 
   // HugeInt - string that represents large integer value
   bool operator==(const string &) const;

   // inequality operator; HugeInt - HugeInt
   bool operator!=(const HugeInt &) const;

   // inequality operator; HugeInt - int
   bool operator!=(int) const;

   // inequality operator; 
   // HugeInt - string that represents large integer value
   bool operator!=(const string &) const;

   // greater than operator; HugeInt > HugeInt
   bool operator>(const HugeInt &) const;

   // greater than operator; HugeInt > int
   bool operator>(int) const;

   // greater than operator; 
   // HugeInt > string that represents large integer value
   bool operator>(const string &) const;

   // greater than or equal to operator; HugeInt >= HugeInt
   bool operator>=(const HugeInt &) const;

   // greater than or equal to operator; HugeInt >= int
   bool operator>=(int) const;

   // greater than or equal to operator; 
   // HugeInt >= string that represents large integer value
   bool operator>=(const string &) const;

   // less than operator; HugeInt < HugeInt
   bool operator<(const HugeInt &) const;

   // less than operator; HugeInt < int
   bool operator<(int) const;

   // less than operator; 
   // HugeInt < string that represents large integer value
   bool operator<(const string &) const;

   // less than or equal to operator; HugeInt <= HugeInt
   bool operator<=(const HugeInt &) const;

   // less than or equal to operator; HugeInt <- int
   bool operator<=(int) const;

   // less than or equal to operator; 
   // HugeInt <= string that represents large integer value
   bool operator<=(const string &) const;


  
private:
   short integer[ digits ]; // array to represent digits
   char sign; // sign whether positive or negative
   int getNumOfDigits() const; // function to get number of digits of the number
   

}; // end class HugeInt

#endif


/**************************************************************************
 * (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
