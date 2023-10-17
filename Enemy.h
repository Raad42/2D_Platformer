#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Obstacle.h"

class Enemy : public Obstacle {
private:
    bool isAlive;

public:
    Enemy(int x, int y, int width, int height, sf::RenderWindow& window);
    Enemy();
    void setAlive(bool status);

    void move();
    void draw(sf::RenderWindow& window);
    bool alive() const;  // Added this function
};

#endif