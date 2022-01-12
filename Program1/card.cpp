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
}

card::card(char * name, string description, int energy) {
}

card::~card() {
}

int card::display() const {
}

int card::removeEnergy(player & removing) {
}

int card::getType() {
    return 0;
}

bool card::compare(const char *name) {
}

//Attack
attack::attack(char * name, string description, int energy, int power) : card(name, description, energy) {
}

int attack::display() const {
}

int attack::getType() {
    return 1;
}

int attack::attackPlayer(player & attacking) {
}

//Spell
spell::spell(char * name, string description, int energy, int energyRestored) : card(name, description, energy) {
}

int spell::display() const {
}

int spell::getType() {
    return 2;
}

int spell::restore(player & restoring) {
}

//Defence
defence::defence(char * name, string description, int energy, int healed) : card(name, description, energy) { 
}

int defence::display() const {
}

int defence::getType() {
    return 3;
}

int defence::healing(player & healing) {
}
