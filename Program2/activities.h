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

class activity {
    public:
        activity();
        activity(char * title, std::string details);
        virtual ~activity();

        virtual void display();
        virtual int setData(char * title, std::string details);

    protected:
        char * title;
        std::string details;
};

class preparation : public activity {
    public:
        preparation();
        preparation(char * title, std::string details, int type, int difficulty, char * sample);
        ~preparation();

        void display();
        int setData(char * title, std::string details, int type, int difficulty, char * sample);
        
    private:
        int type;
        int difficulty;
        char * sample;
};

class problems : public activity {
    public: 
        problems();
        problems(char * title, std::string details, std::string prototype, int difficulty); 
};

class concepts : public activity {
};

#endif
