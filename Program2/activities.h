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
        virtual ~activity();//Virtual destructor because of virtual functions

        //Virtual functions eliminate need for dynamic cast
        virtual void display() = 0 const;
        virtual int setData() = 0;
        virtual int editDetails() = 0;
        virtual int markCompleted() = 0;
        virtual int rateDifficulty() = 0;

    protected:
        activity();
        activity(char * title, std::string details);
        activity(const activity & activity);

        char * title;
        std::string details;
        int difficulty = -1;
};

class preparation : public activity {//Derived exam prep questions
    public:
        preparation();
        preparation(char * title, std::string details, int type, char * sample);
        preparation(const preparation & prep);
        ~preparation();

        void display() const;
        int setData(char * title, std::string details, int type, char * sample);
        int rateDifficulty(int difficulty);
        bool markCmpleted(bool completed);
        
        
    private:
        int type = -1;
        char * sample;
        bool completed;
};

class problems : public activity {//Derived practice problems
    public: 
        problems();
        problems(char * title, std::string details, std::string prototype); 

        void display() const;
        int setData(char * title, std::string details, std::string prototype);
        int answerQuestion(std::string answer);
        int rateDifficulty(int difficulty);

    private:
        std::string prototype;
        std::string answer;
};

class concepts : public activity {//Derived concepts for future study
    public:
        concepts();
        concepts(char * title, std::string details);

        void display() const;
        int setData(char * title, std::string details, int proficiency);
        int editDetails(std::string details);
        int rateDifficulty(int difficulty);
        bool markCompleted(bool completed);

    private:
        int proficiency;
        bool completed;
};

#endif
