/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the function prototype for inputValidate(). It takes
** the lower and upper bounds of the allowed range and verifies that the user
** input a correct integer or double and returns it to the function calling it.
*****************************************************************************/


#ifndef VALIDATION_HPP
#define VALIDATION_HPP


/*This function returns a validated integer choice from the user input.
It takes two integers, representing the lower and upper bounds of the
allowed input and compares the user input to the allowed range.  If the
input is incorrect, it asks the user to try again.*/
int inputValidate(int lower, int upper);


/*This function returns a validated long integer choice from the user input.
It takes two long integers, representing the lower and upper bounds of the
allowed input and compares the user input to the allowed range.  If the
input is incorrect, it asks the user to try again.*/
long int inputValidate(long int lower, long int upper);


/*This function returns a validated double choice from the user input.
It takes two integers, representing the lower and upper bounds of the
allowed input and compares the user input to the allowed range.  If the
input is incorrect, it asks the user to try again.*/
double inputValidate(double lower, double upper);


#endif

