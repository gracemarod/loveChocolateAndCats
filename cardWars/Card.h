
//************************************************************
// Card.h
// ------------------------
// Grace M. Rodriguez, December 4, 2014.
// 
//************************************************************

/*-- Card.h ---------------------------------------------------------------
 
  This header files defines the new object of Card, that is going to get 
  the value from the class Deck and make the card.
-------------------------------------------------------------------------*/

#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Card {
	protected:
		int value;

	public:
		 /******** Function Members ********/
 		/***** Class constructor *****/
		Card();

  	 /* ----------------------------------------------------------------------
		This is going to recieve the value of the vector Deck and returns a 
		string of the rank of the card depending on the value it gets.
		Parameters: The values from the class Deck.
		Returns: The cards's rank (2,3...J, Q...)
     -----------------------------------------------------------------------*/
		string asRank(int value);

  	 /* ----------------------------------------------------------------------
		Also recieves the value from Deck and returns the Suit of the card as
		a string.
		Parameters: The values from the class Deck.
		Returns: The cards's suit.
     -----------------------------------------------------------------------*/
        string asSuit(int value);

  	 /* ----------------------------------------------------------------------
		This set the values that are going to have the cards. 
		Parameters: The values obtained from the vector created in Deck.
		Returns: nothing
     -----------------------------------------------------------------------*/
        void setValue(int va);

  	 /* ----------------------------------------------------------------------
		Returns the value of the card and converts it into the rank. 
		Parameters: none
		Returns: The rank of the card as a string
     -----------------------------------------------------------------------*/
		string getRank();

	/* ----------------------------------------------------------------------
		Returns the value of the card.
		Parameters: none 
		Returns: The value of the card as an int.
     -----------------------------------------------------------------------*/
		int getValue()const;

	/* ----------------------------------------------------------------------
		Returns the value of the card and converts it into the suit. 
		Parameters: none
		Returns: The suit of the card as a string
     -----------------------------------------------------------------------*/
		string getSuit();

};

// Some string definitions for the suits
const char heart[]   = "\u2665";
const char spade[]   = "\u2660";
const char diamond[] = "\u2666";
const char club[]    = "\u2663";

#endif   /* CARD_H */