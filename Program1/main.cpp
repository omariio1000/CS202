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

void switchPlayer(int & current, int & other);

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
        for (v = myCards.begin(); v != myCards.end(); v++) (*v) -> display(); 
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

    //players[0].display();
    //players[1].display();

    bool playing = true;
    int currentPlayer = 0;
    int otherPlayer = 1;
    while (playing) {
        cout << endl << "Current Player: ";
        players[currentPlayer].display();
        cout << endl << "What would you like to do?" << endl;
        cout << "1: Draw a Card" << endl;
        cout << "2: Use a Card" << endl;
        cout << "3: Hibernate (Regenerate 1 Energy)" << endl;
        cout << "4: Display Information Again (Doesn't End Turn)" << endl;
        cout << "5: Skip Turn" << endl;
        cout << "6: Vote to End Game" << endl;
        int answer = 0;

        cin >> answer;
        cin.clear();
        cin.ignore(100, '\n');

        if (answer == 1) {//draw a card
            int err = myDeck.drawCard(players[currentPlayer]);
            if (err >= -1) {
                if (err == 0)
                    cout << endl << "Since the discard pile is empty, you must select another action." << endl;
                else {
                    cout << endl << "Drawing pile is empty! Would you like to reshuffle the discard pile? (y/n)" << endl;
                    cout << "By the way, if you don't, the game will end! " << endl;
                    cin >> yesno;
                    cin.clear();
                    cin.ignore('\n', 100);

                    if (yesno == 'y') {
                        err = myDeck.reShuffleDiscard();
                        if (err == 0)
                            cout << endl << "Actually, the discard pile is empty too. Select another action." << endl;

                        myDeck.drawCard(players[currentPlayer]);
                        switchPlayer(currentPlayer, otherPlayer);
                    }
                    else {
                        if (yesno == 'n') break;
                        else cout << endl << "Invalid Input" << endl;
                    }
                }
            }
            else switchPlayer(currentPlayer, otherPlayer);
        }

        else if (answer == 2) {//use a card
        }

        else if (answer == 3) {//hibernate
            players[currentPlayer].changeEnergy(1, true);
            switchPlayer(currentPlayer, otherPlayer);
        }

        else if (answer == 4) cout << "Too lazy to scroll up?" << endl; //display again


        else if (answer == 5) {//skip turn
            cout << endl << "Are you sure? You can hibernate and get 1 energy instead... (y/n)";
            cin >> yesno;
            cin.clear();
            cin.ignore('\n', 100);

            if (yesno == 'y' ) {
                cout << endl << "ok then..." << endl;
                switchPlayer(currentPlayer, otherPlayer);
            }
            else cout << "Good Choice." << endl;
        }

        else if (answer == 6) {//vote end
            cout << endl << "Are you sure you would like to end the game? (y/n) ";
            cin >> yesno;
            cin.clear();
            cin.ignore('\n', 100);

            if (yesno == 'y') {
                cout << endl; 
                players[otherPlayer].displayName();
                cout << ", would you like to end the game as well? (y/n) ";
                cin >> yesno;
                cin.clear();
                cin.ignore('\n', 100);

                if (yesno == 'y') break;
                else {
                    cout << endl << "Good Choice. ";
                    players[currentPlayer].displayName();
                    cout << " must be desperate." << endl;
                }
            }

            else cout << endl << "Good Choice." << endl;
        }

        else cout << endl << "Invalid Input." << endl;
    }


    return 0;
}

void switchPlayer(int & current, int & other) {
    int temp = current;
    current = other;
    other = temp;
}
