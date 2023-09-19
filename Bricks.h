#ifndef BRICKS_H
#define BRICKS_H

#include <SFML/Graphics.hpp>
#include "Obstacle.h"

class Bricks : public Obstacle {
public:
    Bricks(const sf::Texture& texture, const sf::Vector2f& position);
};

#endif
