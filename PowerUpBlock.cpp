#include "PowerUpBlock.h"

PowerUpBlock::PowerUpBlock(int x, int y, int width, int height, sf::RenderWindow& window, int health)
    : Obstacle(x, y, width, height, window) {
    // Initialize power-up block-specific members here.
}

void PowerUpBlock::onCollision(Player& player) {
}

void PowerUpBlock::dropPowerUp(){
    sprite.setPosition(0.f, -1000.f);
}

void PowerUpBlock::set_health(int health){
    this->health = health;
}

int PowerUpBlock::get_health(){
    return health;
}