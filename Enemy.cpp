#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int x, int y, int width, int height, sf::RenderWindow& window)
    : Obstacle(x, y, width, height, window), isAlive(true) {
}

void Enemy::move() {
    // Implement enemy movement logic here
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(getSprite());
}

void Enemy::setAlive(bool status) {
    isAlive = status;
}

bool Enemy::alive() const {
    return isAlive;
}
