#include "Player.h"
#include "PowerUp.h"
#include "BoundingBox.h"
#include "Entity.h"
#include "Levels.h"


Player::Player(int x, int y, int width, int height, float scale, int health, int damage, const std::string& name, sf::RenderWindow& window)
    : Character(x, y, width, height, health, damage, name), scale(scale), window(window), boundingBox(sprite) {
    x = 0;
    y = 0;
    velocityX = 0;
    velocityY = 0;
    accelerationX = 0;
    accelerationY = 0;
    
    
    gravity = 1;

    isMovingLeft = false;
    isMovingRight = false;
    isJumping = false;
    isGrounded = true;

}

Player::Player()
    : Character(0, 0, 0, 0, 0, 0, ""), window(window), boundingBox(sprite) {
}

void Player::moveLeft() {
    isMovingLeft = true;
    isMovingRight = false;
    velocityX = -4;
}

void Player::moveRight() {
    isMovingRight = true;
    isMovingLeft = false;
    velocityX = 4;
}

void Player::jump() {
    if (!isJumping) {  // Check if the player is not already jumping
        velocityY = -35; // Adjust the jump velocity as needed
        isJumping = true;
        isGrounded = false;
    }
}

void Player::fall() {
    velocityY = gravity;
}


void Player::attack() {
    // Implement attack logic here.
}

bool Player::getIsMovingLeft() { 
    return isMovingLeft; 
}
bool Player::getIsMovingRight() { 
    return isMovingRight; 
}
bool Player::getIsJumping() { 
    return isJumping; 
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

    static bool spacePressedLastFrame = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !spacePressedLastFrame) {
        jump();
    }
    spacePressedLastFrame = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        attack();
    }
    // You can add more input handling here for other actions.

    // Update other player-specific input handling if needed.
}

void Player::updateMovement(sf::Sprite& sprite, sf::RenderWindow& window) {
    // Add gravity
    if (y < window.getSize().y && !isGrounded) {
        velocityY += gravity;
    }
    else if (y >= window.getSize().y) {
        y = window.getSize().y;
        velocityY = 0;  // Stop vertical movement when the sprite hits the ground
        isJumping = false; // Reset jumping state when landing
        isGrounded = true; // When on ground is grounded
    }

    // Boundary checks to keep the sprite within the window
    if (x < 0) {
        x = 0;
        velocityX = 0;  // Stop horizontal movement when the sprite hits the left border
    }
    if (x + sprite.getLocalBounds().width * sprite.getScale().x > 12000) {
        x = 12000 - sprite.getLocalBounds().width * sprite.getScale().x;
        velocityX = 0;  // Stop horizontal movement when the sprite hits the right border
    }
    if (y < 0) {
        y = 0;
        velocityY = 0;  // Stop vertical movement when the sprite hits the top border
    }
    if (y + sprite.getLocalBounds().height * sprite.getScale().y > window.getSize().y) {
        y = window.getSize().y - sprite.getLocalBounds().height * sprite.getScale().y;
        velocityY = 0;  // Stop vertical movement when the sprite hits the bottom border
        isJumping = false;
    }
    
    boundingBox.update(sprite);

}


void Player::update() {

    // Update the player's position and physics.
    // Apply acceleration and gravity.
    velocityX += accelerationX;
    velocityY += accelerationY + gravity;

    // Update the player's position based on velocity.
    x += velocityX;
    y += velocityY;

    // Handle jump when the Space key is pressed
    static bool spacePressedLastFrame = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !spacePressedLastFrame) {
        jump();
    }
    spacePressedLastFrame = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    float playerWidth = sprite.getLocalBounds().width * scale;
    float playerHeight = sprite.getLocalBounds().height * scale;



    // Handle key releases for horizontal movement
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && isMovingLeft) {
        isMovingLeft = false;
        velocityX = 0; // Stop horizontal movement when left key is released
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && isMovingRight) {
        isMovingRight = false;
        velocityX = 0; // Stop horizontal movement when right key is released
    }

    // Check for collisions with the ground or obstacles and handle accordingly.
    // You'll need to implement collision detection and response here.

    // Update other game-specific logic, animations, etc.
    sprite.setScale(scale, scale);

    updateMovement(sprite, window);
    sprite.setPosition(x,y);

}


void Player::collectPowerUp(PowerUp power_up) {
    // Implement power-up collection logic here.
}
