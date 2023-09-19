#include "Bricks.h"

Bricks::Bricks(const sf::Texture& texture, const sf::Vector2f& position) {
    sprite.setTexture(texture);
    sprite.setScale(0.4f, 0.2f);
    sprite.setPosition(position);
}
