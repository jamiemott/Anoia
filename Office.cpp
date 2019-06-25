/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for Office. An Office object
** represents a building where people go to do work. This class has functions
** to handle the storyline and player choices while they are in the Office area.
*****************************************************************************/


#include "Office.hpp"
#include "Menus.hpp"

#include <iostream>

using std::cout;
using std::endl;


/*Constructor. Sets all values for Office stats. Citation for constructor setup
with Space call: www.studytonight.com/cpp/order-of-constructor-call.php */
Office::Office(Player *p) : Space(p)
{
	setTop(nullptr);
	setBottom(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setAcross(nullptr);
	setName("Office");
	setPlayer(p);
}


//Destructor
Office::~Office()
{
	//Set all pointers to null to manage memory
	setPointers(nullptr, nullptr, nullptr, nullptr, nullptr);
	setPlayer(nullptr);
}


/*This function overrides the Space class function.  It handles the interaction with
the player while they are in the Office.*/
void Office::enterSpace()
{
	int action; //Placeholder for action selection choice

	cout << "You are now in an office buidling.  Please select your action: " << endl;
	
	if (player->getLevel() == 1) //Level 1 options
	{
		action = menus("Loud typing", "Microwave fish");
	}

	else if (player->getLevel() == 2) //Adding level 2 options
	{
		action = menus("Loud typing", "Microwave fish", "Burn popcorn", "Loud personal conversation");
	}

	else if (player->getLevel() == 3) //Adding level 3 options
	{
		action = menus("Loud typing", "Microwave fish", "Burn popcorn", "Loud personal conversation", "Mess in bathroom",
			"Lock out of computer");
	}

	else //Adding level 4 option
	{
		action = menus("Loud typing", "Microwave fish", "Burn popcorn", "Loud personal conversation", "Mess in bathroom",
			"Lock out of computer", "Take down the internet/network");
	}
	

	//Call proper function related to menu choice
	if (action == 1)
	{
		/*This function gives the storyline for the loud typing menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		typing();
	}

	else if (action == 2)
	{
		/*This function gives the storyline for the microwave fish menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		fish();
	}
	
	else if (action == 3)
	{
		/*This function gives the storyline for the burn popcorn menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		popcorn();
	}

	else if (action == 4)
	{
		/*This function gives the storyline for the loud conversation menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		loudConvo();
	}

	else if (action == 5)
	{
		/*This function gives the storyline for the messy bathroom menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		bathroom();
	}

	else if (action == 6)
	{
		/*This function gives the storyline for the lock computer menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		lockComputer();
	}

	else
	{
		/*This function gives the storyline for the downed internet menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		downInternet();
	}
}


/*This function gives the storyline for the loud typing menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Office::typing()
{
	//Storyline
	cout << "You use your influence to cause people around the office to type" << endl;
	cout << "much louder than normal, annoying their collegues." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Office area is: " << player->getReport(4) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(4, "Weak report");
	}
}


/*This function gives the storyline for the microwave fish menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Office::fish()
{
	//Storyline
	cout << "You hover near the break area and cause the smell of an employee's" << endl;
	cout << "reheated fish lunch to waift throughout the entire building. People" << endl;
	cout << "who can't stand teh smell of fish become greatly irritated." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Office area is: " << player->getReport(4) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(4, "Weak report");
	}
}


/*This function gives the storyline for the burn popcorn menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Office::popcorn()
{
	//Storyline
	cout << "You hover near the microwave every time someone tries to make popcorn." << endl;
	cout << "No matter how they try to microwave it, the popcorn always ends up burned." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Office area is: " << player->getReport(4) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(4, "Medium report");
	}
}


/*This function gives the storyline for the loud conversation menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Office::loudConvo()
{
	//Storyline
	cout << "You use your influence to cause an inappropirate conversation to be" << endl;
	cout << "audible throughout the office. Several people are offended by the topic." << endl;
	cout << "As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Office area is: " << player->getReport(4) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(4, "Medium report");
	}
}


/*This function gives the storyline for the messy bathroom menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Office::bathroom()
{
	//Storyline
	cout << "You use your influence to cause the janitor to forget to clean the bathroom" << endl;
	cout << "for awhile. Toilet paper runs out and messes begin to accumulate by the" << endl;
	cout << "overflowing trash cans. Employees become very frustrated as the situation" << endl;
	cout << "continues. As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Office area is: " << player->getReport(4) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(4, "Strong report");
	}
}


/*This function gives the storyline for the locked computer menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Office::lockComputer()
{
	//Storyline
	cout << "You use your influence to continually cause employees to be locked out" << endl;
	cout << "of their computers at inconvienent times and to make IT support slow" << endl;
	cout << "to respond. As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Office area is: " << player->getReport(4) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(4, "Strong report");
	}
}


/*This function gives the storyline for the downed internet menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void Office::downInternet()
{
	//Storyline
	cout << "You use every ounce of your power to cause the work intranet to go down" << endl;
	cout << "at the worst time. Employees are unable to access any of their files" << endl;
	cout << "and work comes to a standstill. The customers are so frustrated they" << endl;
	cout << "could scream. You've never inconvienienced so many people at the same" << endl;
	cout << "time. The power rush is amazing!" << endl << endl;

	int increase = rand() % 5 + 25; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Office area is: " << player->getReport(4) << endl;
	cout << "An excellent report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(4, "Excellent report");
	}
}