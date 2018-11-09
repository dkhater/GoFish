// EE312 - GoFish
// By: Dalia Khater and Neha Shah

#include "player.h"

Player::Player() {
    myName = "";
    //what else do you initialize?

}

void Player::addCard(Card c) {  //adds a card to the hand
    myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2){

    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);

}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    if(c1.getRank() == c2.getRank()){
        return true;
    }
    else
        return false;

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
    //how do you access the first card in the hand? then get rank and just ask
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
    int index = 0;
    int sizeHand = myHand.size();
    for(index = 0; index < sizeHand; index++){
        if(myHand[index] == c){
            myHand.erase(myHand.begin() + index);
            return c;
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
        handStr = handStr.append(myHand[i].toString());
    }
    return handStr;

}

string Player::showBooks() const{
    string bookStr = "";
    int bookHand = myBook.size();
    for(int i = 0; i < bookHand; i++){
        bookStr = bookStr.append(myBook[i].toString());
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
