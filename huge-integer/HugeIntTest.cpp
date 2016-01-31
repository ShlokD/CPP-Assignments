///////////////////////////////////////////////////////////////////////
// Class HugeInt Implementation
// FileName:	HugeIntTest.cpp
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Test driver for HugeInt class
// Description - This file implements a class to store numbers larger than 32 bits
// Reference:		Exercise 11.9, C++ How to Program
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Hugeint.h"
using namespace std;

int main()
{
	// HugeInt values for tests
   HugeInt n1( 7654321 );
   HugeInt n2( 7891234 );
   HugeInt n3( "99999999999999999999999999999" );
   HugeInt n4( "1" );
   HugeInt n5("888888888888888888888888888888");
   HugeInt n6("888888888888888888888888888887");
   HugeInt n7(19);
   HugeInt n8(-7654321);
   HugeInt result;

   cout << "n1 is " << n1 << "\nn2 is " << n2
	   << "\nn3 is " << n3 << "\nn4 is " << n4
	   << "\nn5 is " << n5 << "\nn6 is " << n6
	   << "\nn7 is " << n7 << "\nn8 is "<<n8
      << "\nresult is " << result << "\n\n";


   cout << "********************************************" << endl;
   cout << "Testing Arithmetic Operators" << endl;
   cout << "********************************************" << endl << endl;

   cout << endl << endl;
   cout << "Testing Addition Operator" << endl << endl;


   // Testing of + operator, with positive and negative values
   // passed as HugeInt, int and strings
   result = n1 + n2;
   cout << n1 << " + " << n2 << " = " << result << "\n\n";

   cout << n3 << " + " << n4 << "\n= " << ( n3 + n4 ) << "\n\n";

   result = n1 + 9;
   cout << n1 << " + " << 9 << " = " << result << endl;

   result = n2 + "10000";
   cout << n2 << " + " << "10000" << " = " << result << endl;

   result = n2 + "-100000";
   cout << n2 << "+" << "-100000" << " = " << result << endl;

   result = n8 + "100000";
   cout << n8 << "+" << "100000" << " = " << result << endl;

   result = n8 + "-100000";
   cout << n8 << "+" << "-100000" << " = " << result << endl;
   
   // end testing + operator

   cout << endl << endl;
   cout << "Testing Subtraction Operator" << endl << endl;

   // Testing of - operator, with positive and negative values
   // passed as HugeInt, int and strings
   result = n1 - n2;
   cout << n1 << " - " << n2 << " = " << result << endl;

   result = n1 - -7891234;
   cout << n1 << " - " << -7891234 << " = " << result << endl;

   result = n8 - n2;
   cout << n8 << " - " << n2 << " = " << result << endl;

   result = n8 - "-7891234";
   cout << n8 << " - " << "-7891234" << " = " << result << endl;

   // end testing - operator

   cout << endl << endl;
   cout << "Testing Multiplication Operator" << endl << endl;


   // Testing of * operator, with positive and negative values
   // passed as HugeInt, int and strings
   result = n1*n2;
   cout << n1 << "*" << n2 << " = " << result << endl;

   result = n1*-7891234;
   cout << n1 << "*" << -7891234 << " = " << result << endl;

   result = n8*n2;
   cout << n8 << "*" << n2 << " = " << result << endl;

   result = n8*"-7891234";
   cout << n8 << "*" << "-7891234" << " = " << result << endl;
   // end testing * operator

   cout << endl << endl;
   cout << "Testing Division Operator" << endl << endl;


   // Testing of / operator, with positive,negative and zero values
   // passed as HugeInt, int and strings
   result = n1/n7;
   cout << n1 << "/" << n7 << " = " << result << endl;

   result = n1 / -19;
   cout << n1 << "/" << -19 << " = " << result << endl;

   result = n8 / n7;
   cout << n8 << "/" << n7 << " = " << result << endl;

   result = n8 / -19;
   cout << n8 << "/" << -19 << " = " << result << endl;

   result = n1 / n1;
   cout << n1 << "/" << n1 << " = " << result << endl;

   result = n1 / "0";
   cout << n1 << "/" << "0" << " = " << result << endl;

   result = n3 / "9";
   cout << n3 << "/" << "9" << " = " << result << endl;
   // end testing / operator

   cout << endl << endl;
   cout << "********************************************" << endl;
   cout << "Testing Relational And Equality Operators" << endl;
   cout << "********************************************" << endl << endl;


   // Testing of ==,!=,>,>=,<,<= operators, with positive and negative values
   // passed as HugeInt, int and strings
   if (n5 == n6) cout << n5 << " == " << n6 << endl << endl;
   if (n5 != n6) cout << n5 << " != " << n6 << endl << endl;
   if (n5 > n6) cout << n5 << " > " << n6 << endl << endl;
   if (n5 < n6) cout << n5 << " < " << n6 << endl << endl;
   if (n5 >= n6) cout << n5 << " >= " << n6 << endl << endl;
   if (n5 <= n6) cout << n5 << " <= " << n6 << endl << endl;

   cout << endl << endl;
   cout << "Adding 1 to " << n6 << endl << endl;
   n6 = n6 + 1;

   if (n5 == n6) cout << n5 << " == " << n6 << endl << endl;
   if (n5 != n6) cout << n5 << " != " << n6 << endl << endl;
   if (n5 > n6) cout << n5 << " > " << n6 << endl << endl;
   if (n5 < n6) cout << n5 << " < " << n6 << endl << endl;
   if (n5 >= n6) cout << n5 << " >= " << n6 << endl << endl;
   if (n5 <= n6) cout << n5 << " <= " << n6 << endl << endl;

   cout << endl << endl;
   cout << "Adding 2 to " << n6 << endl << endl;
   n6 = n6 + 2;

   if (n5 == n6) cout << n5 << " == " << n6 << endl << endl;
   if (n5 != n6) cout << n5 << " != " << n6 << endl << endl;
   if (n5 > n6) cout << n5 << " > " << n6 << endl << endl;
   if (n5 < n6) cout << n5 << " < " << n6 << endl << endl;
   if (n5 >= n6) cout << n5 << " >= " << n6 << endl << endl;
   if (n5 <= n6) cout << n5 << " <= " << n6 << endl << endl;

   cout << endl << endl;
   if (n5 == "9") cout << n5 << " == " << "9" << endl << endl;
   if (n5 != 9) cout << n5 << " != " << 9 << endl << endl;
   if (n5 > "9") cout << n5 << " > " << "9" << endl << endl;
   if (n5 < 9) cout << n5 << " < " << 9 << endl << endl;
   if (n5 >= "9") cout << n5 << " >= " << "9" << endl << endl;
   if (n5 <= 9) cout << n5 << " <= " << 9 << endl << endl;

   cout << endl << endl;
   if (n8 == "-9") cout << n8 << " == " << "-9" << endl << endl;
   if (n8 != -9) cout << n8 << " != " << -9 << endl << endl;
   if (n8 > "-9") cout << n8 << " > " << "-9" << endl << endl;
   if (n8 < -9) cout << n8 << " < " << -9 << endl << endl;
   if (n8 >= "-9") cout << n8 << " >= " << "-9" << endl << endl;
   if (n8 <= -9) cout << n8 << " <= " << -9 << endl << endl;
} // end main



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
