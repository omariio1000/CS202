/* Omar Nassar
 * Portland State University CS202
 * January 11, 2022
 * Implentation for player, deck, and accompanying node classes
 */

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

#include "player.h"
#include "files.h"

using namespace std;
using namespace colors;

//Player
player::player() {
    name = nullptr;
}

player::player(char * inName) {
    name = new char[strlen(inName) + 1];
    strcpy(name, inName);
}

player::player(const player & old) {//copy constructor
    name = new char[strlen(old.name) + 1];
    strcpy (name, old.name);
}

player::~player() {
    if (name) delete[] name;
    name = nullptr;
}

int player::changeEnergy(int energyCount, bool changeType) {//change energy either positive or negative
    if (changeType) energy += energyCount;
    else energy -= energyCount;
    return energyCount;
}

int player::changeHealth(int healthAmount, bool changeType) {//change health either positive or negative
    if (changeType) health += healthAmount;
    else health -= healthAmount;
    return healthAmount;
}

void player::addToHand(card * adding) {//adding card to a player's hand
    hand.push_back(adding);
    cout << endl << "This is the card you drew:" << endl;
    adding -> display();
    return;
}

//using a card against another player or oneself
int player::useCard(char * cardName, player & affecting, deck & myDeck, int forHistory) {
    if (!cardName) return -2;
    /*int type = toUse -> getType();

      if (type == 1) dynamic_cast<attack*> (toUse) -> attackPlayer(affecting);
      else if (type == 2) dynamic_cast<spell*> (toUse) -> restore(affecting);
      else if (type == 3) dynamic_cast<defence*> (toUse) -> healing(affecting);
      */
    bool foundCard = false;

    card * toUse = nullptr;
    vector<card*>::iterator v;
    for (v = hand.begin(); v != hand.end(); v++) {//iterating through player's hand to find card by name
        if ((*v) -> compare(cardName)) {
            foundCard = true;        
            toUse = (*v);
            myDeck.discard((*v), forHistory);
            hand.erase(v);
            break;
        }
    }

    if (!foundCard) return -3;
    if (energy < toUse -> getEnergyRequired()) return 0;

    //calling derived class function with dynamic cast
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

    energy -= toUse -> getEnergyRequired();


    return 1;
}

void player::display() {//displaying player info and hand
    cout << endl << CYAN << name << RESET << endl;
    cout << name << "'s Health: " << health << endl;
    cout << name << "'s Energy: " << energy << endl;
    cout << name << "'s Hand:" << endl;
    displayHand();
    cout << endl;
    return;
}

void player::displayHand() {//displaying player hand
    if (hand.size() == 0) {
        cout << endl << "Empty Hand!" << endl;
        return;
    }
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

void player:: displayName() const {//displaying player name
    cout << name;
}

bool player::checkHealth() const {//making sure player health isn't zero
    if (health > 0) return true;
    return false;
}

char* player::getName() const {//getter for name for card history
    return name;
}

int player::findWinner(const player & other) const {//checking who won
    if (health > other.health) return 2;
    else if (health < other.health) return 3;
    else {
        if (energy > other.energy) return 4;
        else if (energy < other.energy) return 5;
        else return -1;
    }
}

//Node
node::node() {
    data = nullptr;
    next = nullptr;
}

node::node(card * inData) {
    data = inData;
    next = nullptr;
}

node::~node() {
    if (next) delete next;
    next = nullptr;
    data = nullptr;
}

card *& node::getData() {//getter for data
    return data;
}

node *& node::getNext() {//getter for next node
    return next;
}

void node::setNext(node * inNext) {//setter for next node
    next = inNext;
    return;
}

void node::setData(card * inData) {//setter for data
    data = inData;
}

void node::display() const {//display node contents
    if (!data) return;
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
    rear = nullptr;
    playerHistory = new node*[2];
    playerHistory[0] = playerHistory[1] = nullptr;
    //discardHead = nullptr;
}

deck::~deck() {
    if (rear) {
        node * temp = rear -> getNext();
        rear -> setNext(nullptr);
        rear = temp;
        delete rear;
    }
    if (playerHistory[0]) delete playerHistory[0];
    if (playerHistory[1]) delete playerHistory[1];
    delete [] playerHistory;
    rear = nullptr;
    playerHistory = nullptr;
    //if (discardHead) delete discardHead;
}

void deck::display() {//displaying deck and discard pile
    cout << endl << "This is the deck." << endl;
    if (rear) {
        rear -> display();
        display(rear -> getNext());
    }

    cout << endl << "This is the discard pile." << endl;
    display(discardPile);

    return;

}

void deck::display(node * current){//displaying for CLL deck
    if (!current || current == rear) return;
    current -> display();
    return display(current -> getNext());
}

void deck::display(vector<card*> & cards) {//displaying for vector discard pile
    vector<card*>::iterator v;
    for (v = cards.begin(); v != cards.end(); v++) (*v) -> display();
    return;
}

void deck::addCards(vector<card*> & cards) {//adding cards to deck from a vector
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

void deck::addCards(card * adding) {//adding cards to CLL given a card object
    if (!rear) {
        rear = new node(adding);
        rear -> setNext(rear);
        return;
    }
    node * temp = new node(adding);
    temp -> setNext(rear -> getNext());
    rear -> setNext(temp);
    rear = temp;
    return;
}

int deck::drawCard(player & drawing) {//drawing a card and giving it to a player
    if (!rear) return 0;
    
    card * myCard = nullptr;

    if (rear == rear -> getNext()) {
       myCard = rear -> getData(); 
       rear -> setNext(nullptr);
       delete rear;
       rear = nullptr;
    }
    else {
        node * draw = rear -> getNext();
        rear -> setNext(draw -> getNext());
        draw -> setNext(nullptr);
        myCard = draw -> getData();
        delete draw;
        draw = nullptr;
    }

    drawing.addToHand(myCard);
    return 1;
}

int deck::shuffle() {//shuffling the deck of cards
    if (!rear) return 0;

    int amount = 0;
    vector<card*> toShuffle;

    node * temp = rear -> getNext();
    rear -> setNext(nullptr);
    rear = temp;

    while (rear) {
        card * myCard = rear -> getData();
        toShuffle.push_back(myCard);
        temp = rear -> getNext();
        rear -> setNext(nullptr);
        rear -> setData(nullptr);
        delete rear;
        rear = temp;
        temp = nullptr;
        amount++;
    }
    srand(unsigned(time(NULL)));
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

int deck::discard(card * data, int forHistory) {//discarding a card and adding to history
    discardPile.push_back(data);
    //cout << "THIS IS THE DISCARDED CARD: ";
    //data -> display();
    addToHistory(data, forHistory);
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

void deck::copyDiscard() {//copying the discard pile and adding it to the deck
    addCards(discardPile);
    vector<card*>::iterator v;
    for (v = discardPile.begin(); v != discardPile.end(); v++)
        (*v) = nullptr;
    
    discardPile.clear();
    return;
}

int deck::reShuffleDiscard() {//reshuffling discard pile into deck
    int items = discardPile.size();
    copyDiscard();
    shuffle();
    return items;
}

void deck::addToHistory(card * data, int forHistory) {//wrapper to add card to player history
    return addToHistory(data, playerHistory[forHistory]);
}

void deck::addToHistory(card * data, node *& current) {//recursive adding to player history LLL
    if (!current) {
        current = new node(data);
        return;
    }
    return addToHistory(data, current -> getNext());
}

void deck::displayHistory(char * player1, char * player2) {//wrapper to display player history
    cout << endl << player1 << "'s history:" << endl;
    displayHistory(playerHistory[0]);
    cout << endl << player2 << "'s history:" << endl;
    displayHistory(playerHistory[1]);
    return;
}

void deck::displayHistory(node * current) {//recursive display player history
    if (!current) return;
    current -> display();
    return displayHistory(current -> getNext());
}
