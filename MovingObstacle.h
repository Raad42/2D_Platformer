#ifndef MOVINGOBSTACLE_H
#define MOVINGOBSTACLE_H

#include "Obstacle.h"

class MovingObstacle : public Obstacle {
private:
    float velocityX;
    float velocityY;

    float maxPosition; 
    float minPosition; 
    bool moveUp; 


    // Add moving obstacle-specific members here.
public:
    MovingObstacle(int x, int y, int width, int height, sf::RenderWindow& window, float velocityXIn, float velocityYIn, float maxPosition, float minPosition);
    void update();
    // Additional attributes and methods for moving obstacles.
};

#endif