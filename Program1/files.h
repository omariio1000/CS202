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

#endif
