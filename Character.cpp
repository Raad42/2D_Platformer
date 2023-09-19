#include "Character.h"

Character::Character() {
    health = 0;
    damage = 0;
    name = "null";
}

int Character::getHealth() const {
    return health;
}

void Character::setHealth(int health) {
    this->health = health;
}

int Character::getDamage() const {
    return damage;
}

std::string Character::getName() const {
    return name;
}
