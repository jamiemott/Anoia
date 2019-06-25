/******************************************************************************
** Program Name: Final Project: Anoia
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for Office. An Office object
** represents a building where people go to do work. This class has functions
** to handle the storyline and player choices while they are in the Office area.
*****************************************************************************/


#ifndef OFFICE_HPP
#define OFFICE_HPP

#include "Space.hpp"


/*Information on the "using" statement gathered from:www.ibm.com/support/knowledgecenter
/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm */
class Office : public Space
{

public:
	Office(Player*); //constructor
	~Office(); //destructor
	using Space::enterSpace;
	void enterSpace(); //overrides Space class function, handles player actions

private:
	void typing(); //Gives storyline, awards god power points and job report
	void fish(); //Gives storyline, awards god power points and job report
	void popcorn(); //Gives storyline, awards god power points and job report
	void loudConvo(); //Gives storyline, awards god power points and job report
	void bathroom(); //Gives storyline, awards god power points and job report
	void lockComputer(); //Gives storyline, awards god power points and job report
	void downInternet(); //Gives storyline, awards god power points and job report

};
#endif
