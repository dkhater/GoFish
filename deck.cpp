// EE312 - GoFish
// By: Dalia Khater and Neha Shah

#include "deck.h"

Deck::Deck() {
    myIndex = 0;
    int counter = 0;
    int i;
    int j;
    for (i = 0; i < 4; ++i){
        Card::Suit mySuit = (Card::Suit)i;
        for (j = 1; j < 14; ++j){
            myCards[counter] = Card(j, mySuit);
            counter++;
        }
    }

    srand((unsigned)time(0));
}

Deck::~Deck(){}

Card Deck::dealCard() {
    Card toReturn;
    if (myIndex < SIZE) {
        toReturn = myCards[myIndex];
        myIndex++;
        return toReturn;
    }
    else{
        cout << "Deck is empty!" << endl;
        myIndex = -1;
    }

    //return (Card)0;      //What do you return if you can't deal??

}

void Deck::shuffle() {
    int card1position, card2position;
    int shuffleTimes = 2 * size();
    while (shuffleTimes != 0) {

        card1position = ((rand() % size()));
        card2position = ((rand() % size()));

        Card temp = myCards[card1position];
        myCards[card1position] = myCards[card2position];
        myCards[card2position] = temp;

        shuffleTimes--;
    }
}

int Deck::size() const {
    return (SIZE - myIndex);
}

