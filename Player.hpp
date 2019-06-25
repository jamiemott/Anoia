/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for Player. A Player object
** represents Anoia, Goddess of Annoyance, which the user will play as in the Final 
** Project in order to move through the game. 
*****************************************************************************/


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

using std::string;


class Player
{
private:
	int power; //current god power, power translates into higher levels
	int level; //current god level, more power equals more action options
	string resume[5]; //Holds the job reports needed to beat the game
	string references[3]; //Holds job references
	

public:
	Player(); //constructor
	~Player(); //destructor
	void setPower(int); //sets the current god power
	void setLevel(int); //sets the current god level
	void setResume(int, string); //sets the resume items to different values
	void setReference(int, string); //sets the reference items to different values
	int getPower();// returns the god power
	int getLevel(); //returns the current god level
	string getReport(int); //Returns the string at the passed location
	string getReference(int); //Returns the string at the passed location
	void printResume(); //Shows current items in resume array
	void printReferences(); //Shows current items in reference array
	void changePower(int); //Changes the power level by the passed parameter
	
};
#endif
