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
using namespace colors;

void switchPlayer(int & current, int & other);

int main() {
    string input;
    files fileReader;
    vector<card*> myCards;
    vector<card*>::iterator v;

    //cout << endl << "What is the name of your file?" << endl << GREEN << ">> " << RESET;
    //getline(cin, input);
    //cin.clear();
    //cin.ignore(100, '\n');
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

    cout << endl << "Would you like to view the deck? (y/n)" << endl << GREEN << ">> " << RESET;
    char yesno;
    cin >> yesno;
    cin.clear();
    cin.ignore(100, '\n');
    if (yesno == 'y') {
        for (v = myCards.begin(); v != myCards.end(); v++) (*v) -> display(); 
        cout << endl;
    }
    myDeck.shuffle();
    //myDeck.display();

    char * player1Name = new char[100];
    char * player2Name = new char[100];
    cout << endl << "What is the first player's name?" << endl << GREEN << ">> " << RESET;
    cin.get(player1Name, 100);
    cin.clear();
    cin.ignore(100, '\n');
    player player1(player1Name);
    delete[] player1Name;
    player1Name = nullptr;

    cout << endl << "What is the second player's name?" << endl << GREEN << ">> " << RESET;
    cin.get(player2Name, 100);
    cin.clear();
    cin.ignore(100, '\n');
    player player2(player2Name);
    delete[] player2Name;
    player2Name = nullptr;

    player players[2] = {player1, player2};

    //players[0].display();
    //players[1].display();

    bool playing = true;
    int currentPlayer = 0;
    int otherPlayer = 1;
    while (playing && players[0].checkHealth() && players[1].checkHealth()) {
        cout << endl << YELLOW << "-----------------------------" << RESET << endl;
        cout << endl << "Current Player: ";
        players[currentPlayer].display();
        cout << endl << "What would you like to do?" << endl;
        cout << "1: Draw a Card" << endl;
        cout << "2: Use a Card" << endl;
        cout << "3: Hibernate (Regenerate 1 Energy)" << endl;
        cout << "4: Display Information Again (Doesn't End Turn)" << endl;
        cout << "5: Skip Turn" << endl;
        cout << "6: Vote to End Game" << endl;
        cout << GREEN << ">> " << RESET;
        int answer = 0;

        cin >> answer;
        cin.clear();
        cin.ignore(100, '\n');

        if (answer == 1) {//draw a card
            int err = myDeck.drawCard(players[currentPlayer]);
            if (err == 0) {
                cout << endl << "Drawing pile is empty! Would you like to reshuffle the discard pile? (y/n)" << endl;
                cout << "By the way, if you don't, the game will end! " << endl;
                cout << GREEN << ">> " << RESET;
                cin >> yesno;
                cin.clear();
                cin.ignore(100, '\n');

                if (yesno == 'y') {
                    err = myDeck.reShuffleDiscard();
                    if (err == 0) 
                        cout << endl << "Actually, the discard pile is empty too. Select another action." << endl;


                    else {
                        myDeck.drawCard(players[currentPlayer]);
                        switchPlayer(currentPlayer, otherPlayer);
                    }
                }
                else {
                    if (yesno == 'n') playing = false;
                    else cout << endl << "Invalid Input" << endl;
                }
            }

            else switchPlayer(currentPlayer, otherPlayer);
        }

        else if (answer == 2) {//use a card
            cout << endl << "What card would you like to play?" << endl;
            cout << GREEN << ">> " << RESET;
            char * cardName = new char[100];
            cin.get(cardName, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Which player would you like to affect? (Please don't heal your opponent)" << endl;
            cout << CYAN << "1: ";
            players[currentPlayer].displayName();
            cout << RESET << endl << "2: ";
            players[otherPlayer].displayName();
            cout << endl << GREEN <<">> " << RESET;

            cin >> answer;
            cin.clear();
            cin.ignore(100, '\n');

            int err = 999;

            if (answer == 1) err = players[currentPlayer].useCard(cardName, players[currentPlayer], myDeck, currentPlayer);
            else if (answer == 2) err = players[currentPlayer].useCard(cardName, players[otherPlayer], myDeck, currentPlayer);
            else cout << endl << "Invalid Input!" << endl;

            //cout << endl << "error code: " << err << endl;
            if (err != (999)) {
                if (err == -3) cout << endl << "You don't have a card with that name!" << endl;
                else if (err == -2) cout << endl << "You have to actually input a name..." << endl;
                else if (err == -1) cout << endl << "Unknown error. Your deck is broken lol" << endl;
                else if (err == 0) cout << endl << "You don't have enough energy to use this card!" << endl;
                else switchPlayer(currentPlayer, otherPlayer);
            }
            delete[] cardName;
        }


        else if (answer == 3) {//hibernate
            players[currentPlayer].changeEnergy(1, true);
            switchPlayer(currentPlayer, otherPlayer);
        }

        else if (answer == 4) cout << endl << "Too lazy to scroll up?" << endl; //display again


        else if (answer == 5) {//skip turn
            cout << endl << "Are you sure? You can hibernate and get 1 energy instead... (y/n) ";
            cout << endl << GREEN << ">> " << RESET;
            cin >> yesno;
            cin.clear();
            cin.ignore(100, '\n');

            if (yesno == 'y' ) {
                cout << endl << YELLOW << "ok then..." << RESET << endl;
                switchPlayer(currentPlayer, otherPlayer);
            }
            else cout << "Good Choice." << endl;
        }

        else if (answer == 6) {//vote end
            cout << endl << "Are you sure you would like to end the game? (y/n) ";
            cout << endl << GREEN << ">> " << RESET;
            cin >> yesno;
            cin.clear();
            cin.ignore(100, '\n');

            if (yesno == 'y') {
                cout << endl; 
                players[otherPlayer].displayName();
                cout << ", would you like to end the game as well? (y/n) ";
                cout << endl << GREEN << ">> " << RESET;
                cin >> yesno;
                cin.clear();
                cin.ignore(100, '\n');

                if (yesno == 'y') playing = false;
                else {
                    cout << endl << "Good Choice. ";
                    players[currentPlayer].displayName();
                    cout << " must be desperate." << endl;
                }
            }

            else cout << endl << "Good Choice." << endl;
        }

        else if (answer == -999) playing = false;

        else cout << endl << RED << "Invalid Input." << RESET << endl;
    }
    
    int winner = players[0].findWinner(players[1]);
    if (winner > 0) {
        cout << endl << "Congratulations, ";
        players[winner % 2].displayName();
        cout << "!. You Won!" << endl;
        if (winner > 3) cout << "You tied in health, but you had more energy." << endl;

    }
    else cout << endl << "There was no winner! You tied in both health and energy!" << endl;

    cout << endl << "Would you like to view the game history? (y/n)" << endl;
    cout << GREEN << ">> " << RESET;
    cin >> yesno;
    cin.clear();
    cin.ignore(100, '\n');

    if (yesno == 'y') myDeck.displayHistory(players[0].getName(), players[1].getName());

    cout << endl << "Thanks for playing!" << endl;

    for (v = myCards.begin(); v != myCards.end(); v++) if (*v) delete (*v);

    return 0;
}

void switchPlayer(int & current, int & other) {
    int temp = current;
    current = other;
    other = temp;
}
