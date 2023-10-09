#include "Obstacle.h"

Obstacle::Obstacle(int x, int y, int width, int height, sf::RenderWindow& window)
    : Entity(x, y, width, height), window(window) {
}

Obstacle::Obstacle()
    : Entity(0, 0, 0, 0), window(window) {
}

Obstacle::~Obstacle() {}