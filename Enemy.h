#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Character.h"

class Enemy : public Character {
private:
    // Add enemy-specific members here.
public:
    Enemy(int x, int y, int width, int height, int health, int damage, const std::string& name);
    Enemy();

    void move();
    void attack();
};

#endif
