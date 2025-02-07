#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <string>

class Character : public Entity {
private:
    // health and damage
    int health;
    int damage;
    std::string name;
public:
    Character(int x, int y, int width, int height, int health, int damage, const std::string& name);
    Character();
    
    // functions to alter attributes
    int get_health() const;
    void set_health(int health);
    int get_damage() const;
    std::string get_name() const;
};


#endif
