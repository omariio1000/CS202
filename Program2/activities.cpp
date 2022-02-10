/* Omar Nassar
 * Portland State University CS202
 * January 31, 2022
 * Implemenation for activities class
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
#include "colors.h"

using namespace colors;
using namespace std;

activity::activity() {
    title = nullptr;
}

activity::activity(char * inTitle, string inDetails) {
    title = new char[strlen(inTitle) + 1];
    strcpy(title, inTitle);

    details = inDetails;
}

activity::activity(const activity & activity) {
    title = new char[strlen(activity.title) + 1];
    strcpy(title, activity.title);

    details = activity.details;
}

activity::~activity() {
    if (title) delete title;
    title = nullptr;
}

void activity::display() const {//throws char * and string
    if (!title) throw title;
    if (details.empty()) throw details;
    
    cout << endl << "Title: " << title << RESET << endl;
    cout << "Details: " << details << endl;
    if (difficulty > 0) cout << "Difficulty: " << difficulty << endl;
    return;
}

int activity::rateDifficulty(int inDifficulty) {
    difficulty = inDifficulty;
    return difficulty;
}

bool activity::compare(char * inTitle) const {
    if (strcmp(title, inTitle) == 0) return true;
    return false;
}

bool activity::compare(const activity * comp) const {
    if (strcmp(title, comp -> title) == 0) return true;
    return false;
}

preparation::preparation() : activity() {
    sample = nullptr;
}

preparation::preparation(char * title, string details, int inType, char * inSample) : activity(title, details) {
    type = inType;

    sample = new char[strlen(inSample) + 1];
    strcpy(sample, inSample);
}

preparation::preparation(const preparation & prep) : activity(prep) {
    type = prep.type;

    if (prep.sample) {
        sample = new char[strlen(prep.sample) + 1];
        strcpy(sample, prep.sample);
    }
    else sample = nullptr;
}

preparation::~preparation() {//virtual function because handles dynamic memory
    if (sample) delete sample;
    sample = nullptr;
}

void preparation::display() const {//virtual function
    cout << CYAN;
    activity::display();

    if (type == 1) cout << "Type: Quiz Prep" << endl;
    else if (type == 2) cout << "Type: Midterm Prep" << endl;
    else if (type == 3) cout << "Type: Final Prep" << endl;
    else if (type == 4) cout << "Type: Proficiency Demo Prep" << endl;
    if (sample) cout << "Here's a sample question: " << sample << endl;
    if (completed) cout << "This question is marked as completed." << endl;
    return;
}

int preparation::setData(char * inTitle, string inDetails, int inType, char * inSample) {
    if (!inTitle || !inSample || inDetails.empty()) return 0;

    if (title) delete title;
    if (sample) delete sample;

    title = new char[strlen(inTitle) + 1];
    strcpy(title, inTitle);

    sample = new char[strlen(inSample) + 1];
    strcpy(sample, inSample);

    details = inDetails;
    type = inType;

    return 1;
}

bool preparation::markCompleted(bool inCompleted) {
    completed = inCompleted;
    return completed;
}

problems::problems() : activity() {}

problems::problems(char * inTitle, string inDetails, string inPrototype) : activity(inTitle, inDetails) {
    prototype = inPrototype;
}

void problems::display() const {//virtual function
    cout << GREEN;
    activity::display(); 
    if (!prototype.empty()) cout << "Here's the prototype: " << prototype << endl;
    if (!answer.empty()) cout << GREEN << "Here's the answer: " << RESET << endl;
    return;
}

int problems::setData(char * inTitle, string inDetails, string inPrototype) {
    if (!inTitle || inDetails.empty() || inPrototype.empty()) return 0;

    if (title) delete title;

    title = new char[strlen(inTitle) + 1];
    strcpy(title, inTitle);

    details = inDetails;
    prototype = inPrototype;

    return 1;
}

int problems::answerQuestion(string inAnswer) {//throws string
    if (inAnswer.empty()) throw inAnswer;

    if (!answer.empty()) answer.erase();

    answer = inAnswer;

    return 1;
}

concepts::concepts() : activity() {}

concepts::concepts(char * title, string details, int inProficiency) : activity(title, details) {
    proficiency = inProficiency;
}

void concepts::display() const {//virtual function
    cout << MAGENTA;
    activity::display();
    if (proficiency >= 0) cout << "Your proficiency level: " << proficiency << endl;
    if (completed) cout << GREEN << "This concept is marked as completed." << RESET << endl;
    return; 
}

int concepts::setData(char * inTitle, string inDetails, int inProficiency) {
    if (!inTitle || inDetails.empty()) return 0;

    if (title) delete title;

    title = new char[strlen(inTitle) + 1];
    strcpy(title, inTitle);

    details = inDetails;

    if (inProficiency >= 0) proficiency = inProficiency;

    return 1;
}

int concepts::setProficiency(int inProficiency) {//throws int
    if (inProficiency < 0) throw inProficiency;

    proficiency = inProficiency;
    return proficiency;
}

int concepts::editDetails(string inDetails) {//throws string
    if (inDetails.empty()) throw inDetails;
    details = inDetails;
    return 1;
}

bool concepts::markCompleted(bool inCompleted) {
    completed = inCompleted;
    return completed;
}
