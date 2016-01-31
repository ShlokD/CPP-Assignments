//////////////////////////////////////////////////////////////////////////
// FileName:	CAI.h
// Description: Definition of CAI class which contains methods to ask random questions
//				for multiplication and division problems
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	CAI class with public and private methods
//////////////////////////////////////////////////////////////////////////

class CAI
{
public:
	CAI(); //Constructor
	void startTest(); //Start asking Questions

private:
	void chooseRandomMultiplicationQuestion(); // choose a random Multiplication Question
	void chooseRandomDivisionQuestion(); // choose a random Division Question
	void askRandomMultiplicationQuestion(int qNo); // Ask a multiplication Question
	void askRandomDivisionQuestion(int qNo); // Ask a Division Question
	void printRandomGoodJob(); // Print good job message
	void printRandomEncouragementMessage(); // Print encouragement message
	int chooseRandomNumber(int start, int end); // Choose a random number between start and end, both inclusive
	void printTestSummary(); // Print summary of test
	int evalAnswers(int userAns, int correctAns, int tries); // evaluate answers

	int rightOnFirstTry; // Counter of answers which were correct on first try
	int wrongGuesses; // Count of wrong guesses
	int multiplicationQuestionsDone[5]; // Array to maintain which multiplication questions have been asked
	int divisionQuestionsDone[5];// Array to maintain which division questions have been asked
};