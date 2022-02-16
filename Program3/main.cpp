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
    RBT skiTree;
    data myData;
    bool running;
    while (running) {
        int answer;
        cout << endl << "What would you like to do:" << endl;
        cout << "1. Add a Ranking" << endl;
        cout << "2. Display" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Quit" << endl;
        cout << YELLOW << ">> " << RESET;
        cin >> answer;
        cin.clear();
        cin.ignore(100, '\n');
        
        if (answer == 1) {//insert
            cout << endl << "Which sport is this for?" << endl;
            cout << "1. Skiing" << endl;
            cout << "2. Snowboarding" << endl;
            cout << "3. Ice Hockey" << endl;
            cout << YELLOW << ">> " << RESET;
            cin >> answer;
            cin.clear();
            cin.ignore(100, '\n');

            char * name = new char[100];
            string nation;
            int age;
            int weight;
            int height;
            int medals[3];

            cout << endl << "What is the athlete's name?" << endl << YELLOW << ">> " << RESET;
            cin.get(name, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "How old is the athlete?" << endl << YELLOW << ">> " << RESET;
            cin >> age;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "How much does the athlete weigh? (lbs)" << endl << YELLOW << ">> " << RESET;
            cin >> weight;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the athlete's height? (in)" << endl << YELLOW << ">> " << RESET;
            cin >> height;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "How many gold medals does this athlete have?" << endl << YELLOW << ">> " << RESET;
            cin >> medals[0];
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "How many silver medals does this athlete have?" << endl << YELLOW << ">> " << RESET;
            cin >> medals[1];
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "How many bronze medals does this athlete have?" << endl << YELLOW << ">> " << RESET;
            cin >> medals[2];
            cin.clear();
            cin.ignore(100, '\n');

            if (answer == 1) {//ski
                int time;
                cout << endl << "What is the athelete's time?" << endl << YELLOW << ">> " << RESET;
                cin >> time;
                cin.clear();
                cin.ignore(100, '\n');

                string sponsor;
                cout << endl << "Does this athlete have a sponsor? If not, leave empty." << endl << YELLOW << ">> " << RESET;
                cin >> sponsor;
                cin.clear();
                cin.ignore(100, '\n');
                
                int ret;
                ski * mySki = new ski();
                try {
                    ret = mySki -> setData(name, nation, age, weight, height, medals, time);
                }
                catch (char*) {
                }
                catch (string) {
                }
                if (ret == 0) {
                }
                else {
                }
            }
            else if (answer == 2) {//board
            }
            else if (answer == 3) {//hockey
            }
            else cout << endl << RED << "Invalid Input." << endl << RESET;
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
