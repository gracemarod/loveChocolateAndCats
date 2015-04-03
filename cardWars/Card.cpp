//************************************************************
// Card.cpp
// ------------------------
// Grace M. Rodriguez, December 4, 2014.
// 
//************************************************************

/*-- Card.cpp------------------------------------------------------------
 
   This file implements Card member functions.
  
-------------------------------------------------------------------------*/

#include "Card.h"

Card::Card(){
// Value equals to -1 as default, becouse if a -1 appears, then we can know something is wrong
	value = -1;
}

void Card::setValue(int va){
	value = va;
}

string Card::getRank(){
	return asRank(value);
}

string Card::getSuit(){
	return asSuit(value);
}

int Card::getValue()const{
    return ((value%13) + 1);
}

string Card::asRank(int value) { 

    if (value < 0 || value > 51 ) 
        cout << "Bad";
    
    stringstream ss;

    // determine the number of the card
    
    switch ((value % 13) + 1) {

        case 10: ss << "J";
            break;
        case 11: ss << "Q";
            break;
        case 12: ss << "K";
            break;
        case 13: ss << "A";
            break;
        default: ss << ((value%13) + 1);
    }
    return ss.str();
}

string Card::asSuit(int value){
    string st;

    if (value < 0 || value > 52 ) 
        cout << "Bad";
    // determine the card's suit
    
    switch (value / 13) {
        case 0:
            st += club;
            break;
        case 1:
            st += diamond;
            break;
        case 2:
            st += heart;
            break;
        case 3:
            st += spade;
            break;
    }

    return st;   
}

