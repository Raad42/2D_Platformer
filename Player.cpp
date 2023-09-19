#include "Player.h"
#include <iostream>

Player::Player(float startX, float startY) {
    x = startX;
    y = startY;
    velocityX = 0;
    velocityY = 0;
    accelerationX = 0;
    accelerationY = 0;
    gravity = 1;
    isJumping = false;
    isGrounded = false;
}

void Player::loadTexture(const std::string& texturePath) {
    // Load the player's texture
    if (!playerTexture.loadFromFile(texturePath)) {
        std::cout << "Failed to load player texture." << std::endl;
        // Handle the error appropriately, e.g., by setting a default texture.
    }

    // Set the texture for the player's sprite
    Mario.setTexture(playerTexture);
    Mario.setScale(0.05f, 0.05f);

    // Initialize the bounding box
    boundingBoxMario = BoundingBox(Mario);
}

// Rest of the Player class methods (handleInput, update, draw, etc.)


void Player::handleInput() {
    // Handle player input (e.g., left, right, jump)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocityX = -3;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocityX = 3;
    }
    else {
        velocityX = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping && isGrounded) {
        velocityY = -20;
        isJumping = true;
    }
}

void Player::update() {
    // Update player position, apply gravity, handle collisions, etc.
    velocityY += gravity;
    x += velocityX;
    y += velocityY;

    // Boundary checks to keep the sprite within the window
    if (x < 0) {
        x = 0;
        velocityX = 0;  // Stop horizontal movement when the sprite hits the left border
    }
    if (x + Mario.getLocalBounds().width * 0.1f > gameWorldWidth) {
        x = gameWorldWidth - Mario.getLocalBounds().width * 0.1f;
        velocityX = 0;  // Stop horizontal movement when the sprite hits the right border
    }
    if (y < 0) {
        y = 0;
        velocityY = 0;  // Stop vertical movement when the sprite hits the top border
    }
    if (y + Mario.getLocalBounds().height * 0.1f > window.getSize().y) {
        y = window.getSize().y - Mario.getLocalBounds().height * 0.1f;
        velocityY = 0;  // Stop vertical movement when the sprite hits the bottom border
    }

    // Update the bounding box
    boundingBoxMario.update(Mario);

    // Check if the player is grounded
    // (You can use your existing logic for checking collision with bricks)
}

void Player::draw(sf::RenderWindow& window) {
    // Draw the player sprite
    Mario.setPosition(x, y);
    window.draw(Mario);
}
