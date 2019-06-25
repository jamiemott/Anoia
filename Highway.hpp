/******************************************************************************
** Program Name: Final Project
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for Highway. A Highway
** represents a real highway where cars travel from place to place. This class
** has functions to handle the storyline and player choices while they are in
** the Highway area.
*****************************************************************************/


#ifndef HIGHWAY_HPP
#define HIGHWAY_HPP

#include "Space.hpp"


/*Information on the "using" statement gathered from:www.ibm.com/support/knowledgecenter
/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm */
class Highway : public Space
{

public:
	Highway(Player*); //constructor
	~Highway(); //destructor
	using Space::enterSpace;
	void enterSpace(); //overrides Space class function, handles player actions

private:
	void rideBumper(); //Gives storyline, awards god power points and job report
	void cutOff(); //Gives storyline, awards god power points and job report
	void construction(); //Gives storyline, awards god power points and job report
	void flatTire(); //Gives storyline, awards god power points and job report
	void fenderBender(); //Gives storyline, awards god power points and job report
	void missExit(); //Gives storyline, awards god power points and job report
	void accident(); //Gives storyline, awards god power points and job report	
		
};
#endif
