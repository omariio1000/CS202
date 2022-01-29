/* Omar Nassar
 * Portland State University CS202
 * January 11, 2022
 * File input class to parse and add cards
 */

#ifndef files_h
#define files_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "card.h"
#include "player.h"

class files {//File input class
    public:
        files(); //constructor
        int readFile(std::string fileName, std::vector<card*> & cards);
};

namespace colors {
    #define RESET   "\033[0m"
    #define RED     "\033[31m"
    #define GREEN   "\033[32m"
    #define YELLOW  "\033[33m"
    #define BLUE    "\033[34m"
    #define MAGENTA "\033[35m"
    #define CYAN    "\033[36m"
};

#endif
