/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for MovieTheater. A MovieTheater 
** object represents a place where people go to watch movies. This class has
** functions to handle the storyline and player choices while they are in the
** MovieTheater area.
*****************************************************************************/


#ifndef MOVIETHEATER_HPP
#define MOVIETHEATER_HPP

#include "Space.hpp"


/*Information on the "using" statement gathered from:www.ibm.com/support/knowledgecenter
/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm */
class MovieTheater : public Space
{

public:
	MovieTheater(Player*); //constructor
	~MovieTheater(); //destructor
	using Space::enterSpace;
	void enterSpace(); //overrides Space class function, handles player actions

private:
	void chewing(); //Gives storyline, awards god power points and job report
	void playAds(); //Gives storyline, awards god power points and job report
	void stickySeat(); //Gives storyline, awards god power points and job report
	void cellPhone(); //Gives storyline, awards god power points and job report
	void shoutScreen(); //Gives storyline, awards god power points and job report
	void spillDrink(); //Gives storyline, awards god power points and job report
	void breakMovie(); //Gives storyline, awards god power points and job report

};
#endif
