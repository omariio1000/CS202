/* Omar Nassar
 * Portland State University CS202
 * January 31, 2022
 * Activities class that store base activity and derived classes
 */

#ifndef activities_h
#define activities_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

class activity {//Base class for activities/questions
    public:
        activity();
        activity(char * title, std::string details);
        activity(const activity & activity);
        virtual ~activity();//Virtual destructor because of virtual functions

        //Virtual functions eliminate need for dynamic cast
        virtual void display() const;
        virtual int setData(char * title, std::string details);

    protected:
        char * title;
        std::string details;
};

class preparation : public activity {//Derived exam prep questions
    public:
        preparation();
        preparation(char * title, std::string details, int type, int difficulty, char * sample);
        preparation(const preparation & prep);
        ~preparation();

        void display() const;
        int setData(char * title, std::string details, int type, int difficulty, char * sample);
        
    private:
        int type;
        int difficulty;
        char * sample;
};

class problems : public activity {//Derived practice problems
    public: 
        problems();
        problems(char * title, std::string details, std::string prototype, int difficulty); 

        void display() const;
        int setData(char * title, std::string details, std::string prototype, int difficulty);

    private:
        int difficulty;
        std::string prototype;
};

class concepts : public activity {//Derived concepts for future study
    public:
        concepts();
        concepts(char * title, std::string details);

        void display() const;
        int setData(char * title, std::string details, int proficiency);

    private:
        int proficiency;
};

#endif
