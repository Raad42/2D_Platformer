#include "Player.h"
#include "PowerUp.h"
#include "BoundingBox.h"
#include "Entity.h"
#include "Levels.h"
#include "GameStats.h"

#include <iostream>


Player::Player(int x, int y, int width, int height, float scale, int health, int damage, const std::string& name, sf::RenderWindow& window)
    : Character(x, y, width, height, health, damage, name), scale(scale), window(window), boundingBox(sprite), playerStats(playerStats) {
    x = 0;
    y = 0;
    jumpVelocity = -40;
    runSpeed = 5; 
    velocityX = 0;
    velocityY = 0;
    accelerationX = 0;
    accelerationY = 0;
    
    gravity = 1;

    isDead = false; 
    isPowerUp = false; 
    isMovingLeft = false;
    isMovingRight = false;
    isJumping = false;
    isGrounded = true; // true as he starts on the ground
    deathAlreadyChecked = false;

}

Player::Player()
    : Character(0, 0, 0, 0, 0, 0, ""), window(window), boundingBox(sprite) {
}

void Player::moveLeft() {
    isMovingLeft = true;
    isMovingRight = false;
    velocityX = -runSpeed;
}

void Player::moveRight() {
    isMovingRight = true;
    isMovingLeft = false;
    velocityX = runSpeed;
}

void Player::jump() {
    if (!isJumping) {  // Check if the player is not already jumping
        velocityY = jumpVelocity; // moves upwards
        isJumping = true;
        isGrounded = false;
    }
}

void Player::fall() {
    velocityY = gravity; // falls down
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
    if (isDead == false){
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
        // flag that stops repeated jumping if spamming/holding space
        static bool spacePressedLastFrame = false;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !spacePressedLastFrame) {
            jump();
        }
        spacePressedLastFrame = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    }
   
}

void Player::updateMovement(sf::Sprite& sprite, sf::RenderWindow& window) {
    if (isDead == false){ //No movement if character dies

    // Add gravity
    if (y < window.getSize().y && !isGrounded) {
        velocityY += gravity;
    }
    // stops from falling through floor
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
    if (x + sprite.getLocalBounds().width * sprite.getScale().x > 10000) {
        x = 10000 - sprite.getLocalBounds().width * sprite.getScale().x;
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
    // updates collision box when he moves
    boundingBox.update(sprite);
    }
    

}


void Player::update() {
    //If character dies animation occurs
    if (isDead == true) { 
        gravity = 0.1;
    }

    else {
        gravity = 1; 
    }

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

    // update sprite width and height
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

    // powerup 
    if (isPowerUp == true && isDead == false){
        sf::Time powerUpDuration = powerUpTimer.getElapsedTime();
        if (powerUpDuration.asSeconds() >= 8) { // 8 seconds duration
            runSpeed = 5; 
            jumpVelocity = -40; 
            set_texture("MarioIdle.png");
            isPowerUp = false;
        }
    }

    // Update sprite scale
    sprite.setScale(scale, scale);

    // updates movement and sets sprite position accordingly
    updateMovement(sprite, window);
    sprite.setPosition(x,y);

}

// function to reset player to default settings after death
void Player::reset () {
    x = 0; 
    y = 100;
    runSpeed = 5; 
    jumpVelocity = -40; 
    set_texture("MarioIdle.png");
    isDead = false; 
    isPowerUp = false;
    gameStats.update_deaths();
    
    deathAlreadyChecked = false;
}

// function that alters marios attributes and changes texture
void Player::PowerUp(){
    jumpVelocity = -50;
    runSpeed = 6; 
    isPowerUp = true; 
    set_texture("BigMarioCrouch.png");
    boundingBox.update(sprite);
    powerUpTimer.restart();
}