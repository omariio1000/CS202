/* Omar Nassar
 * Portland State University CS202
 * January 31, 2022
 * Implemenation for data class
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "data.h"
#include "colors.h"

using namespace std;
using namespace colors;

node::node() {
    data = nullptr;
    next = nullptr;
    previous = nullptr;
}

node::node(activity * inData) {
    data = inData;
}

node::node(const node & obj) {
    data = obj.data;
    next = obj.next;
    previous = obj.previous;
}

node::~node() {
    if (data) delete data;
    if (next) delete next;

    data = nullptr;
    next = nullptr;
    previous = nullptr;
}

activity *& node::getData() {
    return data;
}

void node::setData(activity * inData) {
    data = inData;
    return;
}

node*& node::getNext() {
    return next;
}

void node::setNext(node * inNext) {
    next = inNext;
    return;
}

node*& node::getPrevious() {
    return previous;
}

void node::setPrevious(node * inPrevious) {
    previous = inPrevious;
    return;
}

void node::display() const {
    try {
        data -> display();
    }
    catch (char*) {
        cout << endl << RED << "There is no title for some reason." << RESET << endl;
    }
    catch (string) {
        cout << endl << RED << "There are no details for some reason." << RESET << endl;
    }
    return;
}

bool node::compare(char * title) const {
    return data -> compare(title);
}

bool node::compare(const activity * comp) const {
    return data -> compare(comp);
}

ADLL::ADLL(int inTypes) {
    types = inTypes;
    questions = new node*[types];
    for (int i = 0; i < types; i++) {
        questions[i] = nullptr;
    }
}

ADLL::ADLL(const ADLL & obj) {
    types = obj.types;
    questions = new node*[types];
    for (int i = 0; i < types; i++) {
        questions[i] = nullptr;
        copyDLL(questions[i], obj.questions[i], nullptr);
    }
}

void ADLL::copyDLL(node *& dest, node * source, node * prev) {
    if (!source) return;

    dest = new node(source -> getData());
    dest -> setPrevious(prev);
    return copyDLL(dest -> getNext(), source -> getNext(), dest);
}

ADLL::~ADLL() {
    for (int i = 0; i < types; i++) {
        if (questions[i]) delete questions[i];
        questions[i] = nullptr;
    }
    delete[] questions;
    questions = nullptr;
}

int ADLL::insertData(node *& inserting) {
    activity * data = inserting -> getData();

    if (typeid(*data) == typeid(preparation))
        return insertData(questions[0], nullptr, inserting, 0); 

    else if (typeid(*data) == typeid(problems)) 
        return insertData(questions[1], nullptr, inserting, 1);

    else if (typeid(*data) == typeid(concepts))
        return insertData(questions[2], nullptr, inserting, 2);

    else throw data;
}

int ADLL::insertData(node *& current, node * prev, node *& inserting, int type) {
    if (!current) {
        current = inserting;
        inserting -> setPrevious(prev);
        return type;
    }

    return insertData(current -> getNext(), current, inserting, type);
}

int ADLL::remove(char * title, int type) {
    if (!title) throw title;
    if (type < 0 || type > 2) throw type;
    return remove(questions[type], title);
}

int ADLL::remove(node *& current, char * title) {
    if (!current) return 0;

    if (current -> compare(title)) {
        if (current -> getPrevious()) current -> getPrevious() -> setNext(current -> getNext());
        if (current -> getNext()) current -> getNext() -> setPrevious(current -> getPrevious());

        current -> setPrevious(nullptr);
        current -> setNext(nullptr);

        delete current;
        current = nullptr;

        return 1;
    }

    return remove(current -> getNext(), title);
}

activity *& ADLL::retrieve(char * title, int type) {
    if (!title) throw title;
    if (type < 0 || type > 2) throw type;
    return retrieve(questions[type], title);
}

activity *& ADLL::retrieve(node * current, char * title) {
    if (!current) throw current;

    if (current -> compare(title)) return current -> getData();

    return retrieve(current -> getNext(), title);
}

void ADLL::displayAll() const {
    for (int i = 0; i < types; i++) {
        displayType(i);
    }
    return;
}

void ADLL::displayType(int type) const {
    if (type < 0 || type > 2) throw type;
    displayType(questions[type]);
    return;
}

void ADLL::displayType(node * displaying) const {
    if (!displaying) return;
    displaying -> display();
    return displayType(displaying -> getNext());
}

void ADLL::removeAll() {
    for (int i = 0; i < types; i++) {
        removeType(i);
    }
    return;
}

void ADLL::removeType(int type) {
    if (type < 0 || type > 2) throw type;
    if (!questions[type]) return;

    delete questions[type];
    questions[type] = nullptr;

    return;
}
