/* Omar Nassar
 * Portland State University CS202
 * February 22, 2022
 * Application to view rankings of top olympic athletes
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
#include "data.h"
#include "colors.h"

using namespace std;
using namespace colors;

int main() {
    RBT ski;
    data boardHockey;
    bool running;
    while (running) {
        int answer;
        cout << endl << "What would you like to do:" << endl;
        cout << "1. Insert Data" << endl;
        cout << "2. Display" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Quit" << endl;
        cout << YELLOW << ">> " << RESET;
        cin >> answer;
        cin.clear();
        cin.ignore(100, '\n');
        
        if (answer == 1) {//insert
        }

        else if (answer == 2) {//display
        }

        else if (answer == 3) {//remove
        }

        else if (answer == 4) running = false;
        else cout << endl << RED << "Invalid Input." << RESET << endl;
    }
    return 0;
}
