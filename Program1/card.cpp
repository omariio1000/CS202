/* Omar Nassar
 * Portland State University CS202
 * January 11, 2022
 * Implementation for card base and derived classes
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "card.h"
#include "files.h"

using namespace std;
using namespace colors;

//Card

card::card() {
    name = nullptr;
}

card::card(char * inName, string inDesc, int inEnergy) {
    name = new char[strlen(inName) + 1];
    strcpy(name, inName);

    description = inDesc;
    energyRequired = inEnergy;
}

card::card(const card & object) {//copy constructor
    name = new char[strlen(object.name) + 1];
    strcpy(name, object.name);
}

card::~card() {
    if (name) delete[] name;
    name = nullptr;
}

void card::display() const {//display all info, virtual so I don't need dynamic cast
    cout << endl << name << endl;
    cout << description << endl;
    cout << "Energy Required: " << energyRequired << endl;
    return;
}

void card::displayName() const {//display just name for client
    cout << name;
    return;
}

int card::removeEnergy(player & removing) const {//removing required energy from player
    removing.changeEnergy(energyRequired, false);
    return energyRequired;
}

int card::getEnergyRequired() const {//getting how much energy is needed for cient
    return energyRequired;
}

/*int card::getType() {
    return 0;
}*/

bool card::compare(const card * comparing) {//comparing two cards to see if same
    if (strcmp(name, comparing -> name) == 0) return true;
    return false;
}

bool card::compare(const char * comparing) {//comparing names to see if same
    if (strcmp(name, comparing) == 0) return true;
    return false;
}

//Attack
attack::attack(char * name, string description, int energy, int inPower) : card(name, description, energy) {
    power = inPower;
    //only here because can't think of a use for it
    required = new char[strlen("Required ot have a char array in at least one derived class lol") + 1];
    strcpy(required, "Required to have a char array in at least one derived class lol");
}

attack::~attack() {
    if (required) delete[] required;
    required = nullptr;
}

void attack::display() const {//virtual display all function
    cout << RED;
    card::display();
    cout << "This card has " << power << " attack power." << endl << RESET;
    return; 
}

/*int attack::getType() {
    return 1;
}*/

int attack::attackPlayer(player & attacking) const {//attacking player (removing their health)
    attacking.changeHealth(power, false);
    return power;
}

//Spell
spell::spell(char * name, string description, int energy, int inEnergyRestored) : card(name, description, energy) {
    energyRestored = inEnergyRestored;
}

void spell::display() const {//virtual display all function
    cout << MAGENTA;
    card::display();
    cout << "This card will restore " << energyRestored << " energy." << endl << RESET;
    return;
}

/*int spell::getType() {
    return 2;
}*/

int spell::restore(player & restoring) const {//restoring player's energy
    restoring.changeEnergy(energyRestored, true);
    return energyRestored;
}

//Defence
defence::defence(char * name, string description, int energy, int inHealed) : card(name, description, energy) { 
    healed = inHealed;
}

void defence::display() const {//virtual display all function
    cout << BLUE;
    card::display();
    cout << "This card will heal " << healed << " health." << endl << RESET;
}

/*int defence::getType() {
    return 3;
}*/

int defence::healing(player & healing) const {//healing player
    healing.changeHealth(healed, true);
    return healed;
}
