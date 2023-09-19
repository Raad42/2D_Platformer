#include "Entity.h"

void Entity::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::Sprite Entity::getSprite() const {
    return sprite;
}
