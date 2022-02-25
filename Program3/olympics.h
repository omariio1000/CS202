/* Omar Nassar
 * Portland State University CS202
 * February 22, 2022
 * Olympic activities classes (base + derived)
 */

#ifndef olympics_h
#define olympics_h 

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

class olympics {//base class for olympic activities
    public:
        virtual ~olympics();
        int setData(char* name, std::string nation, int age, int weight, int height, int medals[]);
        void displayVisual();

        //operators
        olympics& operator = (const olympics&);
        
        bool operator == (const olympics&) const;
        bool operator == (const char * name) const;
        bool operator != (const olympics&) const;
        bool operator != (const char * name) const;
        //bool operator < (const olympics&) const;
        //bool operator <= (const olympics&) const;
        //bool operator > (const olympics&) const;
        //bool operator >= (const olympics&) const;

        //friend std::ostream& operator << (std::ostream&, const olympics&);
        
        //print function for base class
        void print(std::ostream&);

    protected:
        //protected constructors
        olympics();
        olympics(const olympics&);

        //data members
        char * name;
        std::string nation;
        int age;
        int weight;
        int height;
        int medals[3];
};

class ski : public olympics {//derived class for skiing
    public: 
        ski();
        ski(const ski&);

        int setData(char * name, std::string nation, int age, int weight, int height, int medals[], int time);
        int setSponsor(std::string sponsor);

        //operators
        ski& operator = (const ski&);
        
        //bool operator == (const ski&) const;
        //bool operator != (const ski&) const;

        friend std::ostream& operator << (std::ostream&, ski&);

    private:
        int time;
        std::string sponsor;
};

class board : public olympics {//derived class for snowboarding
    public: 
        board();
        board(const board&);

        int setData(char * name, std::string nation, int age, int weight, int height, int medals[], int time);
        int setSponsor(std::string);

        //operators
        board& operator = (const board&);

        //bool operator == (const board&) const;
        //bool operator != (const board&) const;

        friend std::ostream& operator << (std::ostream&, board&);

    private:
        int time;
        std::string sponsor;

};

class hockey : public olympics {//derived class for hockey
    public: 
        hockey();
        hockey(const hockey&);

        int setData(char * name, std::string nation, int age, int weight, int height, int medals[], std::string position);
        int setTeam(std::string team);

        //operators
        hockey& operator = (const hockey&);

        //bool operator == (const hockey&) const;
        //bool operator != (const hockey&) const;

        friend std::ostream& operator << (std::ostream&, hockey&);

    private:
        std::string team;
        std::string position;

};

#endif
