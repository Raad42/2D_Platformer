#include "Enemy.h"

Enemy::Enemy(int x, int y, int width, int height, int health, int damage, const std::string& name)
    : Character(x, y, width, height, health, damage, name) {
    // Initialize enemy-specific members here.
}

Enemy::Enemy()
    : Character(0, 0, 0, 0, 0, 0, "") {
    // Initialize enemy-specific members here.
}

void Enemy::move() {
    // Implement enemy movement logic here.
}

void Enemy::attack() {
    // Implement enemy attack logic here.
}
