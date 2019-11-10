/******************************************************************************
** Program Name: Final Project
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for House. A House object
** represents a house where people live. This class has functions to handle
** the storyline and player choices while they are in the House area.
*****************************************************************************/


#include "House.hpp"
#include "Menus.hpp"

#include <iostream>

using std::cout;
using std::endl;


/*Constructor. Sets all values for House stats. Citation for constructor setup
with Space call: www.studytonight.com/cpp/order-of-constructor-call.php */
House::House(Player *p) : Space(p)
{
	setTop(nullptr);
	setBottom(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setAcross(nullptr);
	setName("House");
	setPlayer(p);
}


//Destructor
House::~House()
{
	//Set all pointers to null to manage memory
	setPointers(nullptr, nullptr, nullptr, nullptr, nullptr);
	setPlayer(nullptr);
}


/*This function overrides the Space class function.  It handles the interaction with
the player while they are in the House.*/
void House::enterSpace()
{
	int action; //Placeholder for action selection choice

	cout << "You are now in a house.  Please select your action: " << endl;
	
	if (player->getLevel() == 1) //Level 1 options
	{
		action = menus("Stick item in drawer", "Hide keys");
	}

	else if (player->getLevel() == 2) //Adding level 2 options
	{
		action = menus("Stick item in drawer", "Hide keys", "Make toilet leak", "Break garage door spring");
	}

	else if (player->getLevel() == 3) //Adding level 3 options
	{
		action = menus("Stick item in drawer", "Hide keys", "Make toilet leak", "Break garage door spring", "Knock tree",
			"Constant telemarketing");
	}

	else //Adding level 4 option
	{
		action = menus("Stick item in drawer", "Hide keys", "Make toilet leak", "Break garage door spring", "Knock tree",
			"Constant telemarketing", "Break pipe");
	}


	//Call proper function related to menu choice
	if (action == 1)
	{
		/*This function gives the storyline for the item in drawer menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		itemDrawer();
	}

	else if (action == 2)
	{
		/*This function gives the storyline for the hide keys menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		hideKeys();
	}
			
	else if (action == 3)
	{	
		/*This function gives the storyline for the leaky toilet menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		leakyToilet();
	}

	else if (action == 4)
	{
		/*This function gives the storyline for the break garage menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		breakGarage();
	}

	else if (action == 5)
	{
		/*This function gives the storyline for the knock tree menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		knockTree();
	}
	
	else if (action == 6)
	{
		/*This function gives the storyline for the telemarketers menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		telemarketers();
	}

	else
	{
		/*This function gives the storyline for the broken pipe menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		brokenPipe();
	}
	
}


/*This function gives the storyline for the item in drawer menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void House::itemDrawer()
{
	//Storyline
	cout << "You decide to stick to a known annoyance and get a serving spoon stuck" << endl;
	cout << "in a drawer. Try as they might, the homeowners cannot open the drawer" << endl;
	cout << "in order to get what they need. As their frustration increases, you" << endl;
	cout << "can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the House area is: " << player->getReport(2) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(2, "Weak report");
	}
}


/*This function gives the storyline for the hide keys menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void House::hideKeys()
{
	//Storyline
	cout << "You get a little more creative and decide to hide the homeowners' car" << endl;
	cout << "keys where they will not be found any time soon. As work start time" << endl;
	cout << "comes and goes, they desperately search for their lost keys." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the House area is: " << player->getReport(2) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(2, "Weak report");
	}
}


/*This function gives the storyline for the leaky toilet menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void House::leakyToilet()
{
	//Storyline
	cout << "You use your influence to cause a leak in the toilet seal ring. Without" << endl;
	cout << "knowing there is a problem, the homeowners continue to flush the toilet" << endl;
	cout << "causing toliet water to start running down the basement wall. When they" << endl;
	cout << "discover the damage, the homeowners cannot believe the mess it has caused." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the House area is: " << player->getReport(2) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(2, "Medium report");
	}
}


/*This function gives the storyline for the break the garage menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void House::breakGarage()
{
	//Storyline
	cout << "You use your influence to cause the garage door spring to break, trapping" << endl;
	cout << "the homeowners' cars in the garage. Unable to get to work without a taxi," << endl;
	cout << "they vent their frustration by cursing. As their anger increases, you" << endl;
	cout << "can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the House area is: " << player->getReport(2) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(2, "Medium report");
	}
}


/*This function gives the storyline for the knocked tree menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void House::knockTree()
{
	//Storyline
	cout << "You use your influence to call in some heavy winds, which knock a tree" << endl;
	cout << "into the house as the owners are trying to leave on vacation. As they" << endl;
	cout << "stress out trying to deal with it before leaving, you can feel your" << endl;
	cout << "power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the House area is: " << player->getReport(2) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(2, "Strong report");
	}
}


/*This function gives the storyline for the telemarketers menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void House::telemarketers()
{
	//Storyline
	cout << "You add the homeowners' cell phone numbers to telemarketing lists and" << endl;
	cout << "they begin getting nonstop calls about changing their insurance plan." << endl;
	cout << "As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the House area is: " << player->getReport(2) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(2, "Strong report");
	}
}


/*This function gives the storyline for the broken pipe menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void House::brokenPipe()
{
	//Storyline
	cout << "You use every ounce of your power to cause a water pipe to burst" << endl;
	cout << "while the owners are away for a week on vacation. The water continues to" << endl;
	cout << "pour into the house until they return, ruining all their belongings." << endl;
	cout << "You've never caused so much trouble in a house before." << endl;
	cout <<	"The power rush is amazing!" << endl << endl;

	int increase = rand() % 5 + 25; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the House area is: " << player->getReport(2) << endl;
	cout << "An excellent report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(2, "Excellent report");
	}
}
