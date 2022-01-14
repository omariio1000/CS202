#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "card.h"
#include "player.h"
#include "files.h"

using namespace std;

int main() {
    string input;
    files fileReader;
    vector<card*> myCards;
    vector<card*>::iterator v;

    //cout << endl << "What is the name of your file?" << endl;
    //getline(cin, input);
    //cin.clear();
    //int cards = fileReader.readFile(input, myCards);

    int cards= fileReader.readFile("deck1.txt", myCards);

    deck myDeck; 

    if (cards != 0) {
        myDeck.addCards(myCards);
        cout << endl << cards << " cards added to the deck." << endl;
    }
    else {
        cout << endl << "This file is incompatible." << endl;
        return 0;
    }

    cout << endl << "Would you like to view the deck? (y/n) ";
    char yesno;
    cin >> yesno;
    cin.clear();
    cin.ignore(100, '\n');
    if (yesno == 'y') {
        for (v = myCards.begin(); v != myCards.end(); v++) {
            int type = (*v) -> getType();

            if (type == 1) dynamic_cast<attack*> (*v) -> display();
            else if (type == 2) dynamic_cast<spell*> (*v) -> display();
            else if (type == 3) dynamic_cast<defence*> (*v) -> display();
        }
        cout << endl;
    }
    myDeck.shuffle();

    char * player1Name = new char[100];
    char * player2Name = new char[100];
    cout << endl << "What is the first player's name? ";
    cin.get(player1Name, 100);
    cin.clear();
    cin.ignore(100, '\n');
    player player1(player1Name);
    delete player1Name;
    player1Name = nullptr;

    cout << endl << "What is the second player's name? ";
    cin.get(player2Name, 100);
    cin.clear();
    cin.ignore(100, '\n');
    player player2(player2Name);
    delete player2Name;
    player2Name = nullptr;

    player players[2] = {player1, player2};

    bool playing = true;
    int currentPlayer = 0;
    while (playing) {
        break; 
    }


    return 0;
}
