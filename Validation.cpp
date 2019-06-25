/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the function definition for inputValidate(). It takes
** the lower and upper bounds of the allowed range and verifies that the user
** input a correct integer or double and returns it to the function calling it.
*****************************************************************************/


#include "Validation.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::istringstream;
using std::string;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

/*This function returns a validated integer choice from the user input.
It takes two integers, representing the lower and upper bounds of the
allowed input and compares the user input to the allowed range.  If the
input is incorrect, it asks the user to try again.*/

/*This defines the getline() function used to check the user
input.  If it can pull in data, convert to an int and there is
no remainder, it passes the data to the inputValidate function.
Citation: Fellow student Justin Lin refered me to the following resource:
www.cplusplus.com/forum/beginner/170685/#msg851160*/
istream& getline(istream& ins, int& n)
{
	n = 0;  

	// Read a line from the user
	string s;
	if (getline(ins, s))
	{
		// Get rid of any following whitespace
		s.erase(s.find_last_not_of(" \f\n\r\t\v") + 1);

		// Convert it to integer
		istringstream ss(s);
		ss >> n;

		// Make sure nothing else is in the stream
		if (!ss.eof())
			ins.setstate(std::ios::failbit);
	}
	//Value is used by inputValidate()
	return ins;
}

/*This function returns a validated integer choice from the user input.
It takes two integers, representing the lower and upper bounds of the
allowed input and compares the user input to the allowed range.  If the
input is incorrect, it asks the user to try again. If getline() cannot
convert the user input to an integer, it also asks them to try again.*/
int inputValidate(int lower, int upper)
{
	int userInput = 0; //placeholder for user input
	int bottomRange = lower; //integer below acceptable range
	int topRange = upper; //integer above acceptable range

	while (!getline(cin, userInput) || (userInput < bottomRange) || (userInput > topRange))
	{
		cin.clear();
		cout << "That was invalid. Please enter an integer from " << bottomRange << " to " << topRange << ": ";
	}

	return userInput;
}


/*This defines the getline() function used to check the user
input.  If it can pull in data, convert to a long int and there is
no remainder, it passes the data to the inputValidate function.
Citation: Fellow student Justin Lin refered me to the following resource:
www.cplusplus.com/forum/beginner/170685/#msg851160*/
istream& getline(istream& ins, long int& n)
{
	n = 0;

	// Read a line from the user
	string s;
	if (getline(ins, s))
	{
		// Get rid of any following whitespace
		s.erase(s.find_last_not_of(" \f\n\r\t\v") + 1);

		// Convert it to integer
		istringstream ss(s);
		ss >> n;

		// Make sure nothing else is in the stream
		if (!ss.eof())
			ins.setstate(std::ios::failbit);
	}
	//Value is used by inputValidate()
	return ins;
}

/*This function returns a validated long integer choice from the user input.
It takes two long integers, representing the lower and upper bounds of the
allowed input and compares the user input to the allowed range.  If the
input is incorrect, it asks the user to try again. If getline() cannot
convert the user input to an long integer, it also asks them to try again.*/
long int inputValidate(long int lower, long int upper)
{
	long int userInput = 0; //placeholder for user input
	long int bottomRange = lower; //integer below acceptable range
	long int topRange = upper; //integer above acceptable range

	while (!getline(cin, userInput) || (userInput < bottomRange) || (userInput > topRange))
	{
		cin.clear();
		cout << "That was invalid. Please enter an integer from " << bottomRange << " to " << topRange << ": ";
	}

	return userInput;
}


/*This defines the getline() function used to check the user
input.  If it can pull in data, convert to a double and there is
no remainder, it passes the data to the inputValidate function.
Citation: Fellow student Justin Lin refered me to the following resource:
www.cplusplus.com/forum/beginner/170685/#msg851160*/
istream& getline(istream& ins, double& n)
{
	n = 0.0;

	// Read a line from the user
	string s;
	if (getline(ins, s))
	{
		// Get rid of any following whitespace
		s.erase(s.find_last_not_of(" \f\n\r\t\v") + 1);

		// Convert it to integer
		istringstream ss(s);
		ss >> n;

		// Make sure nothing else is in the stream
		if (!ss.eof())
			ins.setstate(std::ios::failbit);
	}
	//Value is used by inputValidate()
	return ins;
}

/*This function returns a validated integer choice from the user input.
It takes two doubles, representing the lower and upper bounds of the
allowed input and compares the user input to the allowed range.  If the
input is incorrect, it asks the user to try again. If getline() cannot
convert the user input to a double, it also asks them to try again.*/
double inputValidate(double lower, double upper)
{
	double userInput = 0; //placeholder for user input
	double bottomRange = lower; //integer below acceptable range
	double topRange = upper; //integer above acceptable range

	while (!getline(cin, userInput) || (userInput < bottomRange) || (userInput > topRange))
	{
		cin.clear();
		cout << "That was invalid. Please enter a double from " << bottomRange << " to " << topRange << ": ";
	}

	return userInput;
}