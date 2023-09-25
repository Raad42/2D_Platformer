#include "Entity.h"

#include <iostream>

Entity::Entity(int x, int y, int width, int height) {
    this->x_position = x;
    this->y_position = y;
    this->width = width;
    this->height = height;
}

Entity::~Entity() {}

int Entity::get_x_position() {
    return this->x_position;
}

int Entity::get_y_position() {
    return this->y_position;
}

int Entity::get_width() {
    return this->width;
}

int Entity::get_height() {
    return this->height;
}

void Entity::set_texture(const std::string& texturePath) {
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "Failed to load texture from file: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
}

sf::Sprite& Entity::getSprite() {
    return sprite;
}