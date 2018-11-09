// FILE: card_demo.cpp
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include <fstream>
#include <vector>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

int main() {

    ofstream myfile;
    //myfile.open(argv[1]);
    myfile.open("output.txt");

    if (myfile.is_open()) {
        cout << "File is Opened!\n";


        myfile << "Welcome to Go Fish!\n\n";

        int numCards = 7;

        Player p1("Joey");
        Player p2("Nancy");

        Deck d;  //create a deck of cards
        d.shuffle();

        dealHand(d, p1, numCards);
        dealHand(d, p2, numCards);

        myfile << p1.getName() << " has initial hand: " << p1.showHand() << "\n";
        myfile << p2.getName() << " has initial hand: " << p2.showHand() << "\n";

        Card card1toBook, card2toBook;
        if (p1.checkHandForBook(card1toBook, card2toBook)) {
            p1.firstBookCards(card1toBook, card2toBook);
        }
        if (p1.checkHandForBook(card1toBook, card2toBook)) {
            p1.firstBookCards(card1toBook, card2toBook);
        }
        if (p1.checkHandForBook(card1toBook, card2toBook)) {
            p1.firstBookCards(card1toBook, card2toBook);
        }
        if (p2.checkHandForBook(card1toBook, card2toBook)) {
            p2.firstBookCards(card1toBook, card2toBook);
        }
        if (p2.checkHandForBook(card1toBook, card2toBook)) {
            p2.firstBookCards(card1toBook, card2toBook);
        }
        if (p2.checkHandForBook(card1toBook, card2toBook)) {
            p2.firstBookCards(card1toBook, card2toBook);
        }

        myfile << "\n";
        myfile << p1.getName() << " has initial Books: " << p1.showBooks() << "\n";
        myfile << p2.getName() << " has initial Books: " << p2.showBooks() << "\n" << "\n" << "\n";


        Player &current = p1;
        Player &opposite = p2;

        string response;
        bool answer;
        bool turn = true;

        while ((current.getBookSize() + opposite.getBookSize()) < 52) {
            //myfile << "Deck size is:" << d.size() << "\n";

            if (turn) {
                current = current;
                opposite = opposite;
            } else {
                Player temp;
                temp = current;
                current = opposite;
                opposite = temp;
            }


            if (current.getHandSize() < 1) {
                current.addCard(d.dealCard());
            }

            Card cardAsk = current.chooseCardFromHand();
            myfile << current.getName() << " asks - Do you have a " << cardAsk.rankString() << "?" << "\n";

            answer = opposite.rankInHand(cardAsk);
            if (answer) {
                myfile << opposite.getName() << " says - Yes. I have a " << cardAsk.rankString() << "." << "\n";
                Card cardTake = opposite.removeCardFromHand(cardAsk);
                current.addCard(cardTake);

                myfile << endl;
                myfile << current.getName() << " has : " << current.showHand() << "\n";
                myfile << opposite.getName() << " has : " << opposite.showHand() << "\n";

                if (current.checkHandForBook(card1toBook, card2toBook)) {
                    current.bookCards(cardAsk, cardTake);
                    //myfile << current.getName() << " books " << card1toBook.toString() << " and "
                         //<< card2toBook.toString() << "\n";
                }

                myfile << current.getName() << " has : " << current.showHand() << "\n";
                myfile << opposite.getName() << " has : " << opposite.showHand() << "\n";
                myfile << "\n";
               // myfile << current.getName() << " has Books: " << current.showBooks() << "\n";
              //  myfile << opposite.getName() << " has Books: " << opposite.showBooks() << "\n";


            } else {
                response = "Go Fish!\n";
                myfile << opposite.getName() << " says - " << response << "\n";
                turn = !turn;
                Card drawCard = d.dealCard();
                myfile << current.getName() << " draws " << drawCard.toString() << "\n";
                current.addCard(d.dealCard());

                if (current.checkHandForBook(card1toBook, card2toBook)) {
                    myfile << "\n";
                    myfile << current.getName() << " has : " << current.showHand() << "\n";
                    myfile << opposite.getName() << " has : " << opposite.showHand() << "\n";
                    current.bookCards(card1toBook, card2toBook);
                    //myfile << current.getName() << " books " << card1toBook.toString() << " and "
                         //<< card2toBook.toString() << "\n";
                    myfile << "\n";
                    myfile << current.getName() << " has : " << current.showHand() << "\n";
                    myfile << opposite.getName() << " has : " << opposite.showHand() << "\n";
                }
            }
        }

        myfile << "\n";
        myfile << current.getName() << " has Final Books: " << current.showBooks() << "\n";
        myfile << opposite.getName() << " has Final Books: " << opposite.showBooks() << "\n";

        if (current.getBookSize() > opposite.getBookSize()) {
            myfile << current.getName() << " won!" << "\n";
        } else if (current.getBookSize() < opposite.getBookSize())
            myfile << opposite.getName() << " won!" << "\n";
        else
            myfile << "It is a tie!" << "\n";

        myfile.close();
        return EXIT_SUCCESS;
    }

    else {
        cout << "Unable to Open File";
    }

    return 0;

}




   


