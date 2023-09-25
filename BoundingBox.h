#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <SFML/Graphics.hpp>

class BoundingBox {
private:
    sf::FloatRect rect;
    sf::RectangleShape shape;

public:
    BoundingBox(const sf::Sprite& sprite);
    void update(const sf::Sprite& sprite);
    void draw(sf::RenderWindow& window) const;
    bool intersects(const BoundingBox& other) const;
};

#endif
