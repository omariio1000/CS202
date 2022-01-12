#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#include "player.h"

using namespace std;

//Player
player::player() {
    name = nullptr;
}

player::player(char * inName) {
    name = new char[strlen(inName) + 1];
    strcpy(name, inName);
}

player::~player() {
    if (name) delete name;
}

int player::changeEnergy(int energyCount, bool changeType) {
    if (changeType) energy += energyCount;
    else energy -= energyCount;
    return energyCount;
}

int player::changeHealth(int healthAmount, bool changeType) {
    if (changeType) health += healthAmount;
    else health -= healthAmount;
    return healthAmount;
}

void player::addToHand(card * adding) {
    hand.push_back(adding);
    return;
}

void player::useCard(card * toUse, player & affecting) {
    int type = toUse -> getType();

    if (type == 1) dynamic_cast<attack*> (toUse) -> attackPlayer(affecting);
    else if (type == 2) dynamic_cast<spell*> (toUse) -> restore(affecting);
    else if (type == 3) dynamic_cast<defence*> (toUse) -> healing(affecting);

    vector<card*>::iterator v;
    for (v = hand.begin(); v != hand.end(); v++) {
        if (toUse -> compare(*v)) {
            hand.erase(v);
        }
    }

    return;
}

void player::displayHand() {
    vector<card*>::iterator v;
    for (v = hand.begin(); v != hand.end(); v++) {
        (*v) -> display();
    }
    return;
}

//Node
node::node() {
    data = nullptr;
}

node::node(card * inData) {
    data = inData;
}

node::~node() {
    if (next) delete next;
    data = nullptr;
}

card * node::getData() {
    return data;
}

void node::setData(card * inData) {
    data = inData;
}

//Deck
deck::deck() {
    head = nullptr;
    discardHead = nullptr;
}

deck::~deck() {
    if (head) delete head;
    if (discardHead) delete discardHead;
}

void deck::addCards(vector<card*> cards) {
    node * temp = head;
    vector<card*>::iterator v;
    for (v = cards.begin(); v != cards.end(); v++) {
       temp = new node((*v));
       temp = temp -> next;
    }
    shuffle();
}

int deck::drawCard(player & drawing) {
    if (!head) return 0;

    node * drawed = head;
    head = head -> next;
    drawed -> next = nullptr;

    drawing.addToHand(drawed -> getData());

    delete drawed;

    return 1;
}

int deck::shuffle() {
    if (!head) return 0;
    node * count = head;
    int amount = 0;
    while (head) {
        amount++;
        head = head -> next;
    }
    count = head;

    node ** cardList = new node*[amount];

    for (int i = 0; i < amount; i++) {
        cardList[i] -> setData(count -> getData());
        count = count -> next;
    }

    random_shuffle(&cardList[0], &cardList[amount]);

    delete head;
    count = head;

    for (int i = 0; i < amount; i++) {
        count = new node(cardList[i] -> getData());
        delete cardList[i];
        count = count -> next;
    }

    delete[] cardList;

    return amount;
}

int deck::discard(card * data) {
    if (!data) return 0;
    return discard(data, discardHead);
}

int deck::discard(card * data, node * discarding) {
    if (!discarding) {
        discarding = new node(data);
        return 1;
    }
    return discard(data, discarding -> next);
}

int deck::copyDiscard() {
    if (!discardHead) return 0;

    node * temp = head;
    while (head) head = head -> next;

    return copyDiscard(temp, discardHead);
}

int deck::copyDiscard(node * deckNode, node * discardNode) {
    if (!discardNode) {
        delete discardHead;
        discardHead = nullptr;
        return 1;
    }

    deckNode = new node(discardNode -> getData());
    return copyDiscard(deckNode -> next, discardNode -> next);
}

int deck::reShuffleDiscard() {
    int disc = copyDiscard();
    if (disc == 0) return 0;

    shuffle();
    return 1;
}
