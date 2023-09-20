#include "Obstacle.h"

Obstacle::Obstacle(int x, int y, int width, int height)
    : Entity(x, y, width, height) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    // Initialize other common attributes here.
}

void Obstacle::update() {
    // Common update logic for all obstacles.
    // Update position, behavior, or other attributes here.
}

void Obstacle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
