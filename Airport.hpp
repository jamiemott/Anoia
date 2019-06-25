/******************************************************************************
** Program Name: Final Project
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for Airport. An Airport
** object represents a physical airport where people get on planes to travel.
** This class has functions to handle the storyline and player choices while
** they are in the Airport area.
*****************************************************************************/


#ifndef AIRPORT_HPP
#define AIRPORT_HPP

#include "Space.hpp"


/*Information on the "using" statement gathered from:www.ibm.com/support/knowledgecenter
/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm */
class Airport : public Space
{

public:
	Airport(Player*); //constructor
	~Airport(); //destructor
	using Space::enterSpace;
	void enterSpace(); //overrides Space class function, handles player actions
	
private:
	void slowSecurity(); //Gives storyline, awards god power points and job report
	void noCoffee(); //Gives storyline, awards god power points and job report
	void noPower(); //Gives storyline, awards god power points and job report
	void delayFlight(); //Gives storyline, awards god power points and job report
	void lostBag(); //Gives storyline, awards god power points and job report
	void cancelFlight(); //Gives storyline, awards god power points and job report
	void tornado(); //Gives storyline, awards god power points and job report	
		
};
#endif
