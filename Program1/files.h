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

class files {
    public:
        files();
        int readFile(std::string fileName, std::vector<card*> & cards);
};

#endif
