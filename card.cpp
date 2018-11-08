// EE312 - GoFish
// By: Dalia Khater and Neha Shah

#include "card.h"
using namespace std;

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

Card::Card() {
    myRank = 1;
    mySuit = Suit::spades;
}


int Card::getRank() const {
    return myRank;
}

string Card::toString() const  {
    string str = "";

    if(myRank > 1 && myRank < 11){
        str = to_string(myRank);
    }
    else if (myRank == 1){
        str = "A";
    }
    else if (myRank == 11){
        str = "J";
    }
    else if (myRank == 12){
        str = "Q";
    }
    else if (myRank == 13){
        str = "K";
    }

    if (mySuit == Suit::spades) {
       str +=  "s";
    }

    else if (mySuit == Suit::hearts) {
        str +=  "h";
    }

    else if (mySuit == Suit::diamonds) {
        str +=  "d";
    }

    else if (mySuit == Suit::clubs) {
        str +=  "c";
    }

    return str;

}

string Card::suitString(Card::Suit s) const{
    string str = "";
    if (s == Suit::spades) {
       str =  "s";
    }

    else if (s == Suit::hearts) {
        str =  "h";
    }

    else if (s == Suit::diamonds) {
        str =  "d";
    }

    else if (s == Suit::clubs) {
        str =  "c";
    }

    return str;

}

bool Card::sameSuitAs(const Card& c) const{
    if(mySuit == c.mySuit)
        return true;
    else
        return false;

}

bool Card::operator == (const Card& rhs) const{
    if((this->mySuit == rhs.mySuit) && (this->myRank == rhs.myRank)){
        return true;
    }
    else
        return false;
}

bool Card::operator != (const Card& rhs) const{
    if((this->mySuit != rhs.mySuit) && (this->myRank != rhs.myRank)){
        return true;
    }
    else
        return false;

}

string Card::rankString(int r) const{

}


ostream& operator << (ostream& out, const Card& c){
    cout << c.toString();
    return out;

}


Card::~Card(){

}













