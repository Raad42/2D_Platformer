#ifndef DAMAGINGOBSTACLE_H
#define DAMAGINGOBSTACLE_H

#include "Obstacle.h"

class DamagingObstacle : public Obstacle {
private:
    int damage;
    // Add damaging obstacle-specific members here.
public:
    DamagingObstacle(int x, int y, int width, int height, int damage);
    // Additional attributes and methods for damaging obstacles.
};


#endif