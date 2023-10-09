#include "MovingObstacle.h"
#include <SFML/Graphics.hpp>

MovingObstacle::MovingObstacle(int x, int y, int width, int height, sf::RenderWindow& window, float velocityXIn, float velocityYIn)
    : Obstacle(x, y, width, height, window), velocityX(velocityXIn), velocityY(velocityYIn){
        moveUp = true;
    // Initialize moving obstacle-specific members here.
}

void MovingObstacle::update() {
    if (moveUp) {
        // Move up until a certain point is reached (e.g., y < 100)
        if (get_y_position() > 100) {
            set_x_position(get_x_position() - velocityX); 
            set_y_position(get_y_position() - velocityY);
        } else {
            // Change direction when the upper limit is reached
            moveUp = false;
        }
    } else {
        // Move down until another point is reached (e.g., y > 800)
        if (get_y_position() < 800) {
            set_x_position(get_x_position() + velocityX); 
            set_y_position(get_y_position() + velocityY);
        } else {
            // Change direction when the lower limit is reached
            moveUp = true;
        }
    }

    getSprite().setPosition(get_x_position(), get_y_position());
}
