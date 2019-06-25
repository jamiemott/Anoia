/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the function prototype for menus().  It takes
** two to eight string inputs to create the menu and then calls the inputValidate
** function to verify that it is a valid choice for the menu.  It returns the
** integer result of inputValidate.
*****************************************************************************/


#ifndef MENUS_HPP
#define MENUS_HPP

#include <string>

using std::string;


/*This function returns a validated integer choice from the user input.
It takes two strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string, string);


/*This function returns a validated integer choice from the user input.
It takes three strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string, string, string);


/*This function returns a validated integer choice from the user input.
It takes four strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string, string, string, string);


/*This function returns a validated integer choice from the user input.
It takes five strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string, string, string, string, string);


/*This function returns a validated integer choice from the user input.
It takes six strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string, string, string, string, string, string);


/*This function returns a validated integer choice from the user input.
It takes seven strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string, string, string, string, string, string, string);


/*This function returns a validated integer choice from the user input.
It takes eight strings as parameters which are used to fill the menu
to be displayed.  It calls inputValidate() to verify the user input.*/
int menus(string, string, string, string, string, string, string, string);

#endif