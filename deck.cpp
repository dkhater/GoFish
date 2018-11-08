// EE312 - GoFish
// By: Dalia Khater and Neha Shah

#include "deck.h"

Deck::Deck() {
    myIndex = SIZE;
    int i;
    int j;
    for (i = 0; i < 4; ++i){
        for (j = 1; j < 14; ++j){
            Card::Suit mySuit = (Card::Suit)i;
            myCards[i * 13 + j] = Card(j, mySuit);
        }
    }

    srand((unsigned)time(0));
}

Deck::~Deck(){}

Card Deck::dealCard() {
    if (myIndex>-1) {
        myIndex -= 1;
        return myCards[52 - myIndex - 1];
    }
}

void Deck::shuffle() {
    int card1position, card2position;
    int shuffleTimes = 2 * SIZE;            //THIS WORKS WITH FULL DECK
    while (shuffleTimes != 0) {

        card1position = (rand() % SIZE);
        card2position = (rand() % SIZE);

        Card temp = myCards[card1position];
        myCards[card2position] = myCards[card1position];
        myCards[card1position] = temp;
    }
}

int Deck::size() const {
    return myIndex;
}

