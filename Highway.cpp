/******************************************************************************
** Program Name: Final Project
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for Highway. A Highway
** represents a real highway where cars travel from place to place. This class
** has functions to handle the storyline and player choices while they are in
** the Highway area.
*****************************************************************************/


#include "Highway.hpp"
#include "Menus.hpp"

#include <iostream>

using std::cout;
using std::endl;


/*Constructor. Sets all values for Highway stats. Citation for constructor setup
with Space call: www.studytonight.com/cpp/order-of-constructor-call.php */
Highway::Highway(Player *p) : Space(p)
{
	setTop(nullptr);
	setBottom(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setAcross(nullptr);
	setName("Highway");
	setPlayer(p);
}


//Destructor
Highway::~Highway()
{
	//Set all pointers to null to manage memory
	setPointers(nullptr, nullptr, nullptr, nullptr, nullptr);
	setPlayer(nullptr);
}


/*This function overrides the Space class function.  It handles the interaction with
the player while they are in the Highway.*/
void Highway::enterSpace()
{
	int action; //Placeholder for action selection choice

	cout << "You are now on a highway.  Please select your action: " << endl;
	
	if (player->getLevel() == 1) //Level 1 options
	{
		action = menus("Ride bumper", "Cut off a car");
	}

	else if (player->getLevel() == 2) //Adding level 2 options
	{
		action = menus("Ride bumper", "Cut off a car", "Mild construction", "Flat tire");
	}

	else if (player->getLevel() == 3) //Adding level 3 options
	{
		action = menus("Ride bumper", "Cut off a car", "Mild construction", "Flat tire", "Fender bender",
			"Force to miss exit");
	}

	else //Adding level 4 option
	{
		action = menus("Ride bumper", "Cut off a car", "Mild construction", "Flat tire", "Fender bender",
			"Force to miss exit", "Major accident");
	}

	
	//Call proper function related to menu choice
	if (action == 1)
	{
		/*This function gives the storyline for the ride bumper menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		rideBumper();
	}

	else if (action == 2)
	{
		/*This function gives the storyline for the being cut off menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		cutOff();
	}

	else if (action == 3)
	{
		/*This function gives the storyline for the construction menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		construction();
	}

	else if (action == 4)
	{
		/*This function gives the storyline for the flat tire menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		flatTire();
	}

	else if (action == 5)
	{
		/*This function gives the storyline for the fender bender menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		fenderBender();
	}

	else if (action == 6)
	{
		/*This function gives the storyline for the miss the exit menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		missExit();
	}

	else
	{
		/*This function gives the storyline for the accident menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		accident();
	}
}


/*This function gives the storyline for the ride bumper menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Highway::rideBumper()
{
	//Storyline
	cout << "You use your power to have a car get right behind the bumper of another and" << endl;
	cout << "stay there, annoying both the people int the front car, for being too" << endl;
	cout << "closely followed, and those in the back car for being unable to pass." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Highway area is: " << player->getReport(1) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(1, "Weak report");
	}
}


/*This function gives the storyline for the being cut off menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Highway::cutOff()
{
	//Storyline
	cout << "You fog the vision of a driver for a moment causing them to almost miss" << endl;
	cout << "their turn. They cut across traffic, cutting off others on their way," << endl;
	cout << "hoping to not have to reroute. The cut off drivers shout and beep their" << endl;
	cout << "horns. As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Highway area is: " << player->getReport(1) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(1, "Weak report");
	}
}


/*This function gives the storyline for the construction menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Highway::construction()
{
	//Storyline
	cout << "You use your powers to place construction signs along the highway, closing" << endl;
	cout << "several lanes. Rush hour traffic comes to a standstill and people worry" << endl;
	cout << "they won't get to work on time. Tempers begin to flair." << endl;
	cout << "As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Highway area is: " << player->getReport(1) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(1, "Medium report");
	}
}


/*This function gives the storyline for the flat tire menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Highway::flatTire()
{
	//Storyline
	cout << "You use your influence to cause a car headed to the airport to get a flat" << endl;
	cout << "tire. The couple in the car begins fighting as they realize they may miss" << endl;
	cout << "their flight. As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Highway area is: " << player->getReport(1) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(1, "Medium report");
	}
}


/*This function gives the storyline for the fender bender menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Highway::fenderBender()
{
	//Storyline
	cout << "You use your power to cause a car to stop short during rush hour. Several" << endl;
	cout << "cars end up in a fender bender as a result. Tempers rise as people become" << endl;
	cout << "late for work and deal with their insurance companies." << endl;
	cout << "You can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Highway area is: " << player->getReport(1) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(1, "Strong report");
	}
}


/*This function gives the storyline for the miss the exit menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Highway::missExit()
{
	//Storyline
	cout << "You use your influence to cause some branches to blow in front of an important" << endl;
	cout << "traffic sign. As a result, several vehicles end up going down the wrong road." << endl;
	cout << "Correcting their navigation adds a lot of extra time to their journeys." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Highway area is: " << player->getReport(1) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(1, "Strong report");
	}
}


/*This function gives the storyline for the accident menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Highway::accident()
{
	//Storyline
	cout << "You use every ounce of your power to cause a truck to tip over and block" << endl;
	cout << "all lanes of traffic. The backup stretches for miles with no option to exit" << endl;
	cout << "the highway or do anything but wait. You've never annoyed so many people at" << endl;
	cout << "the same time. The power rush is amazing!" << endl << endl;

	int increase = rand() % 5 + 25; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Highway area is: " << player->getReport(1) << endl;
	cout << "An excellent report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(1, "Excellent report");
	}
}