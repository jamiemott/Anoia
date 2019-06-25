/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the main function for Final Project: Anoia.
** It creates a Game object and then calls the gameStart() function to run the game. 
** To run, type "final" after compiling.
*****************************************************************************/


#include "Game.hpp"

#include <iostream>

using std::cout;
using std::endl;


int main()
{
	Game annoy; //Creates a Game object

	annoy.gameStart(); //All gameplay is handled within the Game class

	cout << "The game is over.  Thanks for playing!" << endl;
	
	return 0;
}