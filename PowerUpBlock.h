#ifndef POWERUPBLOCK_H
#define POWERUPBLOCK_H

#include "Obstacle.h"
#include "Player.h" // Include Player class if needed for collision handling

class PowerUpBlock : public Obstacle {
public:
    PowerUpBlock(int x, int y, int width, int height);
    void onCollision(Player& player);
    // Additional attributes and methods specific to power-up blocks.

private:
    int health; // when it runs out of health drops powerup

};

#endif