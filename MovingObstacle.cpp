#include "MovingObstacle.h"

MovingObstacle::MovingObstacle(int x, int y, int width, int height)
    : Obstacle(x, y, width, height) {
    // Initialize moving obstacle-specific members here.
}

void MovingObstacle::update() {
    // Specialized update logic for moving obstacles.
    // Update position or behavior here.
    // Call the base class's update function for common behavior.
    Obstacle::update();
}
