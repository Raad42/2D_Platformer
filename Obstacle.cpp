#include "Obstacle.h"

Obstacle::Obstacle(int x, int y, int width, int height, sf::RenderWindow& window)
    : Entity(x, y, width, height), window(window) {
}

Obstacle::Obstacle()
    : Entity(0, 0, 0, 0), window(window) {
}

Obstacle::~Obstacle() {}

bool Obstacle::IsColliding(Entity* other) {
    // Your collision detection logic here
    // If a collision is detected, return true; otherwise, return false
    if (1) {
        return true;
    } else {
        return false; // or return false if no collision
    }
}


// Implement the OnCollision function in the Player class
void Obstacle::OnCollision(Entity* other) {
    // Add collision response logic specific to the Player class here
    // For example, handle what happens when the player collides with 'other'.
}

void Obstacle::update(){

}