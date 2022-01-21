/* Omar Nassar
 * Portland State University CS202
 * January 11, 2022
 * Card classes that store information for cards and the derived different card types
 */

#ifndef card_h
#define card_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "player.h"

class card {//card base class
    public:
        //Constructors and destructors
        card();
        card(char * name = (char*)(""), std::string description = "", int energy = 0);
        card(const card &);
        ~card();

        void display() const;
        int removeEnergy(class player & removing);
        virtual int getType(); //Virtual function to get card type
        bool compare(const card * comparing);
        bool compare(const char * name);

    protected:
        //Basic card data
        char * name;
        std::string description;
        int energyRequired;
};

class attack : public card {
    public:
        //Additional Constructors
        attack();
        attack(char * name = (char*)(""), std::string description = "", int energy = 0, int power = 0);

        void display() const;
        int getType();
        int attackPlayer(class player & attacking);

    private:
        int power;
};

class spell : public card {
    public:
        //Additional Constructors
        spell();
        spell(char * name = (char*)(""), std::string description = "", int energy = 0, int energyRestored = 0);

        void display() const;
        int getType();
        int restore(class player & restoring);

    private:
        int energyRestored;
};

class defence : public card {
    public:
        //Additional Constructors
        defence();
        defence(char * name = (char*)(""), std::string description = "", int energy = 0, int healed = 0);

        void display() const;
        int getType();
        int healing(class player & healing);

    private: 
        int healed;
};

#endif
