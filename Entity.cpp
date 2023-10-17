#include "Entity.h"

#include <iostream>

Entity::Entity(int x, int y, int width, int height) : boundingBox(sprite) {
    this->x_position = x;
    this->y_position = y;
    this->width = width;
    this->height = height;
}

Entity::~Entity() {}

int Entity::get_x_position() {
    return this->x_position;
}

void Entity::set_x_position(int x_position) {
    this->x_position = x_position;
}

int Entity::get_y_position() {
    return this->y_position;
}

void Entity::set_y_position(int y_position) {
    this->y_position = y_position;
}

int Entity::get_width() {
    return this->width;
}

int Entity::get_height() {
    return this->height;
}

// loads texture and applies it to the sprite
void Entity::set_texture(const std::string& texturePath) {
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "Failed to load texture from file: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
}

sf::Sprite& Entity::getSprite() {
    return sprite;
}

void Entity::updateBoundingBox() {
    boundingBox.update(sprite);
}

sf::FloatRect Entity::getBoundingbox() const {
    return sprite.getGlobalBounds();
}