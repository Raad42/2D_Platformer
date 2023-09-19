#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Entity.h"

class Character : public Entity {
protected:
    int health;
    int damage;
    std::string name;

public:
    Character();
    int getHealth() const;
    void setHealth(int health);
    int getDamage() const;
    std::string getName() const;
};

#endif
