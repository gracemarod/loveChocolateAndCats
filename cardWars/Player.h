//************************************************************
// Player.h
// ------------------------
// Grace M. Rodriguez, December 4, 2014.
// 
//************************************************************

/*-- Player.h ---------------------------------------------------------------
 Makes a new data type of player, which is going to be a deque of card
-------------------------------------------------------------------------*/
#ifndef PLAYER_H
#define PLAYER_H
#include <deque>
#include "Card.h"
#include <iostream>

using namespace std;

class Player : public deque <Card> {	

	public: 

	/******** Function Members ********/

	/* ----------------------------------------------------------------------
		In this function, a new card called temp is going to be created which
		is the card that the player is going to draw to the gameboard and
		delete.
		Parameters: none
		Returns: none
     -----------------------------------------------------------------------*/
		Card draw();

	/* ----------------------------------------------------------------------
		When the players wina  round, it takes the cards that are in the 
		boardgame back to his hand, which in this case a deque.

		Parameters: The cards the players are going to take if they won.
		Returns: 
     -----------------------------------------------------------------------*/
		void take(Card& T);

};
#endif 
