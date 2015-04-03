/* 
 * File:   Main.cpp
 * Author: R. Arce-Nazario
 * 
 * Created on March 5, 2012, 10:50 PM
 * 
 * Client for testing the Deck class.
 */

//************************************************************
// warMain.cpp
// ------------------------
// Grace M. Rodriguez, December 4, 2014.
// 
//************************************************************

/*-- warMain.cpp ---------------------------------------------------------------
 
  File with main client.

-------------------------------------------------------------------------*/

#include "Deck.h"
#include "Player.h"
#include "Card.h"
#include <iomanip>

const int cardSize = 3;

void playWar(Player& , Player& );

int main() {
    Player player1, player2;

    Deck d;

    cout << "Here's your deck"<<endl;
  
   //An iterator is created so it can go through deque of cards and display the deck
    vector<Card>::iterator it;
    it = d.begin();

    while (it!=d.end()){

        cout << it->getRank() << it->getSuit() << " ";
        it++;
    }

    cout << endl<<endl;

    //shuffle function is called so it shuffles the deck
    d.shuffle();

     cout << endl;

    d.deal(player1, player2);

    playWar(player1, player2);

    return 0;
}

/* ----------------------------------------------------------------------
    This fucntion creates a new deque of cards, which is where the players
    are going to throw the cards. It also creates two new cards, which are
    going to be played in the gameboard.     
    Parameters: Players 1 and 2 with their deck
    Returns: none
-----------------------------------------------------------------------*/

 void playWar(Player& p1, Player& p2 ){
    deque <Card> boardGame;
    Card card1, card2;
    int count =0;

    cout << "Let the games begin! ";
    cout << "Player 1 has " << p1.size() << " cards. ";
    cout << setw(17)<< "Player 2 has " << p2.size() << " cards. " << endl ;
    cout << "Press enter to begin. " << endl;
    cin.get();

    while (p1.size()!=0 && p2.size()!= 0){         


    card1 = p1.draw(); 
    card2 = p2.draw();

    boardGame.push_back(card1);
    boardGame.push_back(card2);

    cout << "Player 1 card is: " << card1.getRank() << card1.getSuit() << "       " ;
    cout << "Player 2 card is: " << card2.getRank() << card2.getSuit() << endl;

    //Case if the value of card 1 is bigger than the card of player 2.
    if (card1.getValue() > card2.getValue()){
      cout << "The winner is player 1! " ;

        for (int i = boardGame.size(); i > 0; i--){
            p1.take(boardGame[i]);
            boardGame.pop_back(); 
        }
    }   

    //Case if the value of card 1 is less than the card of player 2.
    else if(card1.getValue() < card2.getValue()){
        cout << "The winner is player 2! ";
            for (int i = boardGame.size(); i > 0; i--){
                p2.take(boardGame[i]);
                boardGame.pop_back();  
            }
    }

    //Case if the value of card 1 is equal to the card of player 2.
     else if ((card1.getValue() == card2.getValue())){
         cout << "Both are equal. Play war!     ";
         int cardsThrown = 0;
        
        //if the player has less than 4 cards, cancel

            while (cardsThrown < 3){
                for (int e = cardSize; (e > 0)  && (p1.size() != 0) && (p2.size() != 0) ; e--){
                    boardGame.push_back(p1.draw());
                    boardGame.push_back(p2.draw());
                    cout << "The cards are: " << boardGame[e].getRank() << boardGame[e].getSuit() << endl;
                }        
                cardsThrown = cardsThrown + 1;

             }    
                boardGame.push_back(card1);
                boardGame.push_back(card2);  

               if(card1.getValue() > card2.getValue()){
                    cout << "Player 1 wins. " ;
                        for (int i = boardGame.size(); i > 0; i--){
                            p1.take(boardGame[i]);
                            boardGame.pop_back(); 
                        }
                }
                else {
                    cout << "Player 2 wins. ";
                    for (int i = boardGame.size(); i > 0; i--){
                        p2.take(boardGame[i]);
                        boardGame.pop_back();  
                    }
                }
                boardGame.erase(boardGame.begin(), boardGame.end());

    }

    else 
        cout << "Invalid movement. " << endl;  
       
        cout <<setw(17)<< "Cards Total = " << "P1: " << p1.size() << " / P2: " << p2.size() << endl << endl; 

        count = count +1;
        }

        cout << "The amount of turns was " << count <<"."<< endl << endl;
        if (p1.size() == 0 ){
            cout << "Player 2 is the final winner." << endl;
        }
        else
            cout << " Player 1 is the final winner." << endl; 
}


