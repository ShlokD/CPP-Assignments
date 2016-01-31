//////////////////////////////////////////////////////////////////////////
// FileName:	CAI.cpp
// Description: Implementation of methods and constructors of CAI class
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	CAI class method definitions which choose random questions for
//              multiplication and division, check the answers, print messages
//              based on correct and incorrect answers and print the summary after
//              all questions have been answered
//////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdlib>
using std::rand;
#include<time.h>
#include "CAI.h"
using namespace std;

// Public Constructor to initialize values of data members
CAI::CAI()
{
	rightOnFirstTry = 0;
	wrongGuesses = 0;
	for (int i = 0; i < 5; ++i)
	{
		multiplicationQuestionsDone[i] = 0;
		divisionQuestionsDone[i] = 0;
	}//end loop
}//end constructor

// Start the test by asking questions and then print the summary
void CAI::startTest()
{
	srand(time(NULL)); // To get proper randomization, using srand also
	cout << "\nFirst, Answer Multiplication Questions" << endl;
	chooseRandomMultiplicationQuestion();
	cout << "\nNow, Answer Division Questions" << endl;
	chooseRandomDivisionQuestion();
	printTestSummary();
}// end function startTest

// Choose a multiplication question
void CAI::chooseRandomMultiplicationQuestion()
{
	int questions = 0; // Number of questions to be asked
	while (questions!=5)// Until 5 questions have been asked, keep asking
	{
		int randQ = chooseRandomNumber(1, 5); // Pick a number from 1 to 5
		if (multiplicationQuestionsDone[randQ - 1] != 0) // If question has been asked, corresponding array variable will be 1
		{
			continue;// As question has been asked, move on to next iteration
		}
		else //	Question hasn't been asked
		{
			questions++; // Increase number of questions asked
			multiplicationQuestionsDone[randQ - 1] = 1; // Question has been asked so set its corresponding array variable to 1
			askRandomMultiplicationQuestion(randQ);// Ask multiplication question corresponding to random number
		}
	}// end loop
} // end function chooseRandomMultiplicationQuestion

// Function to choose a random division question and ask it
void CAI::chooseRandomDivisionQuestion()
{
	int questions = 0; // Question counter
	while (questions != 5)// Ask 5 questions
	{
		int randQ = chooseRandomNumber(1, 5); // Pick number from 1 to 5
		if (divisionQuestionsDone[randQ - 1] != 0) // Question has been asked already
		{
			continue;// Move to next iteration
		}
		else // Question hasn't been asked
		{
			questions++;
			divisionQuestionsDone[randQ - 1] = 1;// set corresponding array variable to 1
			askRandomDivisionQuestion(randQ); // Ask division question corresponding to random number
		}
	} // end loop
}// end function chooseRandomDivisionQuestion

// Function to ask random multiplication question
void CAI::askRandomMultiplicationQuestion(int qNo)
{
	int ans = -1; // User-Inputted Value
	int tries = 0; // Number of tries for each question
	int correctAns = 0; // Correct Answer for Each Question
	int correct = 0; // Is Answer Correct? 0 for No, 1 for Yes

	while (correct!=1) // Until correct answer is given, keep asking the question
	{
		switch (qNo) // Ask Random Question
		{
		case 1: cout << "What is 6 multiplied by 7?" << endl; correctAns = 42; break;
		case 2: cout << "What is 2 multiplied by 3?" << endl; correctAns = 6; break;
		case 3: cout << "What is 9 multiplied by 5?" << endl; correctAns = 45; break;
		case 4: cout << "What is 7 multiplied by 8?" << endl; correctAns = 56; break;
		case 5: cout << "What is 4 multiplied by 4?" << endl; correctAns = 16; break;
		}//end switch

		cin >> ans; // Get user's answer
		tries++;// Increase counter of tries for each question
		correct = evalAnswers(ans, correctAns, tries); // Evaluate Answer 
	}//end loop
}// end function randomMultiplicationQuestion

// Function to ask random division question
void CAI::askRandomDivisionQuestion(int qNo)
{
	
	int ans = -1; // User-inputted answer
	int tries = 0;// Number of tries
	int correctAns = 0; //Correct Answer for a question
	int correct = 0;// Is answer correct? 1 for Yes, 0 for No

	while (correct!=1)// Until correct answer is inputted, keep asking the same question
	{
		switch (qNo)
		{
		case 1: cout << "What is 24 divided by 3?" << endl; correctAns = 8; break;
		case 2: cout << "What is 81 divided by 9?" << endl; correctAns = 9; break;
		case 3: cout << "What is 65 divided by 5?" << endl; correctAns = 13; break;
		case 4: cout << "What is 12 divided by 4?" << endl; correctAns = 3; break;
		case 5: cout << "What is 50 divided by 50?" << endl; correctAns = 1; break;
		}// end switch
		
		cin >> ans; // Get user's answer
		tries++;// Increase tries counter for the question
		correct = evalAnswers(ans, correctAns, tries); // Check if answer is correct
	}// end loop
}// end function askRandomDivisionQuestion

// Function to evaluate answers and check if user got it right on first try
int CAI::evalAnswers(int userAns, int correctAns, int tries)
{
	int flag = 0; //  Variable to check if answer is correct
	if (userAns == correctAns) // Answer is correct
	{
		if (tries == 1) // Answer is right on first try
		{
			rightOnFirstTry++; // Increase counter of answers which are right on first try
		}
		printRandomGoodJob(); // Answer is right. So, print good job message
		flag = 1;// Set variable to 1 as answer is right
	}
	else // Answer is wrong
	{
		wrongGuesses++;// Increase counter of wrong guesses
		printRandomEncouragementMessage(); // print an encouragement message
	}
	return flag; // return the status of answer, whether correctly answered or not
}//end function evalAnswers

// Function to print a good job message
void CAI::printRandomGoodJob()
{
	int randNum = chooseRandomNumber(1, 4); // Select number between 1 and 4
	switch (randNum) // Print message corresponding to number
	{
	case 1: cout << "Excellent!" << endl; break;
	case 2: cout << "Very Good!" << endl; break;
	case 3: cout << "Good Work" << endl; break;
	case 4: cout << "Keep Up The Good Work" << endl; break;
	}// end switch
}// end function printRandomGoodJob

// Function to print encouragement message
void CAI::printRandomEncouragementMessage()
{
	int randNum = chooseRandomNumber(1, 4); //choose number between 1 and 4
	switch (randNum)// print message corresponding to random number
	{
	case 1: cout << "No.Please Try Again" << endl; break;
	case 2: cout << "Wrong. Try Once More" << endl; break;
	case 3: cout << "Don't Give Up" << endl; break;
	case 4: cout << "No. Keep Trying" << endl; break;
	}// end switch
}// end function printRandomEncouragementMessage

//  Function to print the summary of the test
void CAI::printTestSummary()
{
	float avgWrongGuesses = (float)wrongGuesses / 10; // get average number of wrong guesses
	cout << endl;
	cout << "You Answered All The Questions!" << endl;
	cout << "You Answered " << rightOnFirstTry << " correctly on first try" << endl;
	cout << "You had total of " << wrongGuesses << " Wrong Guesses" << endl;
	cout << "You had an Average of " << avgWrongGuesses << " Wrong Guesses Per Answer" << endl;
}// end function printTestSummary

// Function to choose a random number between two values, both inclusive
int CAI::chooseRandomNumber(int start, int end)
{
	return start + (rand() % end);
}// end function chooseRandomNumbers