#ifndef CHARACTER_H
#define CHARACTER_H

#include <cstring>
#include <iostream>
#include "Entity.h"

class Character: public Entity{
    private: 
        int health;
        int damage; 
        std::string name; 
    public: 
};

#endif