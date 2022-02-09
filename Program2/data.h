/* Omar Nassar
 * Portland State Universiy CS202
 * January 31, 2022
 * Data structure class that has node and array of DLLs
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

#include "activities.h"

class node {//DLL node class
    public:
        node();
        node(activity * data);
        node(const node & node);
        ~node();
        
        activity *& getData();
        void setData(activity * data);

        node *& getNext();
        void setNext(node * next);

        node *& getPrevious();
        void setPrevious(node * previous);

        void display() const;
        bool compare(char * title) const;
        bool compare(const activity * comp) const;

    private:
        activity * data; //data being stored is an activity/question
        node * next;
        node * previous;
};

class ADLL {//Class for array of DLLs data structure
    public:
        ADLL(int types = 3);
        ADLL(const ADLL & obj);
        ~ADLL();

        int insertData(node *& inserting);
        int remove(char * title, int type);
        void displayAll() const;
        void displayType(int type) const;
        activity *&  retrieve(char * title, int type);
        void removeAll();
        void removeType(int type);

    private:
        node ** questions; //double pointer for array of pointers
        int types; //different types of activities
        
        //Recursive Functions (yet to add)
        void copyDLL(node *& destination, node * source, node * previous);
        int insertData(node *& current, node * previous, node *& inserting, int type);
        int remove(node *& current, char * title);
        activity *& retrieve(node * current, char * title);
        void displayType(node * displaying) const;
};

#endif
