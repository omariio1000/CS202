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
        virtual ~activity(); //Virtual destructor because of virtual functions

        virtual void display() const; //virtual display so no dynamic cast needed
        int rateDifficulty(int difficulty); //rating question difficulty
        bool compare(char * title) const; //checking for retrieve and delete
        bool compare(const activity * comp) const; //checking for retrieve and delete but with object

    protected:
        //protected constructors so that only derived classes can use them
        activity();
        activity(char * title, std::string details);
        activity(const activity & activity);

        char * title;
        std::string details;
        int difficulty = -1;
};

class preparation : public activity {//Derived exam prep questions
    public:
        //constructors and destructor
        preparation();
        preparation(char * title, std::string details, int type, char * sample);
        preparation(const preparation & prep);
        ~preparation();

        void display() const;
        int setData(char * title, std::string details, int type, char * sample);
        bool markCompleted(bool completed);
        
        
    private:
        int type;
        char * sample;
        bool completed;
};

class problems : public activity {//Derived practice problems
    public: 
        //constructors
        problems();
        problems(char * title, std::string details, std::string prototype); 

        void display() const;
        int setData(char * title, std::string details, std::string prototype);
        int answerQuestion(std::string answer);

    private:
        std::string prototype;
        std::string answer;
};

class concepts : public activity {//Derived concepts for future study
    public:
        //constructors
        concepts();
        concepts(char * title, std::string details, int proficiency);

        void display() const;
        int setData(char * title, std::string details, int proficiency);
        int setProficiency(int proficiency);
        int editDetails(std::string details);
        bool markCompleted(bool completed);

    private:
        int proficiency = -1;
        bool completed;
};

#endif
