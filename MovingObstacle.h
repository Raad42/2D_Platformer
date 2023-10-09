#ifndef MOVINGOBSTACLE_H
#define MOVINGOBSTACLE_H

#include "Obstacle.h"

class MovingObstacle : public Obstacle {
private:
    float velocityX;
    float velocityY;
    bool moveUp; 
    // Add moving obstacle-specific members here.
public:
    MovingObstacle(int x, int y, int width, int height, sf::RenderWindow& window, float velocityXIn, float velocityYIn);
    void update() override;
    // Additional attributes and methods for moving obstacles.
};

#endif