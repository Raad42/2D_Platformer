#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics.hpp>

class Bricks {
private:
    sf::Sprite sprite;

public:
    Bricks(const sf::Texture& texture, const sf::Vector2f& position);
    void draw(sf::RenderWindow& window);
    sf::Sprite getSprite() const;
};

#endif
