#include "PowerUpBlock.h"

PowerUpBlock::PowerUpBlock(int x, int y, int width, int height)
    : Obstacle(x, y, width, height) {
    // Initialize power-up block-specific members here.
}

void PowerUpBlock::onCollision(Player& player) {
    // Custom behavior for power-up block collision with the player.
    // Implement power-up behavior here.
}
