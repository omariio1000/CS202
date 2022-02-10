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
            cout << GREEN << "2: Programming Practice Problems" << endl;
            cout << MAGENTA << "3: Concepts to Study" << endl;
            cout << YELLOW << ">> " << RESET;

            cin >> answer;
            cin.clear();
            cin.ignore(100, '\n');

            activity * data = nullptr;;

            char * title = new char[100];
            string details;

            cout << endl << "What is the title of the activity?" << endl << YELLOW << ">> " << RESET;
            cin.get(title, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What are the details of the activity?" << endl << YELLOW << ">> " << RESET;
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
                cin.clear();
                cin.ignore(100, '\n');
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
                string prototype;

                cout << endl << "Please provide a prototype." << endl << YELLOW << ">> " << RESET;
                cin >> prototype;
                cin.clear();
                cin.ignore(100, '\n');

                data = new problems(title, details, prototype);
            }

            else if (answer == 3) {//Study Concepts
                int proficiency;

                cout << endl << "How proficient are you at this concept? (integer value) " << endl << YELLOW << ">> " << RESET;
                cin >> proficiency;
                cin.clear();
                cin.ignore(100, '\n');

                data = new concepts(title, details, proficiency);
            }

            else cout << endl << RED << "Invalid Input." << RESET << endl;

            if (data) {
                node * inserting = new node(data);

                int ret = -1;
                try {
                    ret = myActivities.insertData(inserting);
                }
                catch (activity*) {
                    cout << endl << RED << "Unknown Error Occured. Tough Luck." << RESET << endl;
                }

                if (ret == 0) cout << endl << CYAN << "Successfully Added Exam Prep Question." << RESET << endl;
                else if (ret == 1) cout << endl << GREEN << "Successfully Added Programming Practice Problem." << RESET << endl;
                else if (ret == 2) cout << endl << MAGENTA << "Successfully Added Concept to Study." << RESET << endl;
                else cout << RED << "Object of Unknown Type Added." << RESET << endl;
            }

            if (title) delete[] title;
            title = nullptr;

        }

        else if (answer == 2) {//Display
            cout << endl << "Would you like to:" << endl;
            cout << "1: Display All" << endl;
            cout << "2: Display By Type" << endl << YELLOW << ">> " << RESET;

            cin >> answer;
            cin.clear();
            cin.ignore(100, '\n');

            if (answer == 1) myActivities.displayAll();
            else if (answer == 2) {//Display By Type
                cout << endl << "What type would you like to display?" << endl;
                cout << CYAN << "1: Exam Prep Question" << endl;
                cout << GREEN << "2: Programming Practice Problems" << endl;
                cout << MAGENTA << "3: Concepts to Study" << endl;
                cout << YELLOW << ">> " << RESET;

                cin >> answer;
                cin.clear();
                cin.ignore(100, '\n');

                answer--;
                try {
                    myActivities.displayType(answer);
                }
                catch (int) {
                    cout << endl << RED << "Invalid Input." << RESET << endl;
                }

            }
            else cout << endl << RED << "Invalid Input." << endl << RESET;
        }

        else if (answer == 3) {//Remove
            cout << endl << "Would you like to:" << endl;
            cout << "1: Remove All" << endl;
            cout << "2: Remove By Type" << endl;
            cout << "3: Remove Single" << endl << YELLOW << ">> " << RESET;

            cin >> answer;
            cin.clear();
            cin.ignore(100, '\n');

            if (answer == 1) myActivities.removeAll();
            else if (answer == 2) {//Display By Type
                cout << endl << "What type would you like to remove?" << endl;
                cout << CYAN << "1: Exam Prep Question" << endl;
                cout << GREEN << "2: Programming Practice Problems" << endl;
                cout << MAGENTA << "3: Concepts to Study" << endl;
                cout << YELLOW << ">> " << RESET;

                cin >> answer;
                cin.clear();
                cin.ignore(100, '\n');

                answer--;
                try {
                    myActivities.removeType(answer);
                }
                catch (int) {
                    cout << endl << RED << "Invalid Input." << RESET << endl;
                }

            }
            else if (answer == 3) {//Remove Single
                char * title = new char[100];
                int type = -1;
                int ret = -1;

                cout << endl << "What type is it?" << endl;
                cout << CYAN << "1: Exam Prep Question" << endl;
                cout << GREEN << "2: Programming Practice Problems" << endl;
                cout << MAGENTA << "3: Concepts to Study" << endl;
                cout << YELLOW << ">> " << RESET;

                cin >> type;
                cin.clear();
                cin.ignore(100, '\n');
                type--;

                cout << endl << "What is the title? (Case Sensitive)" << endl << YELLOW << ">> " << RESET;
                cin.get(title, 100);
                cin.clear();
                cin.ignore(100, '\n');

                try {
                    ret = myActivities.remove(title, type);
                }
                catch (int) {
                    cout << endl << RED << "Invalid Type Selected." << RESET << endl;
                }
                catch (char*) {
                    cout << endl << RED << "Invalid Title Inputted." << RESET << endl;
                }

                if (ret == 1) cout << endl << GREEN << "Successfully Removed." << RESET << endl;
                else if (ret == 0) cout << endl << RED << "Nothing Found With That Title." << RESET << endl;
                else cout << endl << RED << "Nothing Removed." << RESET << endl;
                
                if (title) delete title;
                title = nullptr;
            }
            else cout << endl << RED << "Invalid Input." << endl << RESET;

        }

        else if (answer == 4) {//Retrieve and Edit
            char * title = new char[100];

            cout << endl << "What type of activity would you like to retrieve?" << endl;
            cout << CYAN << "1: Exam Prep Question" << endl;
            cout << GREEN << "2: Programming Practice Problems" << endl;
            cout << MAGENTA << "3: Concepts to Study" << endl;
            cout << YELLOW << ">> " << RESET;

            cin >> answer;
            cin.clear();
            cin.ignore(100, '\n');
            answer--;

            cout << endl << "What is the title? (Case Sensitive)" << endl << YELLOW << ">> " << RESET;
            cin.get(title, 100);
            cin.clear();
            cin.ignore(100, '\n');

            activity * myActivity = nullptr;
            try {
                myActivity = myActivities.retrieve(title, answer);
            }
            catch (int) {
                cout << endl << RED << "Invalid Type Selected." << RESET << endl;
            }
            catch (char*) {
                cout << endl << RED << "Invalid Title Inputted." << RESET << endl;
            }
            catch (node*) {
                cout << endl << RED << "Nothing Found With That Title." << RESET << endl;
            }

            if (myActivity) {//If retrieved
                myActivity -> display();
                if (answer == 0) {//exam prep
                    //should be able to mark as completed
                    cout << endl << "Would you like to mark this as completed? (y/n)" << RESET << endl;
                    cout << YELLOW << ">> ";

                    char yesno;
                    cin >> yesno;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (yesno == 'y' || yesno == 'Y') dynamic_cast<preparation*> (myActivity) -> markCompleted(true);
                    else if (yesno == 'n' || yesno == 'N') dynamic_cast<preparation*> (myActivity) -> markCompleted(false);
                    else cout << RED << endl << "Invalid Input." << RESET << endl;

                }
                
                else if (answer == 1) {//practice problem
                    //should be able to answer question
                    cout << endl << "Would you like to answer the question? (y/n)" << endl;
                    cout << YELLOW << ">> " << RESET;

                    char yesno;
                    cin >> yesno;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (yesno == 'y' || yesno == 'Y') {
                        string answer;
                        cout << endl << "What is the answer?" << endl << YELLOW << ">> " << RESET;
                        cin >> answer;
                        cin.clear();
                        cin.ignore(100, '\n');

                        int ret = -1;
                        try {
                            ret = dynamic_cast<problems*> (myActivity) -> answerQuestion(answer);
                        }
                        catch (string) {
                            cout << endl << RED << "Invalid Input." << endl << RESET;
                        }
                        
                        if (ret == 1) cout << endl << GREEN << "Problem Answered Successfully." << RESET << endl;
                        else cout << endl << RED << "Problem Not Answered." << RESET << endl;
                    }
                    else if (yesno != 'n' || yesno != 'N') cout << RED << endl << "No answer given." << RESET << endl;
                }

                else if (answer == 2) {//study concepts
                    //should be able to change proficiency, edit details, or mark completed
                    cout << endl << "Would you like to:" << endl;
                    cout << "1: Change Proficiency Level" << endl;
                    cout << "2: Edit Details" << endl;
                    cout << "3: Change Completion Status" << endl << YELLOW << ">> " << RESET;

                    cin >> answer;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (answer == 1) {//change proficiency level
                        cout << endl << "What is your new proficiency level?" << endl << YELLOW << ">> " << RESET;
                        cin >> answer;
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            answer = dynamic_cast<concepts*> (myActivity) -> setProficiency(answer);
                            cout << GREEN << endl << "Proficiency Level Set to " << answer << RESET << endl;
                        }
                        catch (int) {
                            cout << RED << endl << "Proficiency Level Cannot Be Below Zero." << RESET << endl;
                        }

                    }

                    else if (answer == 2) {//edit details
                        string details;
                        cout << endl << "What would you like to change the details to?" << endl << YELLOW << ">> " << RESET;
                        cin >> details;
                        cin.clear();
                        cin.ignore(100, '\n');

                        try {
                            dynamic_cast<concepts*> (myActivity) -> editDetails(details);
                            cout << endl << GREEN << "Details Updated Successfully." << RESET << endl;
                        }
                        catch (int) {
                            cout << endl << RED << "Details Cannot be Empty!" << RESET << endl;
                        }
                    }

                    else if (answer == 3) {//mark completed
                        cout << endl << "Would you like to mark this as completed? (y/n)" << endl << YELLOW << ">> " << RESET;
                        char yesno;
                        cin >> yesno;
                        cin.clear();
                        cin.ignore(100, '\n');

                        if (yesno == 'y' || yesno == 'Y') {
                            dynamic_cast<concepts*> (myActivity) -> markCompleted(true);
                            cout << endl << GREEN << "Marked As Completed." << RESET << endl;
                        }

                        else if (yesno == 'n' || yesno == 'N') {
                            dynamic_cast<concepts*> (myActivity) -> markCompleted(false);
                            cout << endl << YELLOW << "Marked as Incomplete." << RESET << endl;
                        }

                        else cout << endl << RED << "Invalid Input." << RESET << endl;
                    }
                }

                else cout << endl << RED << "This shouldn't happen..." << RESET << endl;
            }

            if (title) delete title;
            title = nullptr;
            myActivity = nullptr;
        }

        else if (answer == 5) running = false;

        else cout << endl << RED << "Invalid Input." << RESET << endl;
    }

    myActivities.removeAll();

    return 0;
}
