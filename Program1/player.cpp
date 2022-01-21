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

player::player(const player & old) {
    name = new char[strlen(old.name) + 1];
    strcpy (name, old.name);
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
        int type = (*v) -> getType();

        if (type == 1) dynamic_cast<attack*> (*v) -> display();
        else if (type == 2) dynamic_cast<spell*> (*v) -> display(); 
        else if (type == 3) dynamic_cast<defence*> (*v) -> display(); 

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
}

card *& node::getData() {
    return data;
}

node *& node::getNext() {
    return next;
}

void node::setNext(node * inNext) {
    next = inNext;
    return;
}

void node::setData(card * inData) {
    data = inData;
}

void node::display() {
    int type = data -> getType();    

    if (type == 1) dynamic_cast<attack*> (data) -> display();
    else if (type == 2) dynamic_cast<spell*> (data) -> display(); 
    else if (type == 3) dynamic_cast<defence*> (data) -> display(); 

    return;

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

void deck::display() {
    cout << endl << "This is the deck." << endl;
    display(head);

    cout << endl << "This is the discard pile." << endl;
    display(discardHead);

    return;

}

void deck::display(node * head) {
    if (!head) return;
    head -> display();
    return display(head -> getNext());
}

void deck::addCards(vector<card*> & cards) {
    vector<card*>::iterator v;
    for (v = cards.begin(); v != cards.end(); v++) {
        node * temp = head;
        head = nullptr;
        head = new node(*v);
        head -> setNext(temp);
    }

    return;
}

int deck::drawCard(player & drawing) {
    if (!head) return 0;

    node * drawed = head -> getNext();
    drawed -> setNext(nullptr);

    card * myCard = drawed -> getData();
    drawing.addToHand(myCard);

    delete drawed;

    return 1;
}

int deck::shuffle() {
    if (!head) return 0;

    int amount = 0;
    vector<card*> toShuffle;

    while (head) {
        card * myCard = head -> getData();
        toShuffle.push_back(myCard);
        node * temp = head -> getNext();
        head -> setNext(nullptr);
        head -> setData(nullptr);
        delete head;
        head = temp;
        temp = nullptr;
        amount++;
    }

    random_shuffle(toShuffle.begin(), toShuffle.end());

    addCards(toShuffle);
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
    return discard(data, discarding -> getNext());
}

int deck::copyDiscard() {
    if (!discardHead) return 0;

    node * temp = head;
    while (temp) temp = temp -> getNext();

    return copyDiscard(temp, discardHead);
}

int deck::copyDiscard(node * deckNode, node * discardNode) {
    if (!discardNode) {
        delete discardHead;
        discardHead = nullptr;
        return 1;
    }

    card * myCard = discardNode -> getData();
    deckNode = new node(myCard);
    return copyDiscard(deckNode -> getNext(), discardNode -> getNext());
}

int deck::reShuffleDiscard() {
    int disc = copyDiscard();
    if (disc == 0) return 0;

    shuffle();
    return 1;
}
