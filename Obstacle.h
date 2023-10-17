#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Obstacle : public Entity {
private:
    // allows obstacles to be displayed in window
    sf::RenderWindow& window;
public:
    Obstacle();
    Obstacle(int x, int y, int width, int height, sf::RenderWindow& window);
    ~Obstacle();

};

#endif
