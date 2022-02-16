/* Omar Nassar
 * Portland State University CS202
 * February 22, 2022
 * Data class for node and balanced tree (RBT)
 */

#ifndef data_h
#define data_h 

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <map>

#include "olympics.h"

class node {
    public:
        //constructors and destructors
        node();
        node(node * parent, ski * data, int rank);
        node(ski * data, int rank);
        node(const node&);
        ~node();

        //getters and setters
        ski * getData();
        int getRank();
        void setData(ski * data, int ranking);

        node *& getLeft();
        void setLeft(node * left);

        node *& getRight();
        void setRight(node * right);

        node *& getParent();
        void setParent(node * parent);

        //for red-black tree
        bool getColor();
        void setColor(bool color);

        void displayVisual();
        void swap(node * swapping);

        //operators
        node& operator = (const node&);
        node& operator = (const bool color);

        bool operator == (const node&) const;
        bool operator == (const int rank) const;
        bool operator == (const bool color) const;
        bool operator == (const char * name) const;
        bool operator != (const node&) const;
        bool operator != (const int rank) const;
        bool operator != (const bool color) const;
        bool operator < (const node&) const;
        bool operator < (const int rank) const;
        bool operator <= (const node&) const;
        bool operator <= (const int rank) const;
        bool operator > (const node&) const;
        bool operator > (const int rank) const;
        bool operator >= (const node&) const;
        bool operator >= (const int rank) const;

        friend std::ostream& operator << (std::ostream&, node&);

    private:
        ski * data;
        int ranking;
        node * left;
        node * right;
        node * parent;
        bool red;
};

//helper struct for visual display
struct Trunk {
    Trunk * prev;
    char * str;

    Trunk(Trunk * prev, char * str) {
        this -> prev = prev;
        this -> str = str;
    }
};

class RBT {//red black tree class
    public:
        RBT();
        RBT(const RBT&);
        ~RBT();

        int insertData(node * inserting);
        int balanceTree(node * current);
        void rotate(node * current, bool LR);
        void displayAll();
        void displaySingle(int ranking);
        void displaySingle(char * name);
        void visualDisplay();
        node * retrieve(int ranking);
        node * retrieve(char * name);
        void remove(int ranking);
        void remove(char * name);
        void removeAll();
        void copyTree(node * source);
        void fixDouble(node * current);

        RBT& operator = (RBT&);
        RBT& operator += (node*);

    private:
        node * root;

        //will still implement recursive functions
        int insertData(node * current, node * inserting, node * parent);
        void displayAll(node * current);
        node * retrieve(node * current, int ranking);
        node * retrieve(node * current, char * name);
        void visualDisplay(node * root, Trunk * prev, bool isLeft);
        void removeAll(node * root);
        void copyTree(node *& dest, node * source);
        void remove(node * removing);
};

class data {//other data structures
    public:
        data();
        //data(const data&);
        ~data();

        int insertData(olympics * data, int rank);
        void displayAll(bool type);
        void displaySingle(int ranking, bool type);
        void displaySingle(char * name, bool type);
        olympics * retrieve(int ranking, bool type);
        olympics * retrieve(char * name, bool type);
        bool remove(int ranking, bool type);
        bool remove(char * name, bool type);
        void removeAll(bool type);

    private:
        std::map<int, board*> snowBoarders;
        std::map<int, hockey*> hockeyPlayers;
};

#endif
