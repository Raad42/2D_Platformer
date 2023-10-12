#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int x, int y, int width, int height, int health, int damage, const std::string& name, const std::string& texturePath)
    : Character(x, y, width, height, health, damage, name), isAlive(true) {
    if(!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

Enemy::Enemy() : Character(0, 0, 0, 0, 0, 0, ""), isAlive(true) {
    // The default constructor remains empty since you don't have specific logic here.
}

void Enemy::move() {
    sprite.move(-1, 0);
    if (sprite.getPosition().x + sprite.getGlobalBounds().width < 0) {
        isAlive = false;
    }
}

void Enemy::attack() {
    // Logic for enemy attack (not implemented here)
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Enemy::setAlive(bool status) {
    isAlive = status;
}

bool Enemy::alive() const {
    return isAlive;
}