/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for Olympus. An Olympus
** object represents the home of the Gods.  This is where the player must
** go to increase their level and access more actions in the rest of the game.
*****************************************************************************/


#ifndef OLYMPUS_HPP
#define OLYMPUS_HPP

#include "Space.hpp"


/*Information on the "using" statement gathered from:www.ibm.com/support/knowledgecenter
/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm */
class Olympus : public Space
{

private:
	Space *godHome;

public:
	Olympus(Player*); //constructor
	~Olympus(); //destructor
	using Space::enterSpace;
	void enterSpace(); //overrides Space class function

private:
	void levelUp(); //Allow user to switch god levels based on power points
	void visitGods(); //Move user to space to visit gods to get job references
		
};
#endif
