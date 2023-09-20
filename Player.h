#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "PowerUp.h"
#include <SFML/Graphics.hpp>

class Player : public Character {
private:
    // Add player-specific members here.
public:
    Player(int x, int y, int width, int height, int health, int damage, const std::string& name);
    Player();

    void moveLeft();
    void moveRight();
    void jump();
    void fall();
    void attack();
    void collectPowerUp(PowerUp power_up);


};


#endif
