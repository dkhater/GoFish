// FILE: card_demo.cpp
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include <vector>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main( )
{
    cout << "Welcome to Go Fish!\n\n" << endl;

    Deck d;
    //d.shuffle();

    Card c = d.dealCard();
    cout << "deal test " << c << endl;
    cout << endl;

    Player p("Joe");
    cout << p.getName() << endl;
    p.addCard(c);
    p.addCard(d.dealCard());
    cout << p.showHand() << endl;


    int numCards = 5;

    vector <Card> cards(numCards);

    srand((unsigned)time(0));  //seed the random number generator

    for (int i = 0; i < numCards; i++) {
        int rank = (rand() % 13) + 1;
        int suit = (rand() % 4) + 1;
        Card c(rank,(Card::Suit)suit);
        cout << "rank - " << rank << "  "  << c <<  endl;
        cards[i] = c;
    }

    for (int i = 0; i < cards.size(); i++)
        cout << cards[i] << endl;

    cards.erase(cards.begin()+2);

    cout << "after" << endl;

    for (int i = 0; i < cards.size(); i++)
        cout << cards[i] << endl;

    return EXIT_SUCCESS;


}




   


