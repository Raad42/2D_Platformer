#include "DamagingObstacle.h"

DamagingObstacle::DamagingObstacle(int x, int y, int width, int height, sf::RenderWindow& window, int damageIn)
    : Obstacle(x, y, width, height, window), damage(damageIn) {
    // Initialize damaging obstacle-specific members here.
}

int DamagingObstacle::get_damage(){
    return damage;
}
