/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for Game. A Game represents a
** game such as cards or dice. The default constructor initalizes the game object.
** The gameStart function begins the game loop by calling the menu.  
*****************************************************************************/


#include "Game.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "Airport.hpp"
#include "Highway.hpp"
#include "House.hpp"
#include "MovieTheater.hpp"
#include "Office.hpp"
#include "Olympus.hpp"
#include "Menus.hpp"
#include "Validation.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>


using std::cout;
using std::cin;
using std::endl;


/*Constructor.  Initializes steps to 0 and pointers to NULL. Sets the random
number generator seed. */
Game::Game()
{
	unsigned seed = time(0);
	srand(seed);

	steps = 0; //Set step counter to 0
	p1 = nullptr; //Set to null until game setup
	current = nullptr; //Set to null until game setup
	zone1 = nullptr; //Set to null until game setup
	zone2 = nullptr; //Set to null until game setup
	zone3 = nullptr; //Set to null until game setup
	zone4 = nullptr; //Set to null until game setup
	zone5 = nullptr; //Set to null until game setup
	zone6 = nullptr; //Set to null until game setup
}


// Destructor
Game::~Game()
{
	
}


//This function starts the game by calling the menu.
void Game::gameStart()
{
	cout << endl << "Welcome to Anoia!" << endl << endl;

	int playChoice = menus("Play Game", "Exit Game");

	if (playChoice == 1) //Playing
	{
		gameInfo();
		setUpGame();
	}

	else //Quitting
	{
		exitGame();
	}
}



/*This function is used to exit the game.  It returns 0 to signify that the function
is complete after deleteing all dynamically created objects and setting all pointers
to null.*/
int Game::exitGame()
{
	//Delete player and set pointer to null
	delete p1;
	p1 = nullptr;

	//Set current location pointer to null
	current = nullptr;

	//Delete all the Space objects created
	delete zone1;
	delete zone2;
	delete zone3;
	delete zone4;
	delete zone5;
	delete zone6;

	//Set zone pointers to null
	zone1 = nullptr; 
	zone2 = nullptr; 
	zone3 = nullptr; 
	zone4 = nullptr; 
	zone5 = nullptr; 
	zone6 = nullptr; 

	return 0; //return to main to quit
}


/*This function provides information about the game, including the goals and the necessary
actions to win.*/
void Game::gameInfo()
{
	cout << "In this game, you are Anoia, a low-level diety currently in charge of" << endl;
	cout << "getting items stuck in drawers to annoy humans. It's been eons since you" << endl;
	cout << "took on this role and your next performance review is approaching. If you" << endl;
	cout << "do well enough, maybe you can finally promote up to some big-time god duties!" << endl << endl;
	
	cout << "At the start of the game, you are a level one god. In order to increase your" << endl;
	cout << "level, you must travel the word annoying humans to collect power. You can then" << endl;
	cout << "check into Olympus to increase your level and access more abilities. Higher" << endl;
	cout << "level abilities give more points." << endl << endl;

	cout << "In order to win the game, you must collect job reports for your performance" << endl;
	cout << "review. You will need to collect one report from each of the five areas in" << endl;
	cout << "the game: " << endl;
	cout << "1. Airport" << endl;
	cout << "2. Highway" << endl;
	cout << "3. House" << endl;
	cout << "4. Movie Theater" << endl;
	cout << "5. Office" << endl;
	cout << "Higher level abilities look better on your review and will increase your" << endl;
	cout << "chance of promotion (meaning you need better reports to win the game)." << endl << endl;

	cout << "You will also need to get references from other gods in order to win." << endl;
	cout << "You must receive at least two recommendations to win the game. You'll" << endl;
	cout <<	"need to go through Olympus to get to the gods and convince them of your skills." << endl << endl;

	cout << "Note that you will only be allowed to complete 50 moves before the" << endl;
	cout << "performance review happens. If you think you have what you need to ace" << endl;
	cout << "your review, you can request it any time from the movement menu." << endl << endl;

	cout << "Press enter to continue" << endl;
	cin.ignore();
}


/*This function creates the player and the spaces for the game.  It also sets the pointers
for the spaces so that the locations are linked and the player can move between them.*/
void Game::setUpGame()
{
	//Create player object first so that spaces can point to it
	p1 = new Player(); 

	//Create game board spaces
	zone1 = new Olympus(p1); //Create Olympus for zone 1
	zone2 = new Airport(p1); //Create Airport for zone 2
	zone3 = new Highway(p1); //Create Highway for zone 3
	zone4 = new House(p1); //Create House for zone 4
	zone5 = new MovieTheater(p1); //Create Movie Theater for zone 5
	zone6 = new Office(p1); //Create Office for zone 6

	current = zone1;

	/*Link the zones together to allow for movement around the game. I visualize this as
	a cube with all parts connected. */
	zone1->setPointers(zone5, zone2, zone6, zone4, zone3);
	zone2->setPointers(zone5, zone3, zone6, zone1, zone4);
	zone3->setPointers(zone5, zone4, zone6, zone2, zone1);
	zone4->setPointers(zone5, zone1, zone6, zone3, zone2);
	zone5->setPointers(zone3, zone2, zone1, zone4, zone6);
	zone6->setPointers(zone1, zone2, zone3, zone4, zone5);
	
	//This function handles the main steps of playing the game.
	playGame();
}


/*This function handles the main steps of playing the game.  For each round, it calls
the functions to have player select an area to visit and display the current map. Once
the player hits 50 steps, the job reivew function is called.  If steps equals more than
50, that is the signal value to allow the user to just exit the game.*/
void Game::playGame()
{
	while (steps < 50)
	{
		playRound(); //Display map and use actions
	}

	if (steps == 50)
	{
		jobReview(); //Check to see if they won the game
	}

	exitGame();  //Clean up memory and exit
}


/*This function displays the current game map and then allows the user to pick where to go.  The
spaces handle the game play for those actions. */
void Game::playRound()
{
	displayMap(); //Shows current surroundings

	//Ask user where they want to go next.
	cout << "Where would you like to go?" << endl;
	int moveChoice = menus(current->getLeft()->getName(), current->getRight()->getName(),
		current->getTop()->getName(), current->getBottom()->getName(), current->getAcross()->getName(),
		"Job Review", "Quit Game");

	if (moveChoice == 1) //Left
	{
		current = current->getLeft(); //Move left
		steps += 1;
		current->enterSpace(); //Enter zone
	}

	else if (moveChoice == 2) //Right
	{
		current = current->getRight(); //Move right
		steps += 1;
		current->enterSpace(); //Enter zone
	}

	else if (moveChoice == 3) //Up
	{
		current = current->getTop(); //Move up
		steps += 1;
		current->enterSpace(); //Enter zone
	}

	else if (moveChoice == 4) //Down
	{
		current = current->getBottom(); //Move down
		steps += 1;
		current->enterSpace(); //Enter zone
	}

	else if (moveChoice == 5) //Across
	{
		current = current->getAcross(); //Move across
		steps += 1;
		current->enterSpace(); //Enter zone
	}

	else if (moveChoice == 6) //Job review
	{
		steps = 50;
	}

	else //Quit
	{
		steps = 100;
	}
}


/*This function shows the current game map */
void Game::displayMap()
{
	//Print out the current location along with the surroundings
	cout << "Current map:" << endl;
	cout << "Your current location is: " << current->getName() << endl;
	cout << "To the left is: " << current->getLeft()->getName() << endl;
	cout << "To the right is: " << current->getRight()->getName() << endl;
	cout << "To the top is: " << current->getTop()->getName() << endl;
	cout << "To the bottom is: " << current->getBottom()->getName() << endl;
	cout << "Across from here is: " << current->getAcross()->getName() << endl << endl;
}


/*This function looks at the array used by the player to hold their job report resume
and assigns points based on the level of the report.  If the player has a high enough
score, they win the game. */
void Game::jobReview()
{
	cout << "It is time for your review. Press enter to continue" << endl;
	cin.ignore();
		
	cout <<	"Here is your current resume:" << endl;

	p1->printResume(); //Show current

	cout << endl << "Here are your current references:" << endl;

	cout << "Tyche, Goddess of Luck: " << p1->getReference(0) << endl;
	cout << "Athena, Goddess of Wisdom: " << p1->getReference(1) << endl;
	cout << "Kratos, God of Strength: " << p1->getReference(2) << endl << endl;

	int finalScore = 0; //placeholder for final score
	int references = 0; //placeholder for total references

	//Loop through resume to look at items and assign points
	for (int i = 0; i < 5; i++)
	{
		if (p1->getReport(i) == "Empty")
		{
			finalScore = 0;
			i = 5; //break loop, didn't meet requirements
		}

		else if (p1->getReport(i) == "Weak report")
		{
			finalScore += 1;
		}

		else if (p1->getReport(i) == "Medium report")
		{
			finalScore += 2;
		}

		else if (p1->getReport(i) == "Strong report")
		{
			finalScore += 3;
		}

		else if (p1->getReport(i) == "Excellent report")
		{
			finalScore += 5;
		}
	}

	//Loop through references to add total
	for (int i = 0; i < 3; i++)
	{
		if (p1->getReference(i) == "Yes")
		{
			references += 1;
		}
	}
	   	  

	if (finalScore == 0) //Weak, lose
	{
		cout << "You didn't collect a report for each area so we can't consider you." << endl;
		cout << "You lose." << endl << endl;
	}

	else if (finalScore > 0 && finalScore < 15) //Medium, lose
	{
		cout << "This isn't quite what we were hoping for from you.  Maybe next time." << endl;
		cout << "Sorry, you didn't win this time." << endl << endl;
	}

	else if (finalScore > 15 && references < 2) //High, lose
	{
		cout << "Wow, you really did a great job, but we couldn't get enough good" << endl;
		cout << "references. We don't think you are ready yet." << endl << endl;
	}

	else //Win
	{
		cout << "Wow, you really did a great job and your references are great." << endl;
		cout << "A promotion is definitely in order! Congratulations! You won the game!" << endl << endl;
	}
}
