/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for Olympus. An Olympus
** object represents the home of the Gods.  This is where the player must
** go, with a high enough level, to win the game. The player can also go to
** Olympus to level up.
*****************************************************************************/


#include "Olympus.hpp"
#include "Gods.hpp"
#include "Menus.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


/*Space constructor. Sets all values for Olympus stats. Citation for constructor setup
with Space call: www.studytonight.com/cpp/order-of-constructor-call.php */
Olympus::Olympus(Player *p) : Space(p)
{
	setTop(nullptr);
	setBottom(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setAcross(nullptr);
	setName("Olympus");
	setPlayer(p);

	//This location can only be reached from Olympus
	godHome = new Gods(p);
}


//Destructor, manages memory
Olympus::~Olympus()
{
	//Set all pointers to null to manage memory
	setPointers(nullptr, nullptr, nullptr, nullptr, nullptr);
	setPlayer(nullptr);

	//Delete the Gods location
	delete godHome;
	godHome = nullptr;
}


/*This function overrides the Space class function.  It handles the interaction with
the player while they are in the Olympus location. If the player has enough points,
he or she can move to the next level which allows for more game actions or they can
chose to go visit the Gods to get job references.*/
void Olympus::enterSpace()
{
	int action; //Placeholder for action selection choice

	cout << "Welcome to Olympus! What would you like to do?" << endl;

	action = menus("Level up", "Visit the Gods");

	if (action == 1)
	{
		/*This function allows the user to switch god levels based on the power points
		earned.*/
		levelUp();
	}

	else
	{
		/*This function allows the user to enter the space where he/she can interact with other
		Gods to try to get job references to help them win the game.*/
		visitGods();
	}
}


/*This function allows the user to switch god levels based on the power points
earned.*/
void Olympus::levelUp()
{		
	cout <<	"Let's see if you have enough points to level up." << endl;
	cout << "Press enter to continue." << endl;
	cin.ignore();

	if (player->getPower() < 20) //Level 1
	{
		cout << "You only have enough power to be a level one god. You need to have" << endl;
		cout << "20 points to get to level two." << endl << endl;
		player->setLevel(1);
	}

	else if (player->getPower() < 75) //Level 2
	{
		cout << "You are now a level two god and can perform level one or two actions." << endl;
		cout << "You need to have 75 points to get to level three." << endl << endl;
		player->setLevel(2);
	}

	else if (player->getPower() < 150) //Level 3
	{
		cout << "You are now a level three god and can perform level one, two or" << endl;
		cout << "three actions. You need to have 150 points to get to level four." << endl << endl;
		player->setLevel(3);
	}

	else //Level 4
	{
		cout << "You are now a level four god and can perform all actions." << endl << endl;
		player->setLevel(4);
	}
}


/*This function allows the user to enter the space where he/she can interact with other
Gods to try to get job references to help them win the game.*/
void Olympus::visitGods()
{
	//This calls the Gods enterSpace function which handles interaction in the Gods space
	godHome->enterSpace();
}