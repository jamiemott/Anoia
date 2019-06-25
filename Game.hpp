/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for Game. A Game represents a
** game such as cards or dice. The default constructor initalizes the game object.
** The gameStart function begins the game loop by calling the menu.  
*****************************************************************************/


#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Space.hpp"

#include <string>

using std::string;


class Game
{
private:
	int steps; //game step counter
	Player *p1; //pointer to a player object
	Space *current; //Pointer to current location in the game
	Space *zone1; //Pointer to space 1
	Space *zone2; //Pointer to space 2
	Space *zone3; //Pointer to space 3
	Space *zone4; //Pointer to space 4
	Space *zone5; //Pointer to space 5
	Space *zone6; //Pointer to space 6
	

public:
	Game(); //Creates Game object
	~Game(); //Destructor
	void gameStart(); //Calls gameMenu
	int exitGame(); //Returns from object to main fuction
	void gameInfo(); //This function provides the user information about the game.
	void setUpGame(); //Creates player and game zones
	void playGame(); //Handles stepping through the rounds
	void playRound(); //Calls map display then handles movement selection
	void displayMap(); //Gives current game map
	void jobReview(); //Checks player stats to see if they win
};
#endif
