#include "BoundingBox.h"

BoundingBox::BoundingBox(const sf::Sprite& sprite) {
    rect = sprite.getGlobalBounds();

    shape.setSize(sf::Vector2f(rect.width, rect.height));
    shape.setPosition(rect.left, rect.top);

    // Set the visual properties of the bounding box, for mainly for debugging purposes
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(2);
}

// Update the bounding box based on the sprite's current state
void BoundingBox::update(const sf::Sprite& sprite) {
    rect = sprite.getGlobalBounds();
    shape.setSize(sf::Vector2f(rect.width, rect.height));
    shape.setPosition(rect.left, rect.top);
}

void BoundingBox::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

// Check if this bounding box intersects with another
bool BoundingBox::intersects(const BoundingBox& other) const {
    return rect.intersects(other.rect);
}

// Get the underlying FloatRect of the bounding box
sf::FloatRect BoundingBox::getFloatRect() const {
    return rect;
}
