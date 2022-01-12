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
        int addToHand(class card * adding);
        int useCard(class card * toUse);
        int displayHand() const;

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

        node *& getNext();
        card * getData();
        int setNext(node *& next); 

    private:
        class card * data;
        node * next;
};

class deck {
    public: 
        deck();
        deck(const deck &);
        ~deck();

        int drawCard(player & drawing);
        int shuffle();
        int discard(const class card * data);
        int reShuffleDiscard();
        
    private:
        node * head;
        node * discardHead;
};

#endif
