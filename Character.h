#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstring>
#include <iostream>
#include "Abstract.h"

class Character: public Abstract{
    private: 
        int health;
        int damage; 
        std::string name; 
    public: 
};

#endif