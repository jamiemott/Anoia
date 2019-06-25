/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class implementation file for Space. A Space object
** represents a location that will be used in the Final Project for the player
** to interact with. Space is an abstract class that will be overridden by its 
** derived classes.  It has getters and setters for all parameters.
*****************************************************************************/


#include "Space.hpp"


//Space constructor. Sets space pointers to null and the player pointer to the passed parameter. 
Space::Space(Player *p)
{
	setTop(nullptr);
	setBottom(nullptr);
	setLeft(nullptr);
	setRight(nullptr);
	setAcross(nullptr);
	setName("");
	setPlayer(p);
}


//Information on virtual destructor from: www.geeksforgeeks.org/virtual-destructor
Space::~Space()
{
	//Set all pointers to null to manage memory
	setPointers(nullptr, nullptr, nullptr, nullptr, nullptr);
	setPlayer(nullptr);
}


/*Virtual enterSpace() was defined in specification file*/


//Sets the top pointer to the passed parameter
void Space::setTop(Space *ptr)
{
	top = ptr;
}


//Sets the bottom pointer to the passed parameter
void Space::setBottom(Space *ptr)
{
	bottom = ptr;
}


//Sets the left pointer to the passed parameter
void Space::setLeft(Space *ptr)
{
	left = ptr;
}


//Sets the right pointer to the passed parameter
void Space::setRight(Space *ptr)
{
	right = ptr;
}


//Sets the across pointer to the passed parameter
void Space::setAcross(Space *ptr)
{
	across = ptr;
}


//Sets the name of space to the passed parameter
void Space::setName(string n)
{
	name = n;
}


//Sets the player pointer to the passed parameter
void Space::setPlayer(Player *p)
{
	player = p;
}


//Gets the top pointer
Space* Space::getTop()
{
	return top;
}


//Gets the bottom pointer
Space* Space::getBottom()
{
	return bottom;
}


//Gets the left pointer
Space* Space::getLeft()
{
	return left;
}


//Gets the right pointer
Space* Space::getRight()
{
	return right;
}


//Gets the across pointer
Space* Space::getAcross()
{
	return across;
}


//Gets the name of space
string Space::getName()
{
	return name;
}


//Gets the player pointer
Player* Space::getPlayer()
{
	return player;
}


//Sets all the pointers for the Space object in one pass to the parameters passed
void Space::setPointers(Space *n, Space *e, Space *s, Space *w, Space *a)
{
	setTop(n);
	setRight(e);
	setBottom(s);
	setLeft(w);
	setAcross(a);
}