//////////////////////////////////////////////////////////////////////////
// FileName:	WordFont.h
// Description: Class declaration and methods to implement string display
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Declaration of WordFont class and its constructor and methods
//////////////////////////////////////////////////////////////////////////

#include<vector>
using namespace std;

// Class Declaration
class WordFont
{
public:
	WordFont(vector<char> input, int pSize = 8, char pix='*', unsigned int len=8,bool bold=false); // Constructor
	void displayPixellatedString(); // Display the final string
	
private:
	// Private Data Members
	int pixelSize; // Size of each character
	char pixel; // Character to represent pixel
	unsigned int length; // Length of string
	bool bold;// Bold option
	vector<char> inputString; // Vector to hold input string
	vector<vector<char>> displayString; // Two-Dimensional vector which holds final output

	// Private functions to manipulate data
	// Functions to convert characters into pixel displays
	vector<vector<char>> getPixelA();
	vector<vector<char>> getPixelE();
	vector<vector<char>> getPixelI();
	vector<vector<char>> getPixelO();
	vector<vector<char>> getPixelU();
	vector<vector<char>> getPixelB();
	vector<vector<char>> getPixelC();
	vector<vector<char>> getPixelF();
	vector<vector<char>> getPixelH();
	vector<vector<char>> getPixelJ();
	vector<vector<char>> getPixelL();
	vector<vector<char>> getPixelN();
	vector<vector<char>> getPixelT();
	vector<vector<char>> getPixelX();
	vector<vector<char>> getPixelY();
	vector<vector<char>> getPixelZ();

	// Functions to add characters to final string and display it
	void appendToDisplayString(vector<vector<char>> symbol,int marker);
	void display(vector<vector<char>> vec_2D);


};//end class WordFont