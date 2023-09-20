#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Obstacle : public Entity {
protected:
    sf::RectangleShape shape;
public:
    Obstacle(int x, int y, int width, int height);
    virtual void update();
    virtual void draw(sf::RenderWindow& window);
    // Common attributes and methods for collision, rendering, etc.
};



#endif
