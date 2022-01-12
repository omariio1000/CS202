#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "card.h"

using namespace std;

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

card::~card() {
    if (name) delete name;
}

void card::display() const {
    cout << endl << name << endl;
    cout << description << endl;
    cout << "Energy Required: " << energyRequired << endl;
    return;
}

int card::removeEnergy(player & removing) {
    removing.changeEnergy(energyRequired, false);
    return energyRequired;
}

int card::getType() {
    return 0;
}

bool card::compare(const card * comparing) {
    if (strcmp(name, comparing -> name) == 0) return true;
    return false;
}

bool card::compare(const char * comparing) {
   if (strcmp(name, comparing) == 0) return true;
   return false;
}

//Attack
attack::attack(char * name, string description, int energy, int inPower) : card(name, description, energy) {
    power = inPower;
}

void attack::display() const {
    card::display();
    cout << "This card has " << power << " attack power." << endl;
    return; 
}

int attack::getType() {
    return 1;
}

int attack::attackPlayer(player & attacking) {
    attacking.changeHealth(power, false);
    return power;
}

//Spell
spell::spell(char * name, string description, int energy, int inEnergyRestored) : card(name, description, energy) {
    energyRestored = inEnergyRestored;
}

void spell::display() const {
    card::display();
    cout << "This card will restore " << energyRestored << " energy." << endl;
    return;
}

int spell::getType() {
    return 2;
}

int spell::restore(player & restoring) {
    restoring.changeEnergy(energyRestored, true);
    return energyRestored;
}

//Defence
defence::defence(char * name, string description, int energy, int inHealed) : card(name, description, energy) { 
    healed = inHealed;
}

void defence::display() const {
    card::display();
    cout << "This card will heal " << healed << " health." << endl;
}

int defence::getType() {
    return 3;
}

int defence::healing(player & healing) {
    healing.changeHealth(healed, true);
    return healed;
}
