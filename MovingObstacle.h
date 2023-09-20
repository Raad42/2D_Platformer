#ifndef MOVINGOBSTACLE_H
#define MOVINGOBSTACLE_H

#include "Obstacle.h"

class MovingObstacle : public Obstacle {
private:
    // Add moving obstacle-specific members here.
public:
    MovingObstacle(int x, int y, int width, int height);
    virtual void update() override;
    // Additional attributes and methods for moving obstacles.
};

#endif