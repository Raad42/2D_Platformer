#include "Obstacle.h"

// Constructor: Initializes an Obstacle with specified properties and a reference to the window.
Obstacle::Obstacle(int x, int y, int width, int height, sf::RenderWindow& window)
    : Entity(x, y, width, height), window(window) {
}

Obstacle::Obstacle()
    : Entity(0, 0, 0, 0), window(window) {
}

Obstacle::~Obstacle() {}
