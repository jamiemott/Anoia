/******************************************************************************
** Program Name: Final Project
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for Airport. An Airport
** object represents a physical airport where people get on planes to travel.
** This class has functions to handle the storyline and player choices while
** they are in the Airport area.
*****************************************************************************/


#include "Airport.hpp"
#include "Menus.hpp"

#include <iostream>

using std::cout;
using std::endl;


/*Constructor. Sets all values for Airport stats. Citation for constructor setup
with Space call: www.studytonight.com/cpp/order-of-constructor-call.php */
Airport::Airport(Player *p) : Space(p)
{
	setTop(nullptr);
	setBottom(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setAcross(nullptr);
	setName("Airport");
	setPlayer(p);
}


//Destructor
Airport::~Airport()
{
	//Set all pointers to null to manage memory
	setPointers(nullptr, nullptr, nullptr, nullptr, nullptr);
	setPlayer(nullptr);
}


/*This function overrides the Space class function.  It handles the interaction with
the player while they are in the Airport.*/
void Airport::enterSpace()
{
	int action; //Placeholder for action selection choice

	cout << "You are now in an airport.  Please select your action: " << endl;
	
	if (player->getLevel() == 1) //Level 1 options
	{
		action = menus("Slow security", "No coffee shops open");
	}

	else if (player->getLevel() == 2) //Adding level 2 options
	{
		action = menus("Slow security", "No coffee shops open", "No power outlets", "Delayed flight");
	}

	else if (player->getLevel() == 3) //Adding level 3 options
	{
		action = menus("Slow security", "No coffee shops open", "No power outlets", "Delayed flight", "Lost bag",
			"Cancelled flight");
	}
	
	else //Adding level 4 option
	{
		action = menus("Slow security", "No coffee shops open", "No power outlets", "Delayed flight", "Lost bag",
			"Cancelled flight", "Tornado hits airport");
	}


	//Call proper function related to menu choice
	if (action == 1)
	{
		/*This function gives the storyline for the slow security menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		slowSecurity();
	}

	else if (action == 2)
	{
		/*This function gives the storyline for the no coffee menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		noCoffee();
	}

	else if (action == 3)
	{
		/*This function gives the storyline for the no power menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		noPower();
	}

	else if (action == 4)
	{
		/*This function gives the storyline for the delay flight menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		delayFlight();
	}

	else if (action == 5)
	{
		/*This function gives the storyline for the lost bag menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		lostBag();
	}

	else if (action == 6)
	{
		/*This function gives the storyline for the cancelled flight menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		cancelFlight();
	}

	else
	{
		/*This function gives the storyline for the tornado menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		tornado();
	}
}


/*This function gives the storyline for the slow security menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Airport::slowSecurity()
{
	//Storyline
	cout << "You hover near the security station and use your influence to slow things" << endl;
	cout << "down, greatly frustrating several passengers." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand()% 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Airport area is: " << player->getReport(0) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(0, "Weak report");
	}
}


/*This function gives the storyline for the no coffee menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Airport::noCoffee()
{
	//Storyline
	cout << "You hover near the restaurants and use your influence to keep the coffee" << endl;
	cout << "shops closed in the morning, forcing people to travel without caffine." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Airport area is: " << player->getReport(0) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(0, "Weak report");
	}
}


/*This function gives the storyline for the no power menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Airport::noPower()
{
	//Storyline
	cout << "You hover near the waiting areas and use your influence to shut off" << endl;
	cout << "power to all the outlets, leaving people unable to charge their devices." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Airport area is: " << player->getReport(0) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(0, "Medium report");
	}
}


/*This function gives the storyline for the delayed flight menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Airport::delayFlight()
{
	//Storyline
	cout << "You use your influence to cause the airplane pilot to run late." << endl;
	cout << "Several people are delayed at the airport as they wait for him to arrive." << endl;
	cout << "As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Airport area is: " << player->getReport(0) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(0, "Medium report");
	}
}


/*This function gives the storyline for the lost bag menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Airport::lostBag()
{
	//Storyline
	cout << "You use your influence to cause several bags to go off course and become" << endl;
	cout << "lost. As people realize they can't find their bag, they start getting angry." << endl;
	cout << "As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Airport area is: " << player->getReport(0) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(0, "Strong report");
	}
}


/*This function gives the storyline for the cancelled flight menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Airport::cancelFlight()
{
	//Storyline
	cout << "You use your influence to cause some severe weather that causes several" << endl;
	cout << "cancelled flights. People are scrambling trying to find their way to their" << endl;
	cout << "destinations. As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Airport area is: " << player->getReport(0) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(0, "Strong report");
	}
}


/*This function gives the storyline for the tornado menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Airport::tornado()
{
	//Storyline
	cout << "You use every ounce of your power to create a tornado and direct it toward" << endl;
	cout << "the airport.  All flights are cancelled and staff and passengers have to" << endl;
	cout << "evacuate the airport. You've never inconvienienced so many people at" << endl;
	cout << "the same time. The power rush is amazing!" << endl << endl;

	int increase = rand() % 5 + 25; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Airport area is: " << player->getReport(0) << endl;
	cout << "An excellent report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(0, "Excellent report");
	}
}