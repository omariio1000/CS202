/* Omar Nassar
 * Portland State University CS202
 * January 31, 2022
 * Program to store activities and concepts for study
 * Goal of understanding dynamic binding and exception handling
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "activities.h"
#include "data.h"
#include "colors.h"

using namespace colors;
using namespace std;

int main() {
    ADLL myActivities;
    bool running = true;

    while (running) {
        cout << endl << "What would you like to do?" << endl;
        cout << "1: Add an activity" << endl;
        cout << "2: Display" << endl;
        cout << "3: Remove" << endl;
        cout << "4: Retrieve to Edit" << endl;
        cout << "5: Quit" << endl << YELLOW << ">> " << RESET;

        int answer;
        cin >> answer;
        cin.clear();
        cin.ignore(100, '\n');

        if (answer == 1) {//Add
            cout << endl << "What type of activity would you like to add?" << endl;
            cout << CYAN << "1: Exam Prep Question" << endl;
            cout << GREEN << "2: Practice Problems" << endl;
            cout << MAGENTA << "3: Concepts to Study" << endl;
            cout << YELLOW << ">> " << RESET;

            cin >> answer;
            cin.clear();
            cin.ignore(100, '\n');

            activity * data;

            char * title = new char[100];
            string details;

            cout << endl << "What is the title of the question?" << endl << YELLOW << ">> " << RESET;
            cin.get(title, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What are the details of the question?" << endl << YELLOW << ">> " << RESET;
            cin >> details;
            cin.clear();
            cin.ignore(100, '\n');



            if (answer == 1) {//Exam Prep
                int type;
                char * sample = new char[100];

                cout << endl << "What type of exam is this?" << endl;
                cout << "1: Quiz Prep" << endl;
                cout << "2: Midterm Prep" << endl;
                cout << "3: Final Prep" << endl;
                cout << "4: Proficiency Demo Prep" << endl;
                cout << "5: Other" << endl;
                cout << YELLOW << ">> " << RESET;
                cin >> type;
                if (type >= 5 || type < 0) type = 0;

                cout << endl << "Please provide a sample question." << endl << YELLOW << ">> " << RESET;
                cin.get(sample, 100);
                cin.clear();
                cin.ignore(100, '\n');

                data = new preparation(title, details, type, sample);
                
                if (sample) delete[] sample;
                sample = nullptr;
            }

            else if (answer == 2) {//Practice Problems
            }

            else if (answer == 3) {//Study Concepts
            }

            else cout << endl << RED << "Invalid Input." << RESET << endl;

            node * inserting = new node(data);

            int ret = -1;
            try {
                ret = myActivities.insertData(inserting);
            }
            catch (activity*) {
                cout << endl << RED << "Unknown Error Occured. Tough Luck." << RESET << endl;
            }

            if (title) delete[] title;
            title = nullptr;

        }

        else if (answer == 2) {//Display
        }

        else if (answer == 3) {//Remove
        }

        else if (answer == 4) {//Retrieve and Edit
        }

        else if (answer == 5) running = false;

        else cout << endl << RED << "Invalid Input." << RESET << endl;
    }

    return 0;
}
