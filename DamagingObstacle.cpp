#include "DamagingObstacle.h"

// obstacle handles the attributes that come from obstacle class
DamagingObstacle::DamagingObstacle(int x, int y, int width, int height, sf::RenderWindow& window, int damageIn)
    : Obstacle(x, y, width, height, window), damage(damageIn) {
}

int DamagingObstacle::get_damage(){
    return damage;
}
