#ifndef DAMAGINGOBSTACLE_H
#define DAMAGINGOBSTACLE_H

#include "Obstacle.h"

class DamagingObstacle : public Obstacle {
private:
    int damage;
public:
    DamagingObstacle(int x, int y, int width, int height, sf::RenderWindow& window, int damageIn);
    
    // getters and setters
    void set_damage(int damageIn);
    int  get_damage();
};


#endif