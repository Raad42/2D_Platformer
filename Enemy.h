#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Obstacle.h"

// inherit from obstacle instead of character
class Enemy : public Obstacle {
private:
    bool isAlive;

public:
    Enemy(int x, int y, int width, int height, sf::RenderWindow& window);
    Enemy();

    // functions for move, draw and if enemy alive
    void setAlive(bool status);
    void move();
    void draw(sf::RenderWindow& window);
    bool alive() const;
};

#endif