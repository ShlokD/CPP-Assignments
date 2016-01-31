// Exercise 11.9 Solution: Hugeint.cpp
// HugeInt member-function and friend-function definitions.
///////////////////////////////////////////////////////////////////////
// Class HugeInt Implementation
// FileName:	Hugeint.cpp
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition of HugeInt class and methods with friend functions
// Description - This file implements a class to store numbers larger than 32 bits
// Reference:		Exercise 11.9, C++ How to Program
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cctype> // isdigit function prototype

#include "Hugeint.h" // HugeInt class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt( long value )
{
	if (value < 0) //if number is negative, set sign accordingly
	{
		sign ='-'; 
		value -= value * 2; // get magnitude of number
	}
	else
	{
		sign = '+'; // number is positive, set sign accordingly
	}
   // initialize array to zero
   for ( int i = 0; i < digits; ++i )
      integer[ i ] = 0;

   // place digits of argument into array
   for ( int j = digits - 1; value != 0 && j >= 0; --j )
   {
      integer[ j ] = value % 10;
      value /= 10;
   } // end for
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt( const string &number )
{
   // initialize array to zero
   for ( int i = 0; i < digits; ++i )
      integer[ i ] = 0;

   // place digits of argument into array
   int length = number.size();
   char signbit = number[0]; // if number is negative, first character will be a - sign
   int k = 0;
   if (signbit == '-') // set sign accordingly and shift marker forward
   {
	   sign = '-';
	   k = 1;
	   --length;
   }
   else // number is positive
   {
	   sign = '+';
   }

   for (int j = digits - length; j < digits; ++j, ++k)
      if ( isdigit( number[ k ] ) )
         integer[ j ] = number[ k ] - '0';

} // end HugeInt conversion constructor

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+( const HugeInt &op2 ) const
{
	// temporary numbers to store magnitude of two numbers
	HugeInt firstNum; 
	HugeInt secondNum;

	// copy magnitude
	for (int i = digits - 1; i >= 0; --i)
	{
		firstNum.integer[i] = integer[i];
		secondNum.integer[i] = op2.integer[i];
	}

   HugeInt temp; // temporary result

   if (sign == '-'&& op2.sign == '+')// -x+y = y-x
   {
	   temp = secondNum - firstNum;
	   return temp;
   }
   else if (sign == '+' && op2.sign == '-') // x+-y = x-y
   {
	   temp = firstNum - secondNum;
	   return temp;
   }
   else if (sign == '-' && op2.sign == '-') // -x+-y = -(x+y)
   {
	   temp.sign = '-';
   }
   int carry = 0;
   for ( int i = digits - 1; i >= 0; --i )
   {
      temp.integer[ i ] = firstNum.integer[ i ] + secondNum.integer[ i ] + carry;

      // determine whether to carry a 1
      if ( temp.integer[ i ] > 9 )
      {
         temp.integer[ i ] %= 10;  // reduce to 0-9
         carry = 1;
      } // end if
      else // no carry
         carry = 0;
   } // end for

   return temp; // return copy of temporary object
} // end function operator+

// addition operator; HugeInt + int
HugeInt HugeInt::operator+( int op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 );
} // end function operator+

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+( const string &op2 ) const
{
   // convert op2 to a HugeInt, then invoke
   // operator+ for two HugeInt objects
return *this + HugeInt(op2);
} // end function operator+


// subtraction operator; HugeInt - HugeInt
HugeInt HugeInt::operator-(const HugeInt &op2) const
{
	HugeInt temp;
	if (*this == op2) return temp; // if both numbers are equal, return zero
	
	// temporary numbers to store magnitude
	HugeInt firstNum;
	HugeInt secondNum;
	bool invert = false; // if first number < second number, set to true because answer will be negative

	// copy magnitude
	for (int i = digits - 1; i >= 0; --i)
	{
		firstNum.integer[i] = integer[i];
		secondNum.integer[i] = op2.integer[i];
	}


	if (sign == '-' && op2.sign == '+') // -x -y = -(x+y)
	{
		temp = firstNum + secondNum;
		temp.sign = '-';
		return temp;
	}
	else if (sign == '+' && op2.sign == '-') // x--y = x+y
	{
		temp = firstNum + secondNum;
		temp.sign = '+';
		return temp;
	}
	else if (sign == '-' && op2.sign == '-') // -x--y= -x+y = y-x
	{
		temp = secondNum - firstNum; // perform subtraction of two magnitudes
		if (firstNum < secondNum) // set sign
		{
			temp.sign = '+';
		}
		else
		{
			temp.sign = '-';
		}
		int numLength = firstNum.getNumOfDigits(); // strip away borrowed bits
		for (int i = digits - numLength; i >= 0; --i)
		{
			temp.integer[i] = 0;
		}
		return temp;
	}

	// if x<y, x-y<0
	if (firstNum < secondNum)
	{
		invert = true;
		temp.sign = '-';
	}


	int borrow = 0;

	for (int i = digits - 1; i >= 0; --i)
	{
		if (!invert) // x>y. so subtract first number - second number to get magnitude
		{
			if ((firstNum.integer[i] - borrow) < secondNum.integer[i]) // determine whether to borrow 1
			{
				temp.integer[i] = (firstNum.integer[i] + 10) - secondNum.integer[i] - borrow; // perform subtraction using borrow
				borrow = 1; // set borrow
			}
			else
			{
				temp.integer[i] = firstNum.integer[i] - secondNum.integer[i] - borrow; // perform subtraction
				borrow = 0; // set borrow
			}
		}
		else // x<y so subtract second number - first number to get magnitude
		{
			if ((secondNum.integer[i] - borrow) < firstNum.integer[i]) // determine whether to borrow 1
			{
				temp.integer[i] = (secondNum.integer[i] + 10) - firstNum.integer[i] - borrow; // perform subtraction using borrow
				borrow = 1; // set borrow
			}
			else
			{
				temp.integer[i] = secondNum.integer[i] - firstNum.integer[i] - borrow; // perform subtraction
				borrow = 0; // set borrow
			}
		}
	}

	return temp;
} // end function operator-

// subtraction operator; HugeInt - int
HugeInt HugeInt::operator-(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator- for two HugeInt objects
	HugeInt temp = *this - HugeInt(op2); // cast integer to HugeInt and subtract
	return temp;
} // end function operator -

// subtraction operator; 
// HugeInt - string that represents large integer value
HugeInt HugeInt::operator-(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator- for two HugeInt objects
	HugeInt temp = *this - HugeInt(op2); 
	return temp;
}// end function operator -

// multiplication operator,HugeInt * HugeInt
HugeInt HugeInt::operator*(const HugeInt &op2) const
{
	HugeInt temp; // temporary result

	// first perform multiplication digit by digit
	for (int i = digits - 1; i >= 0; --i)
	{
		for (int j = digits - 1; j >= 0; --j)
		{
			int ans = integer[i] * op2.integer[j];
			int h = digits - ((digits - i) + (digits - j)) + 1;
			temp.integer[h] += ans;
			
		}
	}
	// if integer>9, then it's last digit has to be kept at the position
	// while adding 1 to digits before its position with 1 digit being added
	// for each division of 10
	for (int i = digits - 1; i >= 0; --i)
	{
		if (temp.integer[i] > 9)
		{

			int x = temp.integer[i];
			int factor = 10;
			int marker = 1;
			while (x > 9)
			{
				int carryForward = x / factor;
				temp.integer[i - marker] += carryForward;
				marker++;
				x = x % 10;
			}
			temp.integer[i] = x;

		}
	}

	// If either number is negative, set sign accordingly
	if ((sign == '-' && op2.sign == '+') || (sign == '+' && op2.sign == '-'))
		temp.sign = '-';

	return temp;
	
}// end function operator *

// multiplication operator *; Huge Int * int
HugeInt HugeInt::operator*(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator* for two HugeInt objects
	HugeInt temp = *this * HugeInt(op2); // cast integer to HugeInt and multiply
	return temp;
}// end function operator *


// multiplication operator; 
// HugeInt * string that represents large integer value
HugeInt HugeInt::operator*(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator* for two HugeInt objects
	HugeInt temp = *this * HugeInt(op2);// cast string to integer and multiply
	return temp;
}//end function operator*

// division operator,HugeInt / HugeInt
HugeInt HugeInt::operator/(const HugeInt &op2) const
{
	HugeInt zero;// zero value
	//temporary magnitude values
	HugeInt firstNum;
	HugeInt secondNum;
	//temporary value
	HugeInt temp;
	vector<int> tempDigits(1); // vector to hold temporary digits for cleaner long division process
	int tempDigit = 0; // marker for temporary vector
	
	// copy magnitudes
	for (int i = digits - 1; i >= 0; --i)
	{
		firstNum.integer[i] = integer[i];
		secondNum.integer[i] = op2.integer[i];
	}
	if (secondNum == zero) return zero; // if divisor is zero, return zero

	int firstSize = getNumOfDigits();
	int secondSize = op2.getNumOfDigits();
	long divisor = 0;
	int mulFactor = 1;
	for (int i = digits - 1; i >=0; --i)
	{
		divisor += mulFactor*op2.integer[i];
		mulFactor *= 10;
	}// reconstruct the divisor

	int remainder = 0;
	long quot = 0;
	int dividend = 0;

	// run long division procedure
	for (int i = digits - firstSize; i < digits; i++)
	{
		int currentquot = 0;
		dividend = integer[i] + remainder * 10;
		int factor = 1;
		while (dividend <divisor) // if dividend < divisor, bring the next digit into dividend
		{
			    factor++; // count of how many digits brought in to insert zeroes
				dividend *= 10;
				i++;
				dividend += integer[i];
		}
		currentquot += (dividend / divisor); // get the current quotient
		if (factor > 1) // if more than one digits have been brought in, insert zeroes in digits vector
		{
			while (factor > 1)
			{
				tempDigits.push_back(0);
				--factor;
			}
		}
		tempDigits.push_back( currentquot); // add quotient to digits vector
		tempDigit++;// move marker to next digit
		remainder = dividend -currentquot*divisor; // get remainder
	}

	for (int i = 0; i <(int)tempDigits.size(); ++i) // copy temporary vector to HugeInt
	{
		int h = (digits - tempDigits.size()) + i;
		temp.integer[h] = tempDigits[i];
	}
	if ((sign == '-' && op2.sign == '+') || (sign == '+' && op2.sign == '-')) // if either of the numbers is negative, answer is negativeS
		temp.sign = '-';
	return temp;
	
}// end function operator /

// division operator; HugeInt / int
HugeInt HugeInt::operator/(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator/ for two HugeInt objects
	HugeInt temp = *this / HugeInt(op2); // cast int to HugeInt and divide
	return temp;
}//end function operator /

// division operator; 
// HugeInt / string that represents large integer value
HugeInt HugeInt::operator/(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator/ for two HugeInt objects
	HugeInt temp = *this / HugeInt(op2); 
	return temp;
}// end function operator /


// equality operator; HugeInt == HugeInt
bool HugeInt::operator==(const HugeInt &op2) const
{
	// get digits of both numbers
	int length1 = getNumOfDigits();
	int length2 = op2.getNumOfDigits();
	if (length1 != length2 || sign !=op2.sign) // if there is a sign mismatch or length of digits is not same, numbers are not equal
	{
		return false;
	}
	else
	{
		bool returnVal = true; // are values equal?
		for (int i = digits - 1; i >= 0; --i) // compare all digits for equality for both numbers
		{
			if (integer[i] != op2.integer[i])
			{
				returnVal = false; // values are not equal, so have to return false
				break;
			}
		}
		return returnVal;
	}
} // end function operator==

// equality operator;HugeInt==int
bool HugeInt::operator==(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator== for two HugeInt objects
	return (*this == HugeInt(op2));
} // end function operator==

// equality operator; HugeInt == string
// where string represents a large integer
bool HugeInt::operator==(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator== for two HugeInt objects
	return (*this == HugeInt(op2));
} // end function operator==

// inequality operator;HugeInt!=HugeInt
bool HugeInt::operator!=(const HugeInt &op2) const
{
	return !(*this == op2); // if numbers are not equal, they are inequal and vice versa
}// end function operator !=

// inequality operator;HugeInt!=int
bool HugeInt::operator!=(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator!= for two HugeInt objects
	return (*this != HugeInt(op2));
}// end function operator!=

// inequality operator;
// HugeInt!=string, where string represents a large integerS
bool HugeInt::operator!=(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator!= for two HugeInt objects
	return (*this != HugeInt(op2));
} // end function operator!=

// greater than operator;HugeInt>HugeInt
bool HugeInt::operator>(const HugeInt &op2) const
{
	bool invert = false; // inverted comparison i.e for two negative numbers
	if (*this == op2) return false; // if numbers are equal, one is not greater than the other
	if (sign == '+' && op2.sign == '-') return true; // x>0>y is always true
	if (sign == '-' && op2.sign == '+') return false;// x<0<y and x>y is always false
	if (sign == '-' && op2.sign == '-') invert = true; // have to compare negative values


	// get lengths of two numbers
	int length1 = getNumOfDigits();
	int length2 = op2.getNumOfDigits();
	// temporary values to store magnitude
	HugeInt firstNum;
	HugeInt secondNum;

	// copy magnitudes
	for (int i = digits - 1; i >= 0; --i)
	{
		firstNum.integer[i] = integer[i];
		secondNum.integer[i] = op2.integer[i];
	}

	
	if (length1 > length2)// if x has more digits than y, 
		if (!invert) // if x>0 and y>0, x>y
		{
			return true;
		}
		else // if x<0 and y<0, y>x
		{
			return false;
		}
	else if (length1 < length2)// if x has less digits than y
		if (!invert) // if x>0 and y?0, x<y
		{
			return false;
		}
		else // if x<0 and y<0, x>y
		{
			return true;
		}
	else
	{
		bool returnVal = true;
		
		bool currPlace = false;
		bool prevPlace = false;

		// cycle through the digits, comparing each one
		for (int i = digits - length1; i < digits; ++i)
		{
			if (integer[i]<op2.integer[i]) // if the digit of first number is less than digit of second number
			{
				if (prevPlace) // if previous digit is higher, then continue cycling
				{
					continue;
				}
				else // if previous digit is lower, the number is lower
				{
					returnVal = false;
				}
			}
			else if (integer[i] > op2.integer[i]) // if it is greater, then set the previousPlace checker to the currentPlace checker and the currentPlace checker to true
			{
				prevPlace = currPlace;
				currPlace = true;
				
			}
			else //if digits are equal, move to the next one
			{
				continue;
			}
		}
		if (!invert) // both numbers are positive, return normal result
			return returnVal;
		else // both are negative, return complement of result
			return !returnVal;
	}
} // end function operator>

// greater than operator;HugeInt > int
bool HugeInt::operator>(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator> for two HugeInt objects
	return (*this > HugeInt(op2));
}// end function operator >

// greater than operator;HugeInt > string
// where string represents a large integer
bool HugeInt::operator>(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator> for two HugeInt objects
	return (*this > HugeInt(op2));
}// end function operator >

// greater than or equal to operator; HugeInt >= HugeInt
bool HugeInt::operator>=(const HugeInt &op2) const
{
	// if number is greater than op2 or 
	// equal to op2, it is greater than or equal to op2
	return (*this > op2 || *this == op2);
}// end function operator >=

// greater than or equal to operator;HugeInt >= int
bool HugeInt::operator>=(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator>= for two HugeInt objects
	return (*this >= HugeInt(op2));
}// end function operator >=

// greater than or equal to operator;HugeInt >= string
// where string represents a large integer
bool HugeInt::operator>=(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator>= for two HugeInt objects
	return (*this >= HugeInt(op2));
}// end function operator >=

// less than operator; HugeInt < HugeInt
bool HugeInt::operator<(const HugeInt &op2) const
{
	// if number is not greater than nor equal to op2, then
	// it is less than op2
	return !(*this >= op2);
}// end function operator <

// less than operator;HugeInt < int
bool HugeInt::operator<(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator< for two HugeInt objects
	return (*this < HugeInt(op2));
}// end function operator <

// less than operator;HugeInt < string
// where string represents a large integer
bool HugeInt::operator<(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator< for two HugeInt objects
	return (*this < HugeInt(op2));
}// end function operator <

// less than or equal to operator HugeInt<=HugeInt
bool HugeInt::operator<=(const HugeInt &op2) const
{
	// if the number is not greater than op2, it is 
	// less than or equal to it
	return !(*this > op2);
}// end function <=

// less than or equal to operator;HugeInt <= int
bool HugeInt::operator<=(int op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator<= for two HugeInt objects
	return (*this <= HugeInt(op2));
}//end function operator<=

// less than or equal to operator;HugeInt <= string
// where string represents a large integer
bool HugeInt::operator<=(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke
	// operator<= for two HugeInt objects
	return (*this <= HugeInt(op2));
}//end function operator<=

// overloaded output operator
ostream& operator<<( ostream &output, const HugeInt &num )
{
   int i;
   if (num.sign == '-') // if number is negative, output with sign
		output << num.sign;
   for ( i = 0; i < HugeInt::digits && num.integer[ i ] == 0; ++i )
      ; // skip leading zeros

   if ( i == HugeInt::digits )
      output << 0;
   else
      for ( ; i < HugeInt::digits; ++i )
         output << num.integer[ i ];

   return output;
} // end function operator<<

// Helper private function to get number of digits of HugeInt
int HugeInt::getNumOfDigits() const
{
	int counter = 0; // count of digits
	for (int i = 0; i <digits; ++i)
	{
		if (integer[i] == 0 && counter==0) // skip leading zeroes
		{
			;
		}
		else
			counter++;
	}
	return counter; 
} // end function getNumOfDigits


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
