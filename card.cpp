// EE312 - GoFish
// By: Dalia Khater and Neha Shah

#include "card.h"
#include <string>
#include <iostream>
#include <sstream>

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

    str = rankString(getRank());

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
    else{
        str += "invalid suit";
        cout << "Error in detecting suit! suit is: ";
        cout << mySuit << endl;
    }

    return str;

}

string Card::rankString() const {
    string str = "";
    str = rankString(getRank());
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
    else{
        str += "invalid suit";
        cout << "Error in detecting suit!";
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
    string strRank = "";

    ostringstream convert;
    convert << r;

    if(r > 1 && r < 11){
        strRank = convert.str();
    }
    else if (r == 1){
        strRank = "A";
    }
    else if (r == 11){
        strRank = "J";
    }
    else if (r == 12){
        strRank = "Q";
    }
    else if (r == 13){
        strRank = "K";
    }
    else{
        cout << "did not find correct rank! you have r = " << r << "!" << endl;
        strRank = "invalid rank!";
    }
    return strRank;
}


ostream& operator << (ostream& out, const Card& c){
    cout << c.toString();
    return out;

}


Card::~Card(){

}













