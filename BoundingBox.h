#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <SFML/Graphics.hpp>

class BoundingBox {
private:
    // attributes to create the bounding box
    sf::FloatRect rect;
    sf::RectangleShape shape;

public:
    BoundingBox(const sf::Sprite& sprite);
    void update(const sf::Sprite& sprite); // updates changes to bounding box
    void draw(sf::RenderWindow& window) const; // draw function to display on screen
    bool intersects(const BoundingBox& other) const; // used for collision logic

    sf::FloatRect getFloatRect() const; // used to create collision logic

};

#endif
