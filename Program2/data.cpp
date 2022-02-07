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
    if (previous) delete previous;

    data = nullptr;
    next = nullptr;
    previous = nullptr;
}

activity* node::getData() {
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
