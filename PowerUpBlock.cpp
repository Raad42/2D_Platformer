#include "PowerUpBlock.h"

PowerUpBlock::PowerUpBlock(int x, int y, int width, int height, sf::RenderWindow& window)
    : Obstacle(x, y, width, height, window), health(99) {
    // Initialize power-up block-specific members here.
}

void PowerUpBlock::onCollision(Player& player) {
}

void PowerUpBlock::dropPowerUp(){
    sprite.setPosition(0.f, -1000.f);
}