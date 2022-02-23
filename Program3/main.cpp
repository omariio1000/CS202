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
    bool running = true;
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

            cout << endl << "What nation is the athlete representing?" << endl << YELLOW << ">> " << RESET;
            cin >> nation;
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
            int ret = -1;

            if (answer == 1) {//ski
                int time;
                cout << endl << "What is the athelete's time? (s)" << endl << YELLOW << ">> " << RESET;
                cin >> time;
                cin.clear();
                cin.ignore(100, '\n');

                string sponsor;
                cout << endl << "Does this athlete have a sponsor? If not, input 'n'." << endl << YELLOW << ">> " << RESET;
                cin >> sponsor;
                cin.clear();
                cin.ignore(100, '\n');

                ski * mySki = new ski();
                try {
                    ret = mySki -> setData(name, nation, age, weight, height, medals, time);
                }
                catch (char*) {
                    cout << endl << RED << "Name cannot be empty!" << RESET << endl;
                }
                catch (string) {
                    cout << endl << RED << "Nation cannot be empty!" << RESET << endl;
                }
                if (ret == 0) {
                    if (sponsor != "n") mySki -> setSponsor(sponsor);

                    cout << endl << "What is this athelete's ranking?" << endl;
                    cout << YELLOW << ">> " << RESET;
                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    node * adding = new node(mySki, answer);
                    try {
                        skiTree += adding;
                        cout << endl << GREEN << "Successfully added!" << RESET << endl;
                    }
                    catch (int) {
                        cout << endl << RED << "Cannot have a negative rank!" << RESET << endl;
                        delete adding;
                    }
                    catch (node*) {
                        cout << endl << RED << "Weird." << RESET << endl;
                    }
                }
                else delete mySki;
            }
            else if (answer == 2) {//board
                int time;
                cout << endl << "What is the athelete's time? (s)" << endl << YELLOW << ">> " << RESET;
                cin >> time;
                cin.clear();
                cin.ignore(100, '\n');

                string sponsor;
                cout << endl << "Does this athlete have a sponsor? If not, input 'n'." << endl << YELLOW << ">> " << RESET;
                cin >> sponsor;
                cin.clear();
                cin.ignore(100, '\n');

                board * myBoard = new board();
                try {
                    ret = myBoard -> setData(name, nation, age, weight, height, medals, time);
                }
                catch (char*) {
                    cout << endl << RED << "Name cannot be empty!" << RESET << endl;
                }
                catch (string) {
                    cout << endl << RED << "Nation cannot be empty!" << RESET << endl;
                }
                if (ret == 0) {
                    if (sponsor != "n") myBoard -> setSponsor(sponsor);

                    cout << endl << "What is this athlete's ranking?" << endl;
                    cout << YELLOW << ">> " << RESET;
                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    try {
                        myData.insertData(myBoard, answer);
                        cout << endl << GREEN << "Successfully added!" << RESET << endl;
                    }
                    catch (olympics*) {
                        cout << endl << RED << "Unknown Error." << RESET << endl; 
                    }
                }
                else delete myBoard;

            }
            else if (answer == 3) {//hockey
                string position;
                cout << endl << "What position does the athlete play?" << endl << YELLOW << ">> " << RESET;
                cin >> position;
                cin.clear();
                cin.ignore(100, '\n');

                string team;
                cout << endl << "What team does this athlete play for a team? If not, input 'n'." << endl << YELLOW << ">> " << RESET;
                cin >> team;
                cin.clear();
                cin.ignore(100, '\n');

                hockey * myHockey = new hockey();
                try {
                    ret = myHockey -> setData(name, nation, age, weight, height, medals, position);
                }
                catch (char*) {
                    cout << endl << RED << "Name cannot be empty!" << RESET << endl;
                }
                catch (string) {
                    cout << endl << RED << "Nation cannot be empty!" << RESET << endl;
                }
                if (ret == 0) {
                    if (team != "n") myHockey -> setTeam(team);

                    cout << endl << "What is this athlete's ranking?" << endl;
                    cout << YELLOW << ">> " << RESET;
                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    try {
                        myData.insertData(myHockey, answer);
                        cout << endl << GREEN << "Successfully added!" << RESET << endl;
                    }
                    catch (olympics*) {
                        cout << endl << RED << "Unknown Error." << RESET << endl;
                    }
                }
                else delete myHockey;

            }
            else cout << endl << RED << "Invalid Input." << endl << RESET;

            if (ret == 1) cout << RED << endl << "Age cannot be that low!" << endl << RESET;
            else if (ret == 2) cout << RED << endl << "The lightest olympian ever was heavier than that!" << RESET << endl;
            else if (ret == 3) cout << RED << endl << "The shortest olympian ever was taller!" << RESET << endl;
            else if (ret == 4) cout << RED << endl << "Negative medals???" << RESET << endl;


            if (name) delete[] name;
        }

        else if (answer == 2) {//display
            cout << endl << "What would you like to display?" << endl;
            cout << "1. Display All" << endl;
            cout << "2. Display Skiirs" << endl;
            cout << "3. Display Snowboarders" << endl;
            cout << "4. Display Hockey Players" << endl;
            cout << YELLOW << ">> " << RESET;
            cin >> answer;
            cin.clear();
            cin.ignore(100, '\n');

            if (answer == 1) {//everything
                cout << BLUE << endl << "Skiirs: " << endl << RESET;
                try {
                    skiTree.displayAll();
                }
                catch (node*) {
                    cout << RED << endl << "Nothing to display!" << RESET << endl;
                }
                cout << MAGENTA << endl << "Snowboarders: " << endl << RESET;
                if (!myData.displayAll(true)) cout << RED << endl << "Nothing to display!" << RESET << endl;
                cout << CYAN << endl << "Hockey Players: " << endl << RESET;
                if (!myData.displayAll(false)) cout << RED << endl << "Nothing to display!" << RESET << endl;
            }
            else if (answer == 2) {//skiirs
                cout << endl << "What would you like to display?" << endl;
                cout << "1. Display Sorted" << endl;
                cout << "2. Display Red-Black Tree" << endl;
                cout << "3. Display Match" << endl;
                cout << YELLOW << ">> " << RESET;

                cin >> answer;
                cin.clear();
                cin.ignore(100, '\n');

                if (answer == 1) {
                    try {
                        skiTree.displayAll();
                    }
                    catch (node*) {
                        cout << endl << RED << "Nothing to Display!" << RESET << endl;
                    }
                }
                else if (answer == 2) {
                    try {
                        skiTree.visualDisplay();
                    }
                    catch (node*) {
                        cout << endl << RED << "Tree is empty!" << RESET << endl;
                    }
                }
                else if (answer == 3) {
                    cout << endl << "Would you like to display by..." << endl;
                    cout << "1. Ranking" << endl;
                    cout << "2. Name" << endl;
                    cout << "NOTE: Duplicates will not be displayed." << endl;
                    cout << YELLOW << ">> " << RESET;

                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (answer == 1) {
                        cout << endl << "What is the ranking?" << endl << YELLOW << ">> " << RESET;
                        cin >> answer;
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            skiTree.displaySingle(answer);
                        }
                        catch (int) {
                            cout << endl << RED << "Can't have a ranking below 1!" << RESET << endl;
                        }
                        catch (node*) {
                            cout << endl << RED << "Nobody found with that ranking!" << RESET << endl;
                        }
                    }
                    else if (answer == 2) {
                        cout << endl << "What is the name?" << endl << YELLOW << ">> " << RESET;
                        char * name = new char[100];
                        cin.get(name, 100);
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            skiTree.displaySingle(name);
                        }
                        catch (int) {
                            cout << endl << RED << "Name can't be empty!" << RESET << endl;
                        }
                        catch (node*) {
                            cout << endl << RED << "Nobody found with that name!" << RESET << endl;
                        }
                        if (name) delete[] name;
                    }
                    else cout << RED << endl << "Invalid Input." << RESET << endl;
                }
                else cout << RED << endl << "Invalid Input." << RESET << endl;

            }
            else if (answer == 3) {//snowboarders
                cout << endl << "What would you like to display?" << endl;
                cout << "1. Display Sorted" << endl;
                cout << "2. Display Match" << endl;
                cout << YELLOW << ">> " << RESET;

                cin >> answer;
                cin.clear();
                cin.ignore(100, '\n');

                if (answer == 1) {
                    if (!myData.displayAll(true)) cout << endl << RED << "Nothing to display!" << RESET << endl;
                }
                else if (answer == 2) { 
                    cout << endl << "Would you like to display by..." << endl;
                    cout << "1. Ranking" << endl;
                    cout << "2. Name" << endl;
                    cout << YELLOW << ">> " << RESET;

                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (answer == 1) {
                        cout << endl << "What is the ranking?" << endl << YELLOW << ">> " << RESET;
                        cin >> answer;
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            myData.displaySingle(answer, true);
                        }
                        catch (int) {
                            cout << endl << RED << "Can't have a ranking below 1!" << RESET << endl;
                        }
                        catch (bool) {
                            cout << endl << RED << "Nobody found with that ranking!" << RESET << endl;
                        }
                    }
                    else if (answer == 2) {
                        cout << endl << "What is the name?" << endl << YELLOW << ">> " << RESET;
                        char * name = new char[100];
                        cin.get(name, 100);
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            myData.displaySingle(name, true);
                        }
                        catch (int) {
                            cout << endl << RED << "Name can't be empty!" << RESET << endl;
                        }
                        if (name) delete[] name;
                    }
                    else cout << RED << endl << "Invalid Input." << RESET << endl;
                }
                else cout << RED << endl << "Invalid Input." << RESET << endl;

            }
            else if (answer == 4) {//hockey
                cout << endl << "What would you like to display?" << endl;
                cout << "1. Display Sorted" << endl;
                cout << "2. Display Match" << endl;
                cout << YELLOW << ">> " << RESET;

                cin >> answer;
                cin.clear();
                cin.ignore(100, '\n');

                if (answer == 1) {
                    if (!myData.displayAll(false)) cout << endl << RED << "Nothing to display!" << RESET << endl;
                }
                else if (answer == 2) {
                    cout << endl << "Would you like to display by..." << endl;
                    cout << "1. Ranking" << endl;
                    cout << "2. Name" << endl;
                    cout << YELLOW << ">> " << RESET;

                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (answer == 1) {
                        cout << endl << "What is the ranking?" << endl << YELLOW << ">> " << RESET;
                        cin >> answer;
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            myData.displaySingle(answer, false);
                        }
                        catch (int) {
                            cout << endl << RED << "Can't have a ranking below 1!" << RESET << endl;
                        }
                        catch (bool) {
                            cout << endl << RED << "Nobody found with that rank!" << RESET << endl;
                        }
                    }
                    else if (answer == 2) {
                        cout << endl << "What is the name?" << endl << YELLOW << ">> " << RESET;
                        char * name = new char[100];
                        cin.get(name, 100);
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            myData.displaySingle(name, false);
                        }
                        catch (int) {
                            cout << endl << RED << "Name can't be empty!" << RESET << endl;
                        }
                        if (name) delete[] name;
                    }
                    else cout << RED << endl << "Invalid Input." << RESET << endl;
                }
                else cout << RED << endl << "Invalid Input." << RESET << endl;
            }
            else cout << RED << endl << "Invalid Input." << RESET << endl;
        }

        else if (answer == 3) {//remove
            cout << endl << "Would you like to:" << endl;
            cout << "1. Remove All" << endl;
            cout << "2. Remove All of One Sport"  << endl;
            cout << "3. Remove Single" << endl;
            cout << YELLOW << ">> " << RESET;
            
            cin >> answer;
            cin.clear();
            cin.ignore(100, '\n');

            if (answer == 1) {
                skiTree.removeAll();
                myData.removeAll(true);
                myData.removeAll(false);
            }
            else if (answer == 2) {
                cout << endl << "Which sport would you like to remove?" << endl;
                cout << "1. Skiirs" << endl;
                cout << "2. Snowboarders" << endl;
                cout << "3. Hockey Players" << endl;
                cout << YELLOW << ">> " << RESET;

                cin >> answer;
                cin.clear();
                cin.ignore(100, '\n');

                if (answer == 1) skiTree.removeAll();
                else if (answer == 2) myData.removeAll(true);
                else if (answer == 3) myData.removeAll(false);
                else cout << endl << RED << "Invalid Input." << RESET << endl;
            }
            else if (answer == 3) {
                cout << endl << "What sport does the athlete compete in?" << endl;
                cout << "1. Skiing" << endl;
                cout << "2. Snowboarding" << endl;
                cout << "3. Hockey" << endl;
                cout << YELLOW << ">> " << RESET;

                cin >> answer;
                cin.clear();
                cin.ignore(100, '\n');

                if (answer == 1) {
                    cout << endl << "Would you like to remove by..." << endl;
                    cout << "1. Rank" << endl;
                    cout << "2. Name" << endl;
                    cout << YELLOW << ">> " << RESET;

                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (answer == 1) {
                        cout << endl << "What is the rank?" << endl << YELLOW << ">> " << RESET;
                        cin >> answer;
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            skiTree.remove(answer);
                        }
                        catch (int) {
                            cout << endl << RED << "Rank cannot be below 1!" << RESET << endl;
                        }
                        catch (node*) {
                            cout << endl << RED << "Nobody found with that rank!" << RESET << endl;
                        }
                    }
                    else if (answer == 2) {
                        char * name = new char[100];
                        cout << endl << "What is the athlete's name?" << endl << YELLOW << ">> " << RESET;
                        cin.get(name, 100);
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            skiTree.remove(name);
                        }
                        catch (char*) {
                            cout << endl << RED << "Name cannot be empty!" << endl << RESET;
                        }
                        catch (node*) {
                            cout << endl << RED << "Nobody found with that name!" << endl << RESET;
                        }
                    }
                    else cout << endl << RED << "Invalid Input." << RESET << endl;
                }
                else if (answer == 2) {
                    cout << endl << "Would you like to remove by..." << endl;
                    cout << "1. Rank" << endl;
                    cout << "2. Name" << endl;
                    cout << YELLOW << ">> " << RESET;

                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (answer == 1) {
                        cout << endl << "What is the rank?" << endl << YELLOW << ">> " << RESET;
                        cin >> answer;
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            myData.remove(answer, true);
                        }
                        catch (int) {
                            cout << endl << RED << "Rank cannot be below 1!" << RESET << endl;
                        }
                        catch (node*) {
                            cout << endl << RED << "Nobody found with that rank!" << RESET << endl;
                        }
                    }
                    else if (answer == 2) {
                        char * name = new char[100];
                        cout << endl << "What is the athlete's name?" << endl << YELLOW << ">> " << RESET;
                        cin.get(name, 100);
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            myData.remove(name, true);
                        }
                        catch (char*) {
                            cout << endl << RED << "Name cannot be empty!" << endl << RESET;
                        }
                        catch (node*) {
                            cout << endl << RED << "Nobody found with that name!" << endl << RESET;
                        }
                    }
                    else cout << endl << RED << "Invalid Input." << RESET << endl;
                }
                else if (answer == 3) {
                    cout << endl << "Would you like to remove by..." << endl;
                    cout << "1. Rank" << endl;
                    cout << "2. Name" << endl;
                    cout << YELLOW << ">> " << RESET;

                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (answer == 1) {
                        cout << endl << "What is the rank?" << endl << YELLOW << ">> " << RESET;
                        cin >> answer;
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            myData.remove(answer, false);
                        }
                        catch (int) {
                            cout << endl << RED << "Rank cannot be below 1!" << RESET << endl;
                        }
                        catch (node*) {
                            cout << endl << RED << "Nobody found with that rank!" << RESET << endl;
                        }
                    }
                    else if (answer == 2) {
                        char * name = new char[100];
                        cout << endl << "What is the athlete's name?" << endl << YELLOW << ">> " << RESET;
                        cin.get(name, 100);
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            myData.remove(name, false);
                        }
                        catch (char*) {
                            cout << endl << RED << "Name cannot be empty!" << endl << RESET;
                        }
                        catch (node*) {
                            cout << endl << RED << "Nobody found with that name!" << endl << RESET;
                        }
                    }
                    else cout << endl << RED << "Invalid Input." << RESET << endl;
                }
                else cout << endl << RED << "Invalid Input." << RESET << endl;
            }
            else cout << endl << RED << "Invalid Input." << RESET << endl;
        }

        else if (answer == 4) running = false;
        else cout << endl << RED << "Invalid Input." << RESET << endl;
    }
    return 0;
}
