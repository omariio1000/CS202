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
        ~olympics();
        int setData(char* name, std::string nation, int age, int weight, int height, int[] medals);

        olympics& operator = (const olympics&);
        
        bool operator == (const olympics&) const;
        bool operator == (const char * name) const;
        bool operator != (const olympics&) const;
        bool operator != (const char * name) const;
        //bool operator < (const olympics&) const;
        //bool operator <= (const olympics&) const;
        //bool operator > (const olympics&) const;
        //bool operator >= (const olympics&) const;

        friend ostream& operator << (ostream&, const olympics&);

    protected:
        olympics();
        olympics(const olympics&);

        char * name;
        string nation;
        int age;
        int weight;
        int height;
        int medals[3];
};

class ski : public olympics {//derived class for skiing
    public: 
        ski();
        ski(const ski&);

        int setData(char * name, std::string nation, int age, int weight, int height, int[] medals, int time);
        int setSponsor(std::string sponsor);

        ski& operator = (const ski&);
        
        bool operator == (const ski&) const;
        bool operator != (const ski&) const;

        friend ostream& operator << (ostream&, const ski&);

    private:
        int time;
        std::string sponsor;
};

class board : public olympics {//derived class for snowboarding
    public: 
        board();
        board(const ski&);

        int setData(char * name, std::string nation, int age, int weight, int height, int[] medals, int time);
        int setSponsor(std::string);

        board& operator = (const board&);

        bool operator == (const board&) const;
        bool operator != (const board&) const;

        friend ostream& operator << (ostream&, const board&);

    private:
        int time;
        std::string sponsor;

};

class hockey : public olympics {//derived class for hockey
    public: 
        hockey();
        hockey(const hockey&);

        int setData(char * name, std::string nation, int age, int weight, int height, int[] medals, std::string position);
        int setTeam(std::string);

        hockey& operator = (const hockey&);

        bool operator == (const hockey&) const;
        bool operator != (const hockey&) const;

        friend ostream& operator << (ostream&, const hockey&);

    private:
        std::string team;
        std::string position;

};

#endif olympics_h
