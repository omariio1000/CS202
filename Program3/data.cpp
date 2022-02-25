/* Omar Nassar
 * Portland State University CS202
 * February 22, 2022
 * Implementation for data class
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <map>

#include "data.h"
#include "colors.h"

using namespace std;
using namespace colors;

//just to remember which color is true or false and make code easier to read
static bool black = false;
static bool red = true;

node::node() {
    data = nullptr;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    red = true;
}

node::node(node * inParent, ski * inData, int inRanking) {
    data = inData;
    parent = inParent;
    ranking = inRanking;
    left = nullptr;
    right = nullptr;
    red = true;
}

node::node(ski * inData, int inRanking) {
    data = inData;
    ranking = inRanking;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    red = true;
}

node::node(const node& obj) {
    data = obj.data;
    left = obj.left;
    right = obj.right;
    parent = obj.parent;
    red = obj.red;
    ranking = obj.ranking;
}

node::~node() {
    if (data) delete data;
    //if (left) delete left;
    //if (right) delete right;

    data = nullptr;
    //left = nullptr;
    //right = nullptr;
}

ski* node::getData() {
    return data;
}

int node::getRank() {
    return ranking;
}

void node::setData(ski * inData, int inRank) {
    if (!inData) throw inData;
    if (inRank <= 0) throw inRank;

    if (data) delete data;
    data = inData;
    ranking = inRank;
    return;
}

node* node::getLeft() {
    return left;
}

node*& node::getLeftR() {
    return left;
}

void node::setLeft(node * inLeft) {
    left = inLeft;
    return;
}

node* node::getRight() {
    return right;
}

node*& node::getRightR() {
    return right;
}

void node::setRight(node * inRight) {
    right = inRight;
    return;
}

node* node::getParent() {
    return parent;
}

void node::setParent(node * inParent) {
    parent = inParent;
    return;
}

bool node::getColor() {
    return red;
}

void node::setColor(bool state) {
    red = state;
    return;
}

void node::displayVisual() {
    if (red) cout << RED;
    data -> displayVisual();
    cout << RESET;
    return;
}

void node::swap(node * swapping) {
    ski * temp = data;
    int tempRank = ranking;

    data = swapping -> data;
    ranking = swapping -> ranking;

    swapping -> data = temp;
    swapping -> ranking = tempRank;
    return;
}

node& node::operator = (const node& obj) {
    if (*this == obj) return *this;
    
    this -> data = obj.data;
    this -> ranking = obj.ranking;
    this -> left = obj.left;
    this -> right = obj.right;
    this -> parent = obj.parent;
    this -> red = obj.red;

    return *this;
}

node& node::operator = (const bool color) {
    this -> red = color;
    return *this;
}

bool node::operator == (const node& obj) const {
    if (this -> data == obj.data) return true;
    return false;
}

bool node::operator == (const int rank) const {
    if (ranking == rank) return true;
    return false;
}

bool node::operator == (const bool color) const {
    if (red == color) return true;
    return false;
}

bool node::operator == (const char * name) const {
    if (!name) return false;
    if(*data == name) return true;
    return false;
}

bool node::operator != (const node& obj) const {
    if (*this == obj) return false;
    return true;
}

bool node::operator != (const int rank) const {
    if (*this == rank) return false;
    return true;
}

bool node::operator != (const bool color) const {
    if (*this == color) return false;
    return true;
}

bool node::operator < (const node& obj) const {
    if (this -> ranking < obj.ranking) return true;
    return false;
}

bool node::operator < (const int rank) const {
    if (this -> ranking < rank) return true;
    return false;
}

bool node::operator <= (const node& obj) const {
    if (*this < obj || this -> ranking == obj.ranking) return true;
    return false;
}

bool node::operator <= (const int rank) const {
    if (*this == rank || *this < rank) return true;
    return false;
}

bool node::operator > (const node& obj) const {
    if (this -> ranking > obj.ranking) return true;
    return false;
}

bool node::operator > (const int rank) const {
    if (this -> ranking > rank) return true;
    return false;
}

bool node::operator >= (const node& obj) const {
    if (*this > obj || this -> ranking == obj.ranking) return true;
    return false;
}

bool node::operator >= (const int rank) const {
    if (*this == rank || *this > rank) return true;
    return false;
}

ostream& operator << (ostream& out, node& obj) {
    out << *obj.getData();
    out << "Rank: " << obj.ranking << endl;
    return out;
}

RBT::RBT() {
    root = nullptr;
}

RBT::RBT(const RBT& obj) {
    copyTree(obj.root);
}

RBT::~RBT() {
    if (root) removeAll();
    root = nullptr;
}

int RBT::insertData(node * inserting) {
    if (!inserting) throw inserting;
    if (inserting -> getRank() < 1) throw inserting -> getRank();
    if (!root) {
        root = inserting;
        root -> setColor(black);
        return 0;
    }
    return insertData(root, inserting, nullptr);
}

int RBT::insertData(node * current, node * inserting, node * parent) {
    if (!current) {
        current = inserting;
        inserting -> setParent(parent);
        //using relational ops to compare instead of needing to get data every time
        if (*current >= *parent) parent -> setRight(current);
        else parent -> setLeft(current);
        return balanceTree(current);
    }

    if (*inserting >= *current) return insertData(current -> getRight(), inserting, current);
    return insertData(current -> getLeft(), inserting, current);
}

int RBT::balanceTree(node * current) {//function to rebalance after tree is added
    node * parent = current -> getParent();
    node * grandparent = nullptr;

    while (current != root && *current != black && *parent == red) {
        parent = current -> getParent();
        grandparent = parent -> getParent();

        if (*parent < *grandparent) {//parent is a left child
            node * uncle = grandparent -> getRight();
            
            if (uncle && *uncle == red) {//uncle is red
                *grandparent = red;
                *parent = black;
                *uncle = black;
                current = grandparent;
            }

            else {//uncle either nonexistent or black
                if (*current >= *parent) {//current is a right child
                    rotate(parent, true);
                    current = parent;
                    parent = current -> getParent();
                }
                rotate(grandparent, false);
                bool temp = parent -> getColor();
                *parent = grandparent -> getColor();
                *grandparent = temp;
                current = parent;
            }
        }
        else {//parent is a right child
            node * uncle = grandparent -> getLeft();

            if (uncle && *uncle == red) {//uncle is red
                *grandparent = red;
                *parent = black;
                *uncle = black;
                current = grandparent;
            }

            else {//uncle either nonexistent or black
                if (*current < *parent) {//current is a left child
                    rotate(parent, false);
                    current = parent;
                    parent = current -> getParent();
                }

                rotate(grandparent, true);
                bool temp = parent -> getColor();
                *parent = grandparent -> getColor();
                *grandparent = temp;
                current = parent;
            }
        }
    }
    root -> setColor(black);
    return 1;
}

void RBT::rotate(node * current, bool LR) {//true is left, false is right
    if (LR) {
        node * right = current -> getRight();
        if (current == root) root = right;

        if (current -> getParent()) {
            if (*current < *(current -> getParent())) current -> getParent() -> setLeft(right);
            else current -> getParent() -> setRight(right);
        }

        right -> setParent(current -> getParent());
        current -> setParent(right);
        current -> setRight(right -> getLeft());

        if (right -> getLeft()) right -> getLeft() -> setParent(current);

        right -> setLeft(current);
    }
    else {
        node * left = current -> getLeft();

        if (current == root) root = left;

        if (current -> getParent()) {
            if (*current < *(current -> getParent())) current -> getParent() -> setLeft(left);
            else current -> getParent() -> setRight(left);
        }

        left -> setParent(current -> getParent());
        current -> setParent(left);

        current -> setLeft(left -> getRight());

        if (left -> getRight()) left -> getRight() -> setParent(current);

        left -> setRight(current);
    }
    return;
}

void RBT::displayAll() {
    if (!root) throw root;
    return displayAll(root);
}

void RBT::displayAll(node * current) {//inorder display all function
    if (!current) return;
    displayAll(current -> getLeft());
    cout << *current;
    displayAll(current -> getRight());
    return;
}

node* RBT::retrieve(int rank) {
    if (!root) throw root;
    return retrieve(root, rank);
}

node* RBT::retrieve(node * current, int rank) {
    if (!current) throw rank;
    if (*current == rank) return current;
    
    if (*current <= rank) return retrieve(current -> getRight(), rank);
    return retrieve(current -> getLeft(), rank);

}

node* RBT::retrieve(char * name) {
    if (!root) throw root;
    if (!name) throw name;
    return retrieve(root, name);
}

node* RBT::retrieve(node * current, char * name) {
    if (!current) return nullptr;
    if (*current == name) return current;

    node * left = retrieve(current -> getLeft(), name);
    node * right = retrieve(current -> getRight(), name);

    if (left) return left;
    if (right) return right;
    return nullptr;
}

void RBT::displaySingle(int ranking) {
    node * displaying = retrieve(ranking);
    if (!displaying) throw displaying;
    cout << *displaying;
}

void RBT::displaySingle(char * name) {
    node * displaying = retrieve(name);
    if (!displaying) throw displaying;
    cout << *displaying;
}

void RBT::visualDisplay() {
    if (!root) throw root;
    cout << endl;
    visualDisplay(root, nullptr, false);
    cout << endl;
    return;
}

//helper function for visual printing
void showTrunks(Trunk * p) {
    if (!p) return;

    showTrunks(p -> prev);

    cout << p -> str;
    return;
}

//adapted from my old RBT program from high school
//https://github.com/omariio1000/CS163/tree/master/RBT
void RBT::visualDisplay(node * root, Trunk * prev, bool isLeft) {
    if (!root) return;

    char * prev_str = (char *)("    ");
    Trunk * trunk = new Trunk(prev, prev_str);
    visualDisplay(root -> getLeft(), trunk, true);
    if (!prev)
        trunk -> str = (char *)("---");
    else if (isLeft) {
        trunk -> str = (char *)(".---");
        prev_str = (char *)("   |");
    }
    else {
        trunk -> str = (char *)("`---");
        prev -> str = prev_str;
    }
    showTrunks(trunk);
    root -> displayVisual();

    if (prev)
        prev -> str = prev_str;
    trunk -> str = (char *)("   |");
    visualDisplay(root -> getRight(), trunk, false);
    delete trunk;
}

void RBT::remove(int rank) {
    if (rank < 1) throw rank;
    node * removing = retrieve(rank);
    if (!removing) throw removing;
    return remove(removing);
}

void RBT::remove(char * name) {
    if (!name) throw name;
    node * removing = retrieve(name);
    if (!removing) throw removing;
    return remove(removing);
} 

//finding inorder successor and shifting data
node * inOrderSuccessor(node * root) {
    if (!root -> getLeft()) {//furthest to the left on subtree
        return root;
    }
    else return inOrderSuccessor(root -> getLeft());
}

bool hasRed(node * current) {
  if (current -> getLeft() && *(current -> getLeft()) == red) return true;
  if (current -> getRight() && *(current -> getRight()) == red) return true; 
  return false;
}

void RBT::fixDouble(node * current) {
    node * sibling = nullptr;
    node * parent = current -> getParent();
    bool LR;

    if (*current > *parent) {
        sibling = parent -> getLeft();
        LR = false;
    }
    else {
        sibling = parent -> getRight();
        LR = true;
    }

    if (!sibling) fixDouble(parent);
    else {
        if (*sibling == red) {
            *parent = red;
            *sibling = black;
            rotate(parent, LR);
            fixDouble(current);
        }
        else {
            if (hasRed(sibling)) {
                if (sibling -> getLeft() && *(sibling -> getLeft()) == red) {
                    if (*sibling < *parent) {
                        *(sibling -> getLeft()) = sibling -> getColor();
                        *sibling = parent -> getColor();
                        rotate(parent, false);
                    }
                    else {
                        *(sibling -> getLeft()) = parent -> getColor();
                        rotate(sibling, false);
                        rotate(parent, true);
                    }
                }
                else {
                    if (*sibling < *parent) {
                        *(sibling -> getRight()) = parent -> getColor();
                        rotate(sibling, true);
                        rotate(parent, false);
                    }
                    else {
                        *(sibling -> getRight()) = sibling -> getColor();
                        *sibling = parent -> getColor();
                        rotate(parent, true);
                    }
                }
                *parent = black;
            }
            else {
                *sibling = red;
                if (*parent == black) fixDouble(parent);
                else *parent = black;
            }
        }
    }
}

void RBT::remove(node * removing) {
    node * temp;
    if (!removing -> getRight() && !removing -> getLeft()) temp = nullptr;
    else if (!removing -> getLeft()) temp = removing -> getRight();
    else if (!removing -> getRight()) temp = removing -> getLeft();
    else temp = inOrderSuccessor(removing -> getRight());

    bool doubleBlack = false;

    node * parent = removing -> getParent();

    if (!temp) {
        if (*removing == black) fixDouble(removing);
        else {
            if (*removing >= *parent && parent -> getLeft()) *(parent -> getLeft()) = red;
            else if (parent -> getRight()) *(parent -> getRight()) = red;
        }

        //could tidy up if I used reference instead of pointer, but this works
        removing -> setLeft(nullptr);
        removing -> setRight(nullptr);
        if (removing == removing -> getParent() -> getRight()) removing -> getParent() -> setRight(nullptr);
        else if (removing == removing -> getParent() -> getLeft()) removing -> getParent() -> setLeft(nullptr);
        removing -> setParent(nullptr);
        delete removing;
        removing = nullptr;
        return;
    }

    if (*removing == black && *temp == black) doubleBlack = true;

    if (!removing -> getLeft() || !removing -> getRight()) {
        if (removing == root) {
            removing -> swap(temp);
            if (temp -> getRight()) {
                temp -> getParent() -> setRight(temp -> getRight());
                temp -> getRight() -> setParent(temp -> getParent());
            }
            temp -> setLeft(nullptr);
            temp -> setRight(nullptr);
            if (temp == temp -> getParent() -> getRight()) temp -> getParent() -> setRight(nullptr);
            else if (temp == temp -> getParent() -> getLeft()) temp -> getParent() -> setLeft(nullptr);
            temp -> setParent(nullptr);
            delete temp;
            temp = nullptr;
        }
        else {
            if (*removing < *parent) parent -> setLeft(temp);
            else parent -> setRight(temp);

            removing -> setLeft(nullptr);
            removing -> setRight(nullptr);

            if (removing == removing -> getParent() -> getRight()) removing -> getParent() -> setRight(nullptr);
            else if (removing == removing -> getParent() -> getLeft()) removing -> getParent() -> setLeft(nullptr);
            removing -> setParent(nullptr);
            
            delete removing;
            removing = nullptr;

            temp -> setParent(parent);
            if (doubleBlack) fixDouble(temp);
            else *temp = black;

        }
        return;
    }

    removing -> swap(temp);

    remove(temp);

}

void RBT::removeAll() {
    if (!root) return;
    removeAll(root);
}

void RBT::removeAll(node *& root) {//same as BST remove all
    if (!root) return;
    removeAll(root -> getLeftR());
    removeAll(root -> getRightR());
    delete root;
    root = nullptr;
}

void RBT::copyTree(node * source) {
    if (!source) return;
    if (root) removeAll(root);
    return copyTree(root, source);
}

void RBT::copyTree(node * dest, node * source) {//same as BST copy all
    if (!source) return;
    dest = new node(*source);
    copyTree(dest -> getLeft(), source -> getLeft());
    copyTree(dest -> getRight(), source -> getRight());
    return;
}

RBT& RBT::operator = (const RBT& obj) {
    copyTree(obj.root);
    return *this;
}

RBT& RBT::operator += (node* obj) {
    insertData(obj);
    return *this;
}

RBT RBT::operator + (node * obj) {
    RBT ret(*this);
    ret.insertData(obj);
    return ret;
}

data::data() {}

data::~data() {
    removeAll(false);
    removeAll(true);
}

int data::insertData(olympics * data, int rank) {
    if (!data) throw data;
    if (typeid(*data) == typeid(board)) {
        board * ptr = static_cast<board*> (data);
        snowBoarders.insert(pair<int, board*>(rank, ptr));
        return 0;
    }
    else if (typeid(*data) == typeid(hockey)) {
        hockey * ptr = static_cast<hockey*> (data);
        hockeyPlayers.insert(pair<int, hockey*>(rank, ptr));
        return 1;
    }
    else throw data;
}

bool data::displayAll(bool type) {
    bool something = false;
    if (type) {//board
        map<int, board*>::iterator m;
        for (m = snowBoarders.begin(); m != snowBoarders.end(); m++) {
            something = true;
            cout << *(m -> second);
            cout << "Rank: " << m -> first << endl;
        }
    }
    else {//hockey
        map<int, hockey*>::iterator m;
        for (m = hockeyPlayers.begin(); m != hockeyPlayers.end(); m++) {
            something = true;
            cout << *(m -> second);
            cout << "Rank: " << m -> first << endl;
        }
    }
    return something;
}

void data::displaySingle(int ranking, bool type) {
    if (ranking < 1) throw ranking;
    bool found = false;
    if (type) {//board
        map<int, board*>::iterator m;
        for (m = snowBoarders.begin(); m != snowBoarders.end(); m++) {
            if (ranking == m -> first) {
                found = true;
                cout << *(m -> second);
                cout << "Rank: " << m -> first << endl;
            }
        }
    }
    else {//hockey
        map<int, hockey*>::iterator m;
        for (m = hockeyPlayers.begin(); m != hockeyPlayers.end(); m++) {
            found = true;
            if (ranking == m -> first) {
                cout << *(m -> second);
                cout << "Rank: " << m -> first << endl;
            }

        }
    }
    if (!found) throw type;
}

void data::displaySingle(char * name, bool type) {
    if (!name) throw name;
    bool found = false;
    if (type) {//board
        map<int, board*>::iterator m;
        for (m = snowBoarders.begin(); m != snowBoarders.end(); m++) {
            if (*(m -> second) == name) {
                found = true;
                cout << *(m -> second);
                cout << "Rank: " << m -> first << endl;
            }
        }
    }
    else {//hockey
        map<int, hockey*>::iterator m;
        for (m = hockeyPlayers.begin(); m != hockeyPlayers.end(); m++) {
            if (*(m -> second) == name) {
                found = true;
                cout << *(m -> second);
                cout << "Rank: " << m -> first << endl;
            }
        }
    }
    if (!found) cout << endl << RED << "No athlete was found with that name." << RESET << endl;
}

olympics* data::retrieve (int ranking, bool type) {
    if (ranking < 1) throw ranking;
    if (type) {//board
        map<int, board*>::iterator m;
        for (m = snowBoarders.begin(); m != snowBoarders.end(); m++) {
            if (ranking == m -> first) return m -> second;
        }
    }
    else {//hockey
        map<int, hockey*>::iterator m;
        for (m = hockeyPlayers.begin(); m != hockeyPlayers.end(); m++) {
            if (ranking == m -> first) return m -> second;
        }
    }
    return nullptr;
}


olympics* data::retrieve (char * name, bool type) {
    if (!name) throw name;
    if (type) {//board
        map<int, board*>::iterator m;
        for (m = snowBoarders.begin(); m != snowBoarders.end(); m++) {
            if (*(m -> second) == name) return m -> second;
        }
    }
    else {//hockey
        map<int, hockey*>::iterator m;
        for (m = hockeyPlayers.begin(); m != hockeyPlayers.end(); m++) {
            if (*(m -> second) == name) return m -> second;
        }
    }
    return nullptr;
}

bool data::remove(int ranking, bool type) {
    if (ranking < 1) throw ranking;
    if (type) {//board
        map<int, board*>::iterator m;
        for (m = snowBoarders.begin(); m != snowBoarders.end(); m++) {
            if (m -> first == ranking) {
                if (m -> second) delete m -> second;
                snowBoarders.erase(m);
                return true;
            }
        }
    }
    else {//hockey
        map<int, hockey*>::iterator m;
        for (m = hockeyPlayers.begin(); m != hockeyPlayers.end(); m++) {
            if (m -> first == ranking) {
                if (m -> second) delete m -> second;
                hockeyPlayers.erase(m);
                return true;
            }
        }

    }
    return false;
}

bool data::remove(char * name, bool type) {
    if (!name) throw name;
    if (type) {//board
        map<int, board*>::iterator m;
        for (m = snowBoarders.begin(); m != snowBoarders.end(); m++) {
            if (*(m -> second) == name) {
                if (m -> second) delete m -> second;
                snowBoarders.erase(m);
                return true;
            }
        }
    }
    else {//hockey
        map<int, hockey*>::iterator m;
        for (m = hockeyPlayers.begin(); m != hockeyPlayers.end(); m++) {
            if (*(m -> second) == name) {
                if (m -> second) delete m -> second;
                hockeyPlayers.erase(m);
                return true;
            }
        }

    }
    return false;
}

void data::removeAll(bool type) {
    if (type) {//board
        map<int, board*>::iterator m;
        for (m = snowBoarders.begin(); m != snowBoarders.end(); m++) 
            if (m -> second) delete m -> second;
        snowBoarders.clear();
    }
    else {//hockey
        map<int, hockey*>::iterator m;
        for (m = hockeyPlayers.begin(); m != hockeyPlayers.end(); m++)
            if (m -> second) delete m -> second;
        hockeyPlayers.clear();
    }
}
