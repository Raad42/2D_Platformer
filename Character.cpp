#include "Character.h"

// constructor
Character::Character(int x, int y, int width, int height, int health, int damage, const std::string& name)
    : Entity(x, y, width, height) {
    this->health = health;
    this->damage = damage;
    this->name = name;
}

Character::Character()
    : Entity(0, 0, 0, 0) {
    this->health = 0;
    this->damage = 0;
    this->name = "";
}

int Character::get_health() const {
    return this->health;
}

void Character::set_health(int health) {
    this->health = health;
}

int Character::get_damage() const {
    return this->damage;
}

std::string Character::get_name() const {
    return this->name;
}
