//
// Created by Dalia Khater on 11/5/18.
//

#ifndef GOFISH_PLAYER_H
#define GOFISH_PLAYER_H

#endif //GOFISH_PLAYER_H


// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#include "card.h"
using namespace std;


class Player
{
public:
    Player();
    ~Player();

    Player(string name) {
        myName = name;
    }

    string getName() const {
        return myName;
    }

    void addCard(Card c);  //adds a card to the hand
    void bookCards(Card c1, Card c2);

    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const;

    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const;

    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    string showHand() const;
    string showBooks() const;

    int getHandSize() const;
    int getBookSize() const;



private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};


#endif