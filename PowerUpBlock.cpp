#include "PowerUpBlock.h"

PowerUpBlock::PowerUpBlock(int x, int y, int width, int height, sf::RenderWindow& window, int health)
    : Obstacle(x, y, width, height, window) {
    isCollected = false; 
}

void PowerUpBlock::onCollision(Player& player) {
}

void PowerUpBlock::dropPowerUp(){
    sprite.setPosition(0.f, -1000.f);
    isCollected = true; 
}

void PowerUpBlock::set_health(int health){
    this->health = health;
}

int PowerUpBlock::get_health(){
    return health;
}

bool PowerUpBlock::get_IsCollected(){
    return isCollected; 
}

void PowerUpBlock::set_IsCollected(bool isCollected){
    this->isCollected = isCollected;
}