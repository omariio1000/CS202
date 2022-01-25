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

int player::useCard(card * toUse, player & affecting, deck & myDeck) {
    /*int type = toUse -> getType();

      if (type == 1) dynamic_cast<attack*> (toUse) -> attackPlayer(affecting);
      else if (type == 2) dynamic_cast<spell*> (toUse) -> restore(affecting);
      else if (type == 3) dynamic_cast<defence*> (toUse) -> healing(affecting);
      */
    if (energy < toUse -> getEnergyRequired()) {
        cout << endl << "You don't have enough energy to play this card!" << endl;
        return 0;
    }

    attack * ptr = dynamic_cast<attack*> (toUse);
    if (ptr) ptr -> attackPlayer(affecting);
    else {
        spell * ptr = dynamic_cast<spell*> (toUse);
        if (ptr) ptr -> restore(affecting);
        else {
            defence * ptr = dynamic_cast<defence*> (toUse);
            if (ptr) ptr -> healing(affecting);
            else return -1;
        }
    }

    vector<card*>::iterator v;
    for (v = hand.begin(); v != hand.end(); v++) {
        if (toUse -> compare(*v)) {
            myDeck.discard(*v);
            hand.erase(v);
        }
    }

    return 1;
}

void player::display() {
    cout << endl << name << endl;
    cout << name << "'s Health: " << health << endl;
    cout << name << "'s Energy: " << energy << endl;
    cout << name << "'s Hand:" << endl;
    displayHand();
    cout << endl;
    return;
}

void player::displayHand() {
    vector<card*>::iterator v;
    for (v = hand.begin(); v != hand.end(); v++) (*v) -> display();
    /*{
     * int type = (*v) -> getType();

     if (type == 1) dynamic_cast<attack*> (*v) -> display();
     else if (type == 2) dynamic_cast<spell*> (*v) -> display(); 
     else if (type == 3) dynamic_cast<defence*> (*v) -> display(); 
     }
     */


    return;
}

void player:: displayName() const {
    cout << name;
}

bool player::checkHealth() const {
    if (health > 0) return true;
    return false;
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

void node::display() const {
    /*int type = data -> getType();    

      if (type == 1) dynamic_cast<attack*> (data) -> display();
      else if (type == 2) dynamic_cast<spell*> (data) -> display(); 
      else if (type == 3) dynamic_cast<defence*> (data) -> display();
      */
    data -> display();

    return;

}

//Deck
deck::deck() {
    head = nullptr;
    //discardHead = nullptr;
}

deck::~deck() {
    if (head) {
        node * temp = head -> getNext();
        head -> setNext(nullptr);
        head = temp;
        delete head;
    }
    //if (discardHead) delete discardHead;
}

void deck::display() {
    cout << endl << "This is the deck." << endl;
    head -> display();
    display(head -> getNext());

    cout << endl << "This is the discard pile." << endl;
    display(discardPile);

    return;

}

void deck::display(node * current) const {
    if (!current || current != head) return;
    current -> display();
    return display(current -> getNext());
}

void deck::display(vector<card*> & cards) {
    vector<card*>::iterator v;
    for (v = cards.begin(); v != cards.end(); v++) (*v) -> display();
    return;
}

void deck::addCards(vector<card*> & cards) {
    vector<card*>::iterator v;
    for (v = cards.begin(); v != cards.end(); v++) addCards(*v);
    /*{
        node * temp = head;
        head = nullptr;
        head = new node(*v);
        head -> setNext(temp);
    }*/

    return;
}

void deck::addCards(card * adding) {
    if (!head) {
        head = new node(adding);
        head -> setNext(head);
        return;
    }
    node * temp = new node(adding);
    temp -> setNext(head -> getNext());
    head -> setNext(temp);
    head = temp;
    return;
}

int deck::drawCard(player & drawing) {
    if (!head) return -1;

    node * drawed = head -> getNext();
    head -> setNext(drawed-> getNext());
    drawed -> setNext(nullptr);

    card * myCard = drawed -> getData();
    drawing.addToHand(myCard);

    if (!head -> getNext()) {
        delete head;
        return reShuffleDiscard();
    }

    delete drawed;

    return -2;
}

int deck::shuffle() {
    if (!head) return 0;

    int amount = 0;
    vector<card*> toShuffle;

    node * temp = head -> getNext();
    head -> setNext(nullptr);
    head = temp;

    while (head) {
        card * myCard = head -> getData();
        toShuffle.push_back(myCard);
        temp = head -> getNext();
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

/*int deck::discard(card * data) {
    if (!data) return 0;
    return discard(data, discardHead);
}

int deck::discard(card * data, node * discarding) {
    if (!discarding) {
        discarding = new node(data);
        return 1;
    }
    return discard(data, discarding -> getNext());
}*/

int deck::discard(card * data) {
    if (!data) return 0;
    discardPile.push_back(data);
    return 1;
}

/*int deck::copyDiscard() {
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
}*/

void deck::copyDiscard() {
    addCards(discardPile);
    discardPile.clear();
    return;
}

int deck::reShuffleDiscard() {
    int items = discardPile.size();
    copyDiscard();
    shuffle();
    return items;
}
