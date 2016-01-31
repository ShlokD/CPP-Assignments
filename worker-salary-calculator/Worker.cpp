//////////////////////////////////////////////////////////////////////////
// FileName:	Worker.h
// Description: Implementation of Worker class methods to calculate salary
//				and display bar graph
// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Definition of methods of Worker class
//////////////////////////////////////////////////////////////////////////

#include "Worker.h"
#include<iostream>
using namespace std;

// Constructor to initialize values

Worker::Worker()
{
	paycode = 0;
	totalmanagersalary = 0;
	totalhourlysalary = 0;
	totalcommissionsalary = 0;
	totalpiecesalary = 0;
} //end Constructor

// Starts a loop to calculate salaries of different types of workers
// and makes a call to function which prints the bar graph
// when all salaries have been calculated

void Worker::start()
{
	while (paycode != -1)
	{
		cout << "Enter paycode(-1 to end): ";
		cin >> paycode;

		switch (paycode)
		{
		case 1: totalmanagersalary += calculateManagerSalary(); break; // calculate manager salary and add to total salaries for that worker type
		case 2: totalhourlysalary += calculateHourlySalary(); break; // calculate hourly worker salary and add to total salaries for that worker type
		case 3: totalcommissionsalary += calculateCommissionSalary(); break; // calculate commission worker salary and add to total salaries for that worker type
		case 4: totalpiecesalary += calculatePieceSalary(); break; // calculate piece worker salary and add to total salaries for that worker type
		default:break;
		}//end switch
	}//end while loop
	generateBarGraph(); //Once all salaries have been calculated, print bar graph 
}//end function start

// Function to calculate salary of Manager
int Worker::calculateManagerSalary()
{
	int salary=0;
	cout << "Manager Selected" << endl;
	cout << "Enter Weekly Salary: ";
	cin >> salary;
	cout << "Manager's Pay Is " << salary << endl;;
	return salary;
}//end function calculateManagerSalary

// Function to calculate salary of Hourly Worker
float Worker::calculateHourlySalary()
{
	float hourlywage=0;
	int hours = 0;
	float salary=0;
	cout << "Hourly Worker Selected" << endl;
	cout << "Enter Hourly Salary: ";
	cin >> hourlywage;
	cout << "Enter The Total Hours Worked: ";
	cin >> hours;

	if (hours <= 40) // Salary is hourly wage times the hours worked
	{
		salary = hours * hourlywage;
	} 
	else // Get overtime salary also
	{
		int basic = 40 * hourlywage; //Basic salary rate
		int overtime = (hours - 40)*1.5*hourlywage; // Overtime salary rate
		salary = overtime + basic;
	}
	cout << "Worker's Pay Is " << salary<<endl;
	return salary;
} // end function calculateHourlySalary

//Function to calculate commission worker's salary
float Worker::calculateCommissionSalary()
{
	cout << "Commission Worker Selected" << endl;
	float salary = 0;
	int sales = 0;
	cout << "Enter Weekly Sales: ";
	cin >> sales;
	salary = 250 + (0.057*sales); // Commission Salary Rate which is 250 + 5.7 Percent of Sales
	cout << "Commission Worker's Pay Is " << salary<<endl;
	return salary;
} // end function calculateCommissionSalary

// Function to calculate piece worker's salary
float Worker::calculatePieceSalary()
{
	cout << "Piece Worker Selected" << endl;
	int pieces = 0;
	float wage_per_piece = 0;
	float salary = 0;

	cout << "Enter Number of Pieces: ";
	cin >> pieces;
	cout << "Enter Wage Per Piece: ";
	cin >> wage_per_piece;

	salary = wage_per_piece*pieces; // salary rate for piece worker
	cout << "Piece Worker's Pay  Is " << salary<<endl;
	return salary;
} //end function CalculatePieceSalary

// Function to generate bar graph for all workers' salaries
void Worker::generateBarGraph()
{
	int mgr = (int)totalmanagersalary / 100; // Get number of data points for managers
	int hr = (int)totalhourlysalary / 100; // Get number of data points for hourly workers
	int comm = (int)totalcommissionsalary / 100; // Get number of data points for commission workers
	int pc = (int)totalpiecesalary / 100; // Get number of data points for piece workers
	int i = 0;

	//Print Managers' Graph
	std::cout << endl << endl;
	std::cout << "Managers ";
	for (i = 0; i <mgr; ++i)
	{
		cout << "*";
	}//end loop
	cout << endl;

	//Print Hourly Workers' Graph
	std::cout << "Hourly Workers ";
	for (i = 0; i <hr; ++i)
	{
		cout << "*";
	}
	cout << endl;

	//Print Commission Workers' Graph
	std::cout << "Commission Workers ";
	for (i = 0; i <comm; ++i)
	{
		cout << "*";
	}
	cout << endl;

	//Print Piece Workers' Graph
	std::cout << "Piece Workers ";
	for (i = 0; i <pc; ++i)
	{
		cout << "*";
	}
	cout << endl;
} // end function generateBarGraph