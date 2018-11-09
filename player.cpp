// EE312 - GoFish
// By: Dalia Khater and Neha Shah

#include "player.h"

Player::Player() {
    myName = "";
    myHand.resize(0);
    myBook.resize(0);

}

void Player::addCard(Card c) {  //adds a card to the hand
    myHand.push_back(c);
}

void Player::firstBookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    int sizeHand = myHand.size();
    for(int i = 0; i < sizeHand; i++){
        if(myHand[i] == c1){
            myHand.erase(myHand.begin() + i);
        }
    }
    int sizeHand2 = myHand.size();
    for(int j = 0; j < sizeHand2; j++){
        if(myHand[j] == c2){
            myHand.erase(myHand.begin() + j);
        }
    }
}


void Player::bookCards(Card c1, Card c2){

    Card red1, red2;

    myBook.push_back(c1);
    myBook.push_back(c2);
    red1 = removeCardFromHand(c1);
    red2 = removeCardFromHand(c2);

}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){

    int sizeHand= myHand.size();
    for(int i = 0; i < sizeHand -1; i++){
        for(int j = i+1; j < sizeHand; j++){
            if(myHand[i].getRank() == myHand[j].getRank()){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
/*
    vector<Card>::const_iterator iter1;
    vector<Card>::const_iterator iter2;

    for (iter1 = myHand.begin(); iter1 != (myHand.end()-1); iter1++){
        for(iter2 = iter1 + 1; iter1 != myHand.end(); iter2++)
            if(iter1->getRank() == iter2->getRank()){
                c1 = *iter1;
                c2 = *iter2;
                return true;
            }
    }
    return false;
*/
}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{
    vector<Card>::const_iterator iter;
    for (iter = myHand.begin(); iter != myHand.end(); iter++){
        if(iter->getRank() == c.getRank()){
            return true;
        }
    }
    return false;

}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
    Card toAsk;
    srand((unsigned)time(0));
    int index;
    int sizeHand = myHand.size();
    index = (rand() % sizeHand);
    toAsk = myHand[index];
    return toAsk;

}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    vector<Card>::const_iterator iter;
    for (iter = myHand.begin(); iter != myHand.end(); iter++){
        if(*iter == c){
            return true;
        }
    }
    return false;

}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    Card removal;
    int index = 0;
    int sizeHand = myHand.size();
    for(index = 0; index < sizeHand; index++){
        if(myHand[index].getRank() == c.getRank()){
            removal = myHand[index];
            myHand.erase(myHand.begin() + index);
            return removal;
        }
    }

    /*vector<int>::iterator iter;
    for (iter = myHand.begin(); iter != myHand.end(); iter++){
        if(myHand[iter] == c)
            myHand.erase(myHand.begin() + iter);
    }
     */

}

string Player::showHand() const{
    string handStr = "";
    int sizeHand = myHand.size();
    for(int i = 0; i < sizeHand; i++){
        handStr = handStr.append(myHand[i].toString()) + " ";
    }
    return handStr;

}

string Player::showBooks() const{
    string bookStr = "";
    int bookHand = myBook.size();
    for(int i = 0; i < bookHand; i++){
        bookStr = bookStr.append(myBook[i].toString()) + " ";
    }
    return bookStr;

}

int Player::getHandSize() const{
    return (int)myHand.size();

}

int Player::getBookSize() const{
    return (int)myBook.size();

}

string Player::getName() const {
    return myName;
}


/* These are extra - seem like duplicates but not sure
//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForPair(Card &c1, Card &c2){

}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

bool Player::sameRankInHand(Card c) const{

}
 */
