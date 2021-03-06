/* Omar Nassar
 * Portland State University CS202
 * February 22, 2022
 * Implementation for olympics activities
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "olympics.h"
#include "colors.h"

using namespace std;
using namespace colors;

olympics::olympics() {
    name = nullptr;
    for (int i = 0; i < 3; i++) {
        medals[i] = 0;
    }
}

olympics::olympics(const olympics & obj) {
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);

    nation = obj.nation;
    age = obj.age;
    weight = obj.weight;
    height = obj.height;

    for (int i = 0; i < 3; i++) {
        medals[i] = obj.medals[i];
    }
}

olympics::~olympics() {
    if (name) delete[] name;
    name = nullptr;
}

int olympics::setData(char * inName, string inNation, int inAge, int inWeight, int inHeight, int inMedals[]) {
    if (!inName || strcmp(inName, "") == 0) throw inName;
    if (inNation.empty()) throw inNation;
    if (inAge < 10) return 1;
    if (inWeight < 68) return 2;
    if (inHeight < 55) return 3;
    if (inMedals[0] < 0 || inMedals[1] < 0 || inMedals[2] < 0) return 4;
    
    if (name) delete[] name;
    name = new char[strlen(inName) + 1];
    strcpy(name, inName);

    nation = inNation;
    age = inAge;
    weight = inWeight;
    height = inHeight;

    for (int i = 0; i < 3; i++) {
        medals[i] = inMedals[i];
    }
    return 0;
}

void olympics::displayVisual() {
    cout << name << endl;
}

olympics& olympics::operator = (const olympics& obj) {
    if (*this == obj) return *this;
    name = new char[strlen(obj.name) + 1];
    strcpy(name, obj.name);

    nation = obj.nation;
    age = obj.age;
    weight = obj.weight;
    height = obj.height;

    for (int i = 0; i < 3; i++) {
        medals[i] = obj.medals[i];
    }

    return *this;
}

bool olympics::operator == (const olympics& obj) const {
    if (strcmp(name, obj.name) == 0) return true;
    return false;
}

bool olympics::operator == (const char * inName) const {
    if (strcmp(name, inName) == 0) return true;
    return false;
}

bool olympics::operator != (const olympics& obj) const {
    if (*this == obj) return false;
    return true;
}

bool olympics::operator != (const char * name) const {
    if (*this == name) return false;
    return true;
}

/*ostream& operator << (ostream& out, const olympics& obj) {
  out << endl << "Name: " << obj.name << " Nation: " << obj.nation << endl;
  out << "Weight: " << obj.weight << " Height: " << floor(obj.height/12) << "\' ";
  if (obj.height % 12 != 0) out << obj.height % 12 << "\"";
  out << endl << "Golds: " << obj.medals[0] << " Silvers: " << obj.medals[1] << " Bronzes: " << obj.medals[2] << endl;
  return out;
  }*/

void olympics::print(ostream & out) {
    out << endl << "Name: " << name << " Nation: " << nation << endl;
    out << "Age: " << age << " Weight: " << weight << " Height: " << floor(height/12) << "\'";
    if (height % 12 != 0) out << height % 12 << "\"";
    out << endl << "Golds: " << medals[0] << " Silvers: " << medals[1] << " Bronzes: " << medals[2] << endl;
    return;
}

ski::ski() : olympics() {}

ski::ski(const ski& obj) : olympics(obj) {
    time = obj.time;
    sponsor = obj.sponsor;
}

int ski::setData(char * name, string nation, int age, int weight, int height, int medals[], int inTime) {
    time = inTime;
    return olympics::setData(name, nation, age, weight, height, medals);
}

int ski::setSponsor(string inSponsor) {
    if (inSponsor.empty()) throw inSponsor;
    sponsor = inSponsor;
    return 0;
}

ski& ski::operator = (const ski& obj) {
    if (*this == obj) return *this;
    this -> olympics::operator = (obj);
    sponsor = obj.sponsor;
    return *this;
}

ostream& operator << (ostream& out, ski& obj) {
    obj.print(out);
    out << "Time: " << obj.time << endl;
    if (!obj.sponsor.empty()) out << "Sponsor: " << obj.sponsor << endl;
    return out;
}

board::board() : olympics() {}

board::board(const board& obj) : olympics(obj) {
    time = obj.time;
    sponsor = obj.sponsor;
}

int board::setData(char * name, string nation, int age, int weight, int height, int medals[], int inTime) {
    time = inTime;
    return olympics::setData(name, nation, age, weight, height, medals);
}

int board::setSponsor(string inSponsor) {
    if (inSponsor.empty()) throw inSponsor;
    sponsor = inSponsor;
    return 0;
} 

board& board::operator = (const board& obj) {
    if (*this == obj) return *this;
    this -> olympics::operator = (obj);
    sponsor = obj.sponsor;
    return *this;
}

ostream& operator << (ostream& out, board& obj) {
    obj.print(out);
    out << "Time: " << obj.time << endl;
    if (!obj.sponsor.empty()) out << "Sponsor: " << obj.sponsor << endl;
    return out;
}

hockey::hockey() : olympics() {}

hockey::hockey(const hockey& obj) : olympics(obj) {
    team = obj.team;
    position = obj.position;
}

int hockey::setData(char * name, string nation, int age, int weight, int height, int medals[], string inPosition) {
    position = inPosition;
    return olympics::setData(name, nation, age, weight, height, medals);
}

int hockey::setTeam(string inTeam) {
    if (inTeam.empty()) throw inTeam;
    team = inTeam;
    return 0;
}

hockey& hockey::operator = (const hockey& obj) {
    if (*this == obj) return *this;
    this -> olympics::operator = (obj);
    team = obj.team;
    return *this;
}

ostream& operator << (ostream& out, hockey& obj) {
    obj.print(out);
    out << "Position: " << obj.position << endl;
    if (!obj.team.empty()) out << "Team: " << obj.team << endl;
    return out;
}
