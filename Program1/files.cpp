#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "files.h"

using namespace std;

files::files() {}

int files::readFile(string fileName, vector<card*> & cards) {
    ifstream file;
    file.open(fileName);

    int cardCount = 0;

    if (file) {
        string line;
        char ** allInfo = new char*[6];
        while (getline(file, line)) {

            allInfo[0] = new char[1000];

            //memset because otherwise char array was full of junk
            memset(allInfo[0], 0, sizeof(allInfo));

            int counter = 0;
            int pos = 0;
            for (int i = 0; i < (int) line.length(); i++) { 
                if (line[i] != '|' && line[i] != '\r') {
                    allInfo[counter][pos] = line[i];
                    pos++;
                }
                else if (line[i] != '\r'){
                    pos++;
                    counter++;
                    pos = 0;
                    allInfo[counter] = new char[1000];

                    //memset because otherwise char array was full of junk
                    memset(allInfo[counter], 0, 1000);
                }
            }

            string description(allInfo[2]);
            int energy = atoi(allInfo[3]);
            int powerHealRestore = atoi(allInfo[4]);
            int repititions = atoi(allInfo[5]);

            if (strcmp(allInfo[0], (char*)("attack")) == 0) {
                for (int i = 0; i < repititions; i++) {
                    attack * newCard = new attack(allInfo[1], description, energy, powerHealRestore);
                    cards.push_back(newCard);
                    newCard = nullptr;
                }
            }

            else if (strcmp(allInfo[0], (char*)("spell")) == 0) {
                for (int i = 0; i < repititions; i++) { 
                    spell * newCard = new spell(allInfo[1], description, energy, powerHealRestore);
                    cards.push_back(newCard);
                    newCard = nullptr;
                }
            }

            else if (strcmp(allInfo[0], (char*)("defence")) == 0) {
                for (int i = 0; i < repititions; i++) {
                    defence * newCard = new defence(allInfo[1], description, energy, powerHealRestore);
                    cards.push_back(newCard);
                    newCard = nullptr;
                }
            }

            for (int i = 0; i < 7; i++) {
                delete[] allInfo[i];
                allInfo[i] = nullptr;
            }
            cardCount += repititions;
        }
        delete[] allInfo;
    };
    file.close();
    return cardCount;
}
