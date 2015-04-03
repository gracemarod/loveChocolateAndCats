//************************************************************
// Player.h
// ------------------------
// Grace M. Rodriguez, December 4, 2014.
// 
//************************************************************

/*-- Player.cpp ---------------------------------------------------------------
 
  This file implements Player member functions.

-------------------------------------------------------------------------*/

#include "Player.h"


Card Player::draw(){
	Card temp;
	temp.setValue(back().getValue());

	pop_back();	

	return temp;

}

void Player::take(Card& T){

	push_front(T);

}
