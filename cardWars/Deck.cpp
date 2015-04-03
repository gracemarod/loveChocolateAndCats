/* 
 * File:   Deck.cpp
 * Author: R. Arce-Nazario
 * 
 * Created on March 5, 2012, 10:50 PM
 * 
 * Implementation for the functions of the Deck class.
 */

/*Cambios: 
 Extra credit: make a file Card 
*/

 //************************************************************
// Deck.cpp
// ------------------------
// Grace M. Rodriguez, December 4, 2014.
// 
//************************************************************

 /*-- Deck.cpp ---------------------------------------------------------------
 
  This file implements Deck member functions.

-------------------------------------------------------------------------*/

#include "Deck.h"

Deck::Deck() {

    for (int i = 0; i< SIZE; i++){
        Card c;
        //We create a new object of card, so we can set the values of the vector 
        //that we're going to create.
        c.setValue(i);
        push_back(c); 
    }

}

//We need to feed the shuffle function. This function has been taken as reference from the site
// cplusplus.com
int myrandom (int i) { 
    srand(time(0));
    return rand()%i;
}


void Deck::shuffle() {
    // luckily the algorithm library includes a simple way of 
    // randomly permuting the contents of the vector

   random_shuffle(begin(), end(), myrandom);

}


void Deck::deal(Player& P1, Player& P2){

    for (int i = 0; i < SIZE/2; i++) {
        P1.push_back((*this)[i]);
        }

    for(int i = SIZE/2 ; i < SIZE; i++){
        P2.push_back((*this)[i]);
        }     

 }










