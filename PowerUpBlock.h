#ifndef POWERUPBLOCK_H
#define POWERUPBLOCK_H

#include "Obstacle.h"
#include "Player.h"

class PowerUpBlock : public Obstacle {
private:
    int health; // when it runs out of health drops powerup
public:
    PowerUpBlock(int x, int y, int width, int height, sf::RenderWindow& window, int health);
    void onCollision(Player& player);

    void dropPowerUp();
    void set_health(int health);
    int get_health();
    // Additional attributes and methods specific to power-up blocks.

};

#endif