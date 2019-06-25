/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for House. A House object
** represents a house where people live. This class has functions to handle
** the storyline and player choices while they are in the House area.
*****************************************************************************/


#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "Space.hpp"


/*Information on the "using" statement gathered from:www.ibm.com/support/knowledgecenter
/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm */
class House : public Space
{

public:
	House(Player*); //constructor
	~House(); //destructor
	using Space::enterSpace;
	void enterSpace(); //overrides Space class function, handles player actions

private:
	void itemDrawer(); //Gives storyline, awards god power points and job report
	void hideKeys(); //Gives storyline, awards god power points and job report
	void leakyToilet(); //Gives storyline, awards god power points and job report
	void breakGarage(); //Gives storyline, awards god power points and job report
	void knockTree(); //Gives storyline, awards god power points and job report
	void telemarketers(); //Gives storyline, awards god power points and job report
	void brokenPipe(); //Gives storyline, awards god power points and job report

};
#endif
