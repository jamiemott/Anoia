/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for Player. A Player object
** represents Anoia, Goddess of Annoyance, which the user will play as in the Final 
** Project in order to move through the game. 
*****************************************************************************/


#include "Player.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


/*Player constructor. Sets beginning level and power, sets resume to empty and
sets references to false. */ 
Player::Player()
{
	setPower(0); //Set current god power to 0
	setLevel(1); //Sets god level to 1

	//Fills begining resume to empty
	for (int i = 0; i < 5; i++)
	{
		resume[i] = "Empty";
	}

	//Fills begining references to false
	for (int i = 0; i < 3; i++)
	{
		references[i] = "No";
	}
}


//Destructor
Player::~Player()
{
}


//Sets the god power to the passed parameter
void Player::setPower(int p)
{
	power = p;
}


//Sets the current god level to the passed parameter
void Player::setLevel(int a)
{
	level = a;
}


//Sets the string at the passed array index to the provided string parameter
void Player::setResume(int i, string report)
{
	resume[i] = report;
}


//Sets the bool at the passed array index to the provided bool parameter
void Player::setReference(int i, string ref)
{
	references[i] = ref;
}


//Gets the current power rating
int Player::getPower()
{
	return power;
}


//Gets the current god level
int Player::getLevel()
{
	return level;
}


//Gets the report at the passed index
string Player::getReport(int i)
{
	return resume[i];
}


//Gets the reference at the passed index
string Player::getReference(int i)
{
	return references[i];
}


//Print out the current resume
void Player::printResume()
{
	//Loop through to print out each item
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". " << resume[i] << endl;
	}
	cout << endl;
}


//Print out the current references
void Player::printReferences()
{
	//Loop through to print out each item
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ". " << references[i] << endl;
	}
	cout << endl;
}


//This function changes the current god power by the passed parameter
void Player::changePower(int cp)
{
	power += cp;
}