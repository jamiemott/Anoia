/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for MovieTheater. A MovieTheater 
** object represents a place where people go to watch movies. This class has
** functions to handle the storyline and player choices while they are in the
** MovieTheater area.
*****************************************************************************/


#include "MovieTheater.hpp"
#include "Menus.hpp"

#include <iostream>

using std::cout;
using std::endl;


/*Constructor. Sets all values for MovieTheater stats. Citation for constructor setup
with Space call: www.studytonight.com/cpp/order-of-constructor-call.php */
MovieTheater::MovieTheater(Player *p) : Space(p)
{
	setTop(nullptr);
	setBottom(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setAcross(nullptr);
	setName("Movie Theater");
	setPlayer(p);
}


//Destructor
MovieTheater::~MovieTheater()
{
	//Set all pointers to null to manage memory
	setPointers(nullptr, nullptr, nullptr, nullptr, nullptr);
	setPlayer(nullptr);
}


/*This function overrides the Space class function.  It handles the interaction with
the player while they are in the MovieTheater.*/
void MovieTheater::enterSpace()
{
	int action; //Placeholder for action selection choice

	cout << "You are now in a movie theater.  Please select your action: " << endl;
		
	if (player->getLevel() == 1) //Level 1 options
	{
		action = menus("Chew loudly", "Play lots of ads");
	}

	else if (player->getLevel() == 2) //Adding level 2 options
	{
		action = menus("Chew loudly", "Play lots of ads", "Put sticky stuff on seat", "Use cell phone");
	}

	else if (player->getLevel() == 3) //Adding level 3 options
	{
		action = menus("Chew loudly", "Play lots of ads", "Put sticky stuff on seat", "Use cell phone",
			"Shout at characters in movie", "Spill drink on row in front");
	}

	else //Adding level 4 option
	{
		action = menus("Chew loudly", "Play lots of ads", "Put sticky stuff on seat", "Use cell phone",
			"Shout at characters in movie", "Spill drink on row in front", "Break movie projector");
	}


	//Call proper function related to menu choice
	if (action == 1)
	{
		/*This function gives the storyline for the loud chewing menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		chewing();
	}

	else if (action == 2)
	{
		/*This function gives the storyline for the play ads menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		playAds();
	}

	else if (action == 3)
	{
		/*This function gives the storyline for the sticky seat menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		stickySeat();
	}

	else if (action == 4)
	{
		/*This function gives the storyline for the cell phone menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		cellPhone();
	}

	else if (action == 5)
	{
		/*This function gives the storyline for the shout at screen menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		shoutScreen();
	}

	else if (action == 6)
	{
		/*This function gives the storyline for the spill drink menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		spillDrink();
	}

	else
	{
		/*This function gives the storyline for the break the movie menu option. The player
		gets a random amount of god power added and can choose whether or not to add the
		job report to his/her resume. */
		breakMovie();
	}
}


/*This function gives the storyline for the loud chewing menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void MovieTheater::chewing()
{
	//Storyline
	cout << "You hover behind a group of people while munching louldy on popcorn." << endl;
	cout << "You lean so far over that you are basically chewing right by their ears." << endl;
	cout << "As their frustration increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Movie Theater area is: " << player->getReport(3) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(3, "Weak report");
	}
}


/*This function gives the storyline for the play ads menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void MovieTheater::playAds()
{
	//Storyline
	cout << "You hover near the movie reel and cause it to play the movie's beginning" << endl;
	cout << "ads over and over again. People begin searching for an employee to see" << endl;
	cout << "when and if the movie will actually start. As their frustration" << endl;
	cout << "increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 1; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Movie Theater area is: " << player->getReport(3) << endl;
	cout << "A weak report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(3, "Weak report");
	}
}


/*This function gives the storyline for the sticky seat menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void MovieTheater::stickySeat()
{
	//Storyline
	cout << "You wander through the theater leaving wet, sticky candy bits on" << endl;
	cout << "several seats. People don't notice the icky mess until it is already" << endl;
	cout << "on their pants. As their frustration increases, you can feel your" << endl;
	cout << "power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Movie Theater area is: " << player->getReport(3) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(3, "Medium report");
	}
}


/*This function gives the storyline for the cell phone menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void MovieTheater::cellPhone()
{
	//Storyline
	cout << "You use your influence to cause several people's cell phones to." << endl;
	cout << "continually ring throughout the movie. As the interruptions continue" << endl;
	cout << "others in the crowd get angrier and angrier. As their anger" << endl;
	cout << "increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 10; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Movie Theater area is: " << player->getReport(3) << endl;
	cout << "A medium report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(3, "Medium report");
	}
}


/*This function gives the storyline for the shouting at screen menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void MovieTheater::shoutScreen()
{
	//Storyline
	cout << "You hover at the back of the theater and occassionally begin talking" << endl;
	cout << "loudly to the characters on the screen and guessing what will happen" << endl;
	cout << "next, ruining several important storyline moments for the crowd." << endl;
	cout << "As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Movie Theater area is: " << player->getReport(3) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(3, "Strong report");
	}
}


/*This function gives the storyline for the spilled drink menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void MovieTheater::spillDrink()
{
	//Storyline
	cout << "You use your influence to cause several people in the crowd to spill their" << endl;
	cout << "drinks over other attendees. Cushioned seats are left damp for the next" << endl;
	cout << "showing and several people have to leave the movie for awhile to go clean" << endl;
	cout << "themselves up. As their anger increases, you can feel your power increase." << endl << endl;

	int increase = rand() % 5 + 15; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Movie Theater area is: " << player->getReport(3) << endl;
	cout << "A strong report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(3, "Strong report");
	}
}


/*This function gives the storyline for the break the movie menu option. The player
gets a random amount of god power added and can choose whether or not to add the
job report to his/her resume. */
void MovieTheater::breakMovie()
{
	//Storyline
	cout << "You use every ounce of your power to break the movie projector at the" << endl;
	cout << "most important moment. You jam the electronics so well that the workers" << endl;
	cout << "cannot restart the movie and the whole crowd is told they will have to" << endl;
	cout << "return at another time. You've never inconvienienced so many people at" << endl;
	cout << "the same time. The power rush is amazing!" << endl << endl;

	int increase = rand() % 5 + 25; //To hold increase in power points

	cout << "Your power has been increased by " << increase << " point(s)." << endl;

	player->changePower(increase); //Updated points
	cout << "You now have " << player->getPower() << " power points." << endl << endl;

	//Give option to update resume
	cout << "The current report for the Movie Theater area is: " << player->getReport(3) << endl;
	cout << "An excellent report was created for this job. Would you like to add it to" << endl;
	cout << "your resume?" << endl;
	int resumeChoice = menus("Yes", "No");

	if (resumeChoice == 1) //Add report to resume
	{
		player->setResume(3, "Excellent report");
	}
}