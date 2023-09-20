#include "Entity.h"

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
