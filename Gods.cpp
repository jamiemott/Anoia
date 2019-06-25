/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for Gods. A Gods
** object represents the home of the Gods.  This is where the player must
** go to try to get references for the job interview.
*****************************************************************************/


#include "Gods.hpp"
#include "Menus.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


/*Space constructor. Sets all values for Gods stats. Citation for constructor setup
with Space call: www.studytonight.com/cpp/order-of-constructor-call.php */
Gods::Gods(Player *p) : Space(p)
{
	setTop(nullptr);
	setBottom(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setAcross(nullptr);
	setName("Gods");
	setPlayer(p);
}


//Destructor, manages memory
Gods::~Gods()
{
	//Set all pointers to null to manage memory
	setPlayer(nullptr);
}


/*This function overrides the Space class function.  It handles the interaction with
the player while they are in the Gods location. The player can choose which gods to
visit to try to win job references.*/
void Gods::enterSpace()
{
	int action; //placeholder for user choice

	cout << "Welcome to Gods! This location is off the map, so you will be back" << endl;
	cout << "in Olympus when you are done. Here are your current references:" << endl;
	
	cout << "Tyche, Goddess of Luck: " << player->getReference(0) << endl;
	cout << "Athena, Goddess of Wisdom: " << player->getReference(1) << endl;
	cout << "Kratos, God of Strength: " << player->getReference(2) << endl << endl;
	
	cout << "Who would you like to visit? " << endl;
	
	action = menus("Tyche", "Athena", "Kratos");

	if (action == 1) //Tyche
	{
		/*This function handles the interaction with Tyche, Goddess of Luck. The
		player must win a game of chance to get the reference. */
		visitTyche();
	}

	else if (action == 2) //Athena
	{
		/*This function handles the interaction with Athena, Goddess of Wisdom. The
		player must correctly answer a question to get the reference. */
		visitAthena();
	}

	else //Kratos
	{
		/*This function handles the interaction with Kratos, God of Strength. The
		player must show strength to get the reference. */
		visitKratos();
	}
}


/*This function handles the interaction with Tyche, Goddess of Luck. The player must
win a game of chance to get the reference. */
void Gods::visitTyche()
{
	cout << endl << "So you want me to recommend you for a promotion... You'll have to" << endl;
	cout << "beat me in a game of chance in order to get it. We will toss a coin." << endl;
	cout << "Do you want to be heads or tails?" << endl;

	int coinChoice = menus("Heads", "Tails"); //Holds user choice

	cout << endl << "Let's see if you win..." << endl;

	int coin = rand() % 2 + 1; //Coin toss

	if (coinChoice == coin) //win
	{
		cout << "Today is your lucky day. Here is your reference letter." << endl << endl;

		player->setReference(0, "Yes"); //Add reference
	}

	else //lose
	{
		cout << "Luck is not with you today. You'll have to visit again later" << endl;
		cout << "if you want to try again." << endl << endl;
	}
}


/*This function handles the interaction with Tyche, Goddess of Luck. The player must
correctly answer a question to get the reference. */
void Gods::visitAthena()
{
	cout << endl << "So you want me to recommend you for a promotion... You'll have to" << endl;
	cout << "answer a question to show me your wisdom." << endl;
	
	int question = rand() % 2 + 1; //Selects question so it isn't always the same

	if (question == 1)
	{
		cout << "Which option is correct in C++?" << endl;
		
		int answer = menus("Variables must be initalized", "Variables SHOULD be initialized", 
			"Never initialize variables"); //Holds user choice

		if (answer == 2)
		{
			cout << "Correct! Here is your reference letter." << endl << endl;

			player->setReference(1, "Yes"); //Add reference
		}

		else
		{
			cout << "That is incorrect. You'll have to try again later if you want my reference." << endl << endl;
		}

	}

	else
	{
		cout << "In the Nintendo games, what color is Mario's hat?" << endl;

		int answer = menus("Red", "Green", "Blue"); //Holds user choice

		if (answer == 1) //Win
		{
			cout << "Correct! Here is your reference letter." << endl;

			player->setReference(1, "Yes"); //Add reference
		}

		else //Lose
		{
			cout << "That is incorrect. You'll have to try again later if you want my reference." << endl << endl;
		}
	}
}


/*This function handles the interaction with Kratos, God of Strength. The player must 
show strength to get the reference. */
void Gods::visitKratos()
{
	cout << endl << "So you want me to recommend you for a promotion... You'll have to" << endl;
	cout << "show me your strength to get it." << endl;

	if (player->getLevel() == 4)
	{
		cout << "Ooh, I can feel your power! Here is your reference letter." << endl << endl;

		player->setReference(2, "Yes"); //Add reference
	}

	else
	{
		cout << "You aren't strong enough to earn my recommendation offhand." << endl;
		cout << "Would you like to fight for it?" << endl;

		int fightChoice = menus("Yes", "No");

		if (fightChoice == 1) //Yes
		{
			int win = rand() % 100 + 1; //Get a random number to use for the fight

			if (player->getLevel() == 1 && win > 90) //Level 1 and random number is 91-100
			{
				cout << "You are strong! Here is your reference letter." << endl << endl;

				player->setReference(2, "Yes"); //Add reference
			}

			else if (player->getLevel() == 2 && win > 75) //Level 2 and random number is 76-100
			{
				cout << "You are strong! Here is your reference letter." << endl << endl;

				player->setReference(2, "Yes"); //Add reference
			}

			else if (player->getLevel() == 3 && win > 50) //Level 3 and random number is 51-100
			{
				cout << "You are strong! Here is your reference letter." << endl << endl;

				player->setReference(2, "Yes"); //Add reference
			}

			else //Lose fight
			{
				cout << "Ha! I knew you wouldn't beat me. Come back when you are stronger." << endl << endl;
			}
		}

		else //No
		{
			cout << "Come back when you are stronger or ready to fight." << endl << endl;
		}
	}
}