/******************************************************************************
** Program Name: Final Project
** Author:		Jamie Mott
** Date :		May 27, 2019
** Description : This is the class specification file for Gods. A Gods
** object represents the home of the Gods.  This is where the player must
** go to try to get references for the job interview.
*****************************************************************************/


#ifndef GODS_HPP
#define GODS_HPP

#include "Space.hpp"


/*Information on the "using" statement gathered from:www.ibm.com/support/knowledgecenter
/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/overload_member_fn_base_derived.htm */
class Gods : public Space
{

public:
	Gods(Player*); //constructor
	~Gods(); //destructor
	using Space::enterSpace;
	void enterSpace(); //overrides Space class function

private:
	void visitTyche(); //Visits Tyche, goddess of luck
	void visitAthena(); //Visits Athena, goddess of wisdom
	void visitKratos(); //Visits Kratos, god of power
		
};
#endif
