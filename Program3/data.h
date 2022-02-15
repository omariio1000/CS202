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

#include "olympics.h"

class node {
    public:
        node();
        node(node * parent);
        node(ski * data);
        node(const node&);
        ~node();

        ski * getData();
        void setData(ski * data, int ranking);

        node *& getLeft();
        void setLeft(node * left);

        node *& getRight();
        void setRight(node * right);

        node *& getParent();
        void setParent(node * parent);

        bool getState();
        void setState(bool state);

        bool operator == (const node&) const;
        bool operator != (const node&) const;
        bool operator < (const node&) const;
        bool operator <= (const node&) const;
        bool operator > (const node&) const;
        bool operator >= (const node&) const;

        friend ostream& operator << (ostream&, const node&);

    private:
        ski * data;
        int ranking;
        node * left;
        node * right;
        node * parent;
        bool redBlack();
};

class RBT {
    public:
        RBT();
        RBT(const RBT&);
        ~RBT();

        int insertData(node * inserting);
        int balanceTree();
        int displayAll();
        int displaySingle(int ranking);
        int displaySingle(char * name);
        node *& retrieve(int ranking);
        node *& retrieve(char * name);
        int remove(int ranking);
        int remove(char * name);
        int copyTree();

        RBT& operator += (node*&);

    private:
        node * root;
};

class data {
    public:
        data();
        data(const data&);
        ~data();

        int insertData(olympics * data);
        int displayAll();
        int displaySingle(int ranking);
        int displaySingle(char * single);
        olympics *& retrieve(int ranking);
        olympics *& retrieve(char * name);
        int remove(int ranking);
        int remove(char * name);

    private:
        vector<board*> snowboarders;
        vector<hockey*> hockeyPlayers;
}

#endif
