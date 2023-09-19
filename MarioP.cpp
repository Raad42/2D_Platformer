#include "MarioP.h"

MarioP::MarioP(float startX, float startY) {
  // Set initial position
  x = startX;
  y = startY;

  velocityX = 0;
  velocityY = 0;

  accelerationX = 0;
  accelerationY = 0;

  gravity = 1;

  isJumping = false;
  isGrounded = false;

  isMovingLeft = false;
  isMovingRight = false; 

  if (!texture.loadFromFile("8bitMario.png")) {
       throw std::runtime_error("Failed to load Mario texture"); //Change this; this handles error inside of an constructor
  }

  Mario.setTexture(texture);
  Mario.setScale(0.05f, 0.05f);
};

void MarioP::updateMovement(sf::RenderWindow& window) {
  // Add gravity
  if (y < 800) {
    velocityY += gravity;
  } else if (y > 800) {
    y = 800;
    velocityY = 0;  // Stop vertical movement when the sprite hits the ground
  }

  // Update velocity with acceleration
  velocityX += accelerationX;
  velocityY += accelerationY;

  // Update position
  x += velocityX;
  y += velocityY;

  // Boundary checks to keep the sprite within the window
  if (x < 0) {
    x = 0;
    velocityX =
        0;  // Stop horizontal movement when the sprite hits the left border
  }
  if (x + Mario.getLocalBounds().width * 0.1f > window.getSize().x) {
    x = window.getSize().x - Mario.getLocalBounds().width * 0.1f;
    velocityX =
        0;  // Stop horizontal movement when the sprite hits the right border
  }
  if (y < 0) {
    y = 0;
    velocityY = 0;  // Stop vertical movement when the sprite hits the top border
  }
  if (y + Mario.getLocalBounds().height * 0.1f > window.getSize().y) {
    y = window.getSize().y - Mario.getLocalBounds().height * 0.1f;
    velocityY = 0;  // Stop vertical movement when the sprite hits the bottom border
  }
};

void MarioP::jump(){

    //Might need to get rid of if statement here
    if (!isJumping) {
            velocityY = -20;
            isJumping = true;
    }
};

void MarioP::moveLeft(){
    isMovingLeft = true;
    isMovingRight = false; 
    velocityX = -3; 
   
};

void MarioP::moveRight(){
    isMovingLeft = false;
    isMovingRight = true; 
    velocityX = 3; 
};

void MarioP::stopMoving(){
    isMovingLeft = false;
    isMovingRight = false; 
    velocityX = 0; 
};

void MarioP::setPosition(float newX, float newY){
    x = newX;
    y = newY;
};

float MarioP::getX() const { return x; };

float MarioP::getY() const { return y; };

void MarioP::draw(sf::RenderWindow& window) {
  // Draw the Mario sprite at the current position
  Mario.setPosition(x, y);
  window.draw(Mario);
}