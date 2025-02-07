#include "BoundingBox.h"

BoundingBox::BoundingBox(const sf::Sprite& sprite) {
    // gets the box bounds and creates a bounding box
    rect = sprite.getGlobalBounds();
    shape.setSize(sf::Vector2f(rect.width, rect.height));
    shape.setPosition(rect.left, rect.top);
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(2);
}

void BoundingBox::update(const sf::Sprite& sprite) {
    // changes to bounding box gets updated when moved
    rect = sprite.getGlobalBounds();
    shape.setSize(sf::Vector2f(rect.width, rect.height));
    shape.setPosition(rect.left, rect.top);
}

void BoundingBox::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

bool BoundingBox::intersects(const BoundingBox& other) const {
    return rect.intersects(other.rect);
}

sf::FloatRect BoundingBox::getFloatRect() const {
    return rect;
}