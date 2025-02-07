#ifndef POWERUPBLOCK_H
#define POWERUPBLOCK_H

#include "Obstacle.h"
#include "Player.h"

class PowerUpBlock : public Obstacle {
private:
    int health; // when it runs out of health drops powerup
    bool isCollected; 
public:
    PowerUpBlock(int x, int y, int width, int height, sf::RenderWindow& window, int health);
    void onCollision(Player& player);

    void dropPowerUp();
    void set_health(int health);
    int get_health();

    bool get_IsCollected();
    void set_IsCollected(bool isCollected);
};

#endif