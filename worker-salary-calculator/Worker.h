//////////////////////////////////////////////////////////////////////////
// FileName:	Worker.h
// Description: Definition of Worker class which is used to calculate salaries for
//				different workers as well as definition of methods for the same

// Course:		CIS 554 - Object Oriented Programming in C++
// Author:      Shlok Pankaj Desai
// Contents:	Worker class with public constructor and different methods
//////////////////////////////////////////////////////////////////////////

class Worker
{
public:
	Worker(); //Constructor
	void start();//Start calculating salary
private:
	
	int calculateManagerSalary(); //Calculate salary for manager
	float calculateCommissionSalary(); // Calculate salary for commission workers
	float calculateHourlySalary(); // Calculate salary for hourly wage workers
	float calculatePieceSalary(); // Calculate salary for piece workers
	void generateBarGraph(); // Generate bar graph based on salary of workers

	int totalmanagersalary; // Salary of all managers
	float totalhourlysalary; // Salary of all hourly wage workers
	float totalcommissionsalary; // Salary of all commission workers
	float totalpiecesalary;// Salary of all piece workers
	int paycode;// Paycode of worker
};//end class Worker