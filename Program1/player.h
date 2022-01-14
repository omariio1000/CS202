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

#include "card.h"

class player {
    public:
        player();
        player(char * name = (char*)(""));
        player(const player &);
        ~player();

        int changeEnergy(int energyCount, bool changeType); 
        int changeHealth(int healthAmount, bool changeType);
        void addToHand(class card * adding);
        void useCard(class card * toUse, player & affecting);
        void displayHand();

    private:
        char * name;
        int energy = 10;
        int health = 30;
        std::vector<class card*> hand;
};

class node {
    public:
        node();
        node(card * data);
        node(const node &);
        ~node();

        void getData(card *& data);
        void setData(card * data);
        void display();
        node * next;

    private:
        class card * data;
};

class deck {
    public: 
        deck();
        deck(const deck &);
        ~deck();

        void display();
        void addCards(std::vector<class card*> & cards);
        int drawCard(player & drawing);
        int shuffle();
        int discard(class card * data);
        int copyDiscard();
        int reShuffleDiscard();

    private:
        node * head;
        node * discardHead;

        int discard(card * data, node * discarding);
        int copyDiscard(node * deckNode, node * discardNode);
        void display(node * head);
};

#endif
