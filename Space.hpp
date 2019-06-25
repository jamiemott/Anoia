/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for Space. A Space object
** represents a location that will be used in the Final Project for the player
** to interact with. Space is an abstract class that will be overridden by its 
** derived classes.  It has getters and setters for all parameters.
*****************************************************************************/


#ifndef SPACE_HPP
#define SPACE_HPP

#include "Player.hpp"

#include <string>

using std::string;


/*Information on the "virtual" statement gathered from:www.ibm.com/support/knowledgecenter
/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm
Information on virtual destructor from: www.geeksforgeeks.org/virtual-destructor */
class Space
{
protected:
	Space *top; //Pointer to Space above
	Space *bottom; //Pointer to Space below
	Space *left; //Pointer to Space to the left
	Space *right; //Pointer to Space to the right
	Space *across; //Pointer across cube design
	string name; //Name of the Space
	Player *player; //Pointer to the player to keep track for interactions
	

public:
	Space(Player*); //constructor
	virtual ~Space(); //virtual destructor required
	void setTop(Space*); //sets pointer to top
	void setBottom(Space*); //sets pointer to bottom
	void setLeft(Space*); //sets pointer to left
	void setRight(Space*); //sets pointer to right
	void setAcross(Space*); //sets pointer across from current
	void setName(string); //sets Space name
	void setPlayer(Player*); //set pointer to the player passed
	Space* getTop();// returns pointer to the top
	Space* getBottom();// returns pointer to the bottom
	Space* getLeft();// returns pointer to the left
	Space* getRight();// returns pointer to the right
	Space* getAcross();// returns pointer across from current
	string getName(); //returns Space name
	Player* getPlayer(); //returns pointer to the player
	void setPointers(Space*, Space*, Space*, Space*, Space*); //Sets all pointers in one go
	virtual void enterSpace() = 0; //Virtual, will be overriden by derived classes
};
#endif
