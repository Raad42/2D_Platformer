//for obstacle collision
#include "GameTest.h"
#include <iostream>

// Obstacle (brick) Implementation
sf::FloatRect Obstacle::getBoundingbox() {
    return sf::FloatRect(15, 15, 20, 20);  // This bounding box intersects with Mario's
}

// Game Implementation
Game::Game() : marioBounds(10, 10, 20, 20) {}  // Initialize Mario's bounding box

void Game::handleCollisions() {
    sf::FloatRect brickBounds = brick.getBoundingbox();

    if (marioBounds.intersects(brickBounds)) {
        std::cout << "Mario collided with the brick!" << std::endl;
    } else {
        std::cout << "No collision detected." << std::endl;
    }
}

int main() {
    Game game;
    game.handleCollisions();
    return 0;
}
