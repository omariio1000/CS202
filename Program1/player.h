/* Omar Nassar
 * Portland State University CS202
 * January 11, 2022
 * Player class that stores information about player
 * Also deck class that uses node class to store drawing and discard piles
 */

#ifndef player_h
#define player_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "card.h"

class player {//Player class
    public:
        //Constructors and destructors
        player();
        player(char * name = (char*)(""));
        player(const player &);
        ~player();

        int changeEnergy(int energyCount, bool changeType); 
        int changeHealth(int healthAmount, bool changeType);
        void addToHand(class card * adding);
        int useCard(char * cardName, player & affecting, class deck & myDeck, int forHistory);
        void display();
        void displayHand();
        void displayName() const;
        bool checkHealth() const;
        int findWinner(const player & other) const;
        char* getName() const;

    private:
        char * name;
        int energy = 10;
        int health = 30;
        std::vector<class card*> hand;
};

class node {//Node class to store cards, used as CLL for deck and LLL for history
    public:
        //Constructors and destructor
        node();
        node(card * data);
        node(const node &);
        ~node();

        card *& getData();
        void setData(card * data);
        void display() const;

        node *& getNext();
        void setNext(node * next);

    private:
        class card * data;
        node * next;
};

class deck {//Deck class to store drawing and discard pile
    public: 
        //Constructors and destructor
        deck();
        deck(const deck &);
        ~deck();

        void display();
        void addCards(std::vector<class card*> & cards);
        void addCards(card * adding);
        int drawCard(player & drawing);
        int shuffle();
        int discard(card * data, int forHistory);
        void copyDiscard();
        int reShuffleDiscard();
        void addToHistory(card * data, int forHistory);
        void displayHistory(char * player1, char * player2);

    private:
        node * rear; 
        node ** playerHistory;
        //node * discardHead;
        std::vector<class card*> discardPile;

        //Recursive functions
        //int discard(card * data, node * discarding);
        //int copyDiscard(node * deckNode, node * discardNode);
        void display(node * head);
        void display(std::vector<class card*> & cards);
        void addToHistory(card * data, node *& current);
        void displayHistory(node * current);
};

#endif
