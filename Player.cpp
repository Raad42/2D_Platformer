#include "Player.h"
#include "PowerUp.h"

Player::Player(int x, int y, int width, int height, int health, int damage, const std::string& name, sf::RenderWindow& window)
    : Character(x, y, width, height, health, damage, name), window(window) {
    x = 0;
    y = 0;
    velocityX = 0;
    velocityY = 0;
    accelerationX = 0;
    accelerationY = 0;
    
    gravity = 1;
}

Player::Player()
    : Character(0, 0, 0, 0, 0, 0, ""), window(window) {
    // Initialize player-specific members here.
}

void Player::moveLeft() {
    velocityX = -3;
}

void Player::moveRight() {
    velocityX = 3;
}

void Player::jump() {
    velocityY = -20;
}

void Player::fall() {
    // Implement falling logic here.
}

void Player::attack() {
    // Implement attack logic here.
}

void Player::handleInput() {
    // Check for user input events (e.g., keyboard keys)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        moveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        moveRight();
    }
    else {
        // If neither left nor right keys are pressed, stop horizontal movement.
        velocityX = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        jump();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        attack();
    }

    // You can add more input handling here for other actions.

    // Update other player-specific input handling if needed.
}

void Player::update() {
    // Update the player's position and physics.
    // Apply acceleration and gravity.
    velocityX += accelerationX;
    velocityY += accelerationY + gravity;

    // Update the player's position based on velocity.
    x += velocityX;
    y += velocityY;

    float scale = 0.1f;
    float playerWidth = sprite.getLocalBounds().width * scale;
    float playerHeight = sprite.getLocalBounds().height * scale;

    if (x < 0) {
        x = 0;
        velocityX = 0; // Stop horizontal movement when the player hits the left border
    }
    if (x + playerWidth > window.getSize().x) {
        x = window.getSize().x - playerWidth;
        velocityX = 0; // Stop horizontal movement when the player hits the right border
    }
    if (y < 0) {
        y = 0;
        velocityY = 0; // Stop vertical movement when the player hits the top border
    }
    if (y + playerHeight > window.getSize().y) {
        y = window.getSize().y - playerHeight;
        velocityY = 0; // Stop vertical movement when the player hits the bottom border
    }


    // Check for collisions with the ground or obstacles and handle accordingly.
    // You'll need to implement collision detection and response here.

    // Update other game-specific logic, animations, etc.
    sprite.setScale(scale, scale);
}



void Player::collectPowerUp(PowerUp power_up) {
    // Implement power-up collection logic here.
}

// Implement the IsColliding function in the Player class
bool Player::IsColliding(Entity* other) {
    // Your collision detection logic here
    // If a collision is detected, return true; otherwise, return false
    if (1) {
        return true;
    } else {
        return false; // or return false if no collision
    }
}


// Implement the OnCollision function in the Player class
void Player::OnCollision(Entity* other) {
    // Add collision response logic specific to the Player class here
    // For example, handle what happens when the player collides with 'other'.
}