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
    delete title;
    title = nullptr;
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

    sample = new char[stlen(prep.sample) + 1];
    strcpy(sample, prep.sample);
}

preparation::~preparation() {
    delete sample;
    sample = nullptr;
}

preparation::display() const {
    cout << endl << "Title: " << title << endl;
    cout << "Details: " << details << endl;
    //still need to do type stuff
    cout << "Difficulty: " << difficulty << endl;
    if (!answer.empty()) cout << "Here's the answer: " << endl;
    if (completed) cout << "This question is marked as completed." << endl;
}

int preparation::setData(char * inTitle, std::string inDetails, int inType, char * inSample) {
    if (!inTitle || !inSample || inDetails.empty()) return 0;

    if (title) delete title;
    if (sample) delete sample;
    if (!details.empty()) details.erase();
    
    title = new char[strlen(inTitle) + 1];
    strcpy(title, inTitle);

    sample = new char[strlen(inSample) + 1];
    strcpy(sample, inSample);

    details = inDetails;
    type = inType;

    return 1;
}

int preparation::rateDifficulty(int inDifficulty) {
    difficulty = inDifficulty;
    return difficulty;
}

bool preparation::markCompleted(bool inCompleted) {
    completed = inCompleted;
    return completed;
}
