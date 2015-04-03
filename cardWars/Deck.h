/* 
 * File:   Deck.h
 * Author: R Arce-Nazario
 *
 * Created on March 5, 2012, 10:50 PM
 * 
 * Declaration of class Deck.
 */

//************************************************************
// Deck.h
// ------------------------
// Grace M. Rodriguez, December 4, 2014.
// 
//************************************************************

/*-- Deck.h ---------------------------------------------------------------
 
  This header file defines the data type Deck that is a vector of Cards. 

-------------------------------------------------------------------------*/
#ifndef DECK_H
#define	DECK_H
#include <algorithm>
#include <iostream> 
#include <vector> 
#include <sstream> 
#include <cstdlib>
#include <ctime>
#include <string>
#include "Card.h"
#include "Player.h"

using namespace std;

// Deck is a child class of vector<int>, so it 
// will inherit all its cool functions.
const int SIZE = 52;

//vectorde cartas envez de int 
//inicializar cartas en el constructor

class Deck : public vector <Card> {

public:
	/******** Function Members ********/
 	/***** Class constructor *****/
    Deck();
    
     /* ----------------------------------------------------------------------
		Shuffles the vector.
		Parameters: none
		Returns: none
     -----------------------------------------------------------------------*/
    void shuffle();
    
     /* ----------------------------------------------------------------------
		Divide the deck in half, and deal each half to each player.
		Parameters: Player 1 and player 2, which are a deque of cards
		Returns: none
     -----------------------------------------------------------------------*/
    void deal(Player& P1, Player& P2);

};

#endif	/* DECK_H */

