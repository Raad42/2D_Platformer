#include "PowerUpBlock.h"

PowerUpBlock::PowerUpBlock(int x, int y, int width, int height, sf::RenderWindow& window)
    : Obstacle(x, y, width, height, window), health(99) {
    // Initialize power-up block-specific members here.
}

void PowerUpBlock::onCollision(Player& player) {
    // Custom behavior for power-up block collision with the player.
    // Implement power-up behavior here.
}

void PowerUpBlock::dropPowerUp(){
    if (health <= 0){
        sprite.setPosition(0.f, -1000.f);
    }
}