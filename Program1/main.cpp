#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "card.h"
#include "player.h"
#include "files.h"

using namespace std;

int main() {
    string input;
    files fileReader;

    vector<card*> deck;
    cout << endl << "What is the name of your file? ";
    getline(cin, input);
    int cards = fileReader.readFile(input, deck);
    cout << endl << cards << " cards added to the deck." << endl;

    vector<card*>::iterator v;
    for (v = deck.begin(); v != deck.end(); v++) {
        int type = (*v) -> getType();

        if (type == 1) dynamic_cast<attack*> (*v) -> display();
        else if (type == 2) dynamic_cast<spell*> (*v) -> display();
        else if (type == 3) dynamic_cast<defence*> (*v) -> display();
    }
    return 0;
}
