/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the function definition for menus().  It takes
** two to eight string inputs to create the menu and then calls the inputValidate
** function to verify that it is a valid choice for the menu.  It returns the
** integer result of inputValidate.
*****************************************************************************/


#include "Menus.hpp"
#include "Validation.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*This function returns a validated integer choice from the user input.
It takes two strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string a, string b)
{
	cout << "1. " << a << " (Enter 1 to select)" << endl;
	cout << "2. " << b << " (Enter 2 to select)" << endl;

	//Validates that the user input is an integer within the proper range
	int choice = inputValidate(1, 2);

	return choice;	
}


/*This function returns a validated integer choice from the user input.
It takes three strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string a, string b, string c)
{
	cout << "1. " << a << " (Enter 1 to select)" << endl;
	cout << "2. " << b << " (Enter 2 to select)" << endl;
	cout << "3. " << c << " (Enter 3 to select)" << endl;

	//Validates that the user input is an integer within the proper range
	int choice = inputValidate(1, 3);

	return choice;
}


/*This function returns a validated integer choice from the user input.
It takes four strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string a, string b, string c, string d)
{
	cout << "1. " << a << " (Enter 1 to select)" << endl;
	cout << "2. " << b << " (Enter 2 to select)" << endl;
	cout << "3. " << c << " (Enter 3 to select)" << endl;
	cout << "4. " << d << " (Enter 4 to select)" << endl;

	//Validates that the user input is an integer within the proper range
	int choice = inputValidate(1, 4);

	return choice;
}


/*This function returns a validated integer choice from the user input.
It takes five strings as parameters which are used to fill the menu
to be displayed.It calls inputValidate() to verify the user input.*/
int menus(string a, string b, string c, string d, string e)
{
	cout << "1. " << a << " (Enter 1 to select)" << endl;
	cout << "2. " << b << " (Enter 2 to select)" << endl;
	cout << "3. " << c << " (Enter 3 to select)" << endl;
	cout << "4. " << d << " (Enter 4 to select)" << endl;
	cout << "5. " << e << " (Enter 5 to select)" << endl;

	//Validates that the user input is an integer within the proper range
	int choice = inputValidate(1, 5);

	return choice;
}


/*This function returns a validated integer choice from the user input.
It takes six strings as parameters which are used to fill the menu
to be displayed.It calls inputValidate() to verify the user input.*/
int menus(string a, string b, string c, string d, string e, string f)
{
	cout << "1. " << a << " (Enter 1 to select)" << endl;
	cout << "2. " << b << " (Enter 2 to select)" << endl;
	cout << "3. " << c << " (Enter 3 to select)" << endl;
	cout << "4. " << d << " (Enter 4 to select)" << endl;
	cout << "5. " << e << " (Enter 5 to select)" << endl;
	cout << "6. " << f << " (Enter 6 to select)" << endl;

	//Validates that the user input is an integer within the proper range
	int choice = inputValidate(1, 6);

	return choice;
}


/*This function returns a validated integer choice from the user input.
It takes seven strings as parameters which are used to fill the menu
to be displayed.It calls inputValidate() to verify the user input.*/
int menus(string a, string b, string c, string d, string e, string f, string g)
{
	cout << "1. " << a << " (Enter 1 to select)" << endl;
	cout << "2. " << b << " (Enter 2 to select)" << endl;
	cout << "3. " << c << " (Enter 3 to select)" << endl;
	cout << "4. " << d << " (Enter 4 to select)" << endl;
	cout << "5. " << e << " (Enter 5 to select)" << endl;
	cout << "6. " << f << " (Enter 6 to select)" << endl;
	cout << "7. " << g << " (Enter 7 to select)" << endl;

	//Validates that the user input is an integer within the proper range
	int choice = inputValidate(1, 7);

	return choice;
}


/*This function returns a validated integer choice from the user input.
It takes eight strings as parameters which are used to fill the menu
to be displayed.It calls inputValidate() to verify the user input.*/
int menus(string a, string b, string c, string d, string e, string f, string g, string h)
{
	cout << "1. " << a << " (Enter 1 to select)" << endl;
	cout << "2. " << b << " (Enter 2 to select)" << endl;
	cout << "3. " << c << " (Enter 3 to select)" << endl;
	cout << "4. " << d << " (Enter 4 to select)" << endl;
	cout << "5. " << e << " (Enter 5 to select)" << endl;
	cout << "6. " << f << " (Enter 6 to select)" << endl;
	cout << "7. " << g << " (Enter 7 to select)" << endl;
	cout << "8. " << h << " (Enter 8 to select)" << endl;

	//Validates that the user input is an integer within the proper range
	int choice = inputValidate(1, 8);

	return choice;
}