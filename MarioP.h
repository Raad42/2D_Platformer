#include <SFML/Graphics.hpp>

#ifndef MARIOP_H
#define MARIOP_H

class MarioP{
private:
    float x;
    float y;
    float velocityX;
    float velocityY;
    float accelerationX;
    float accelerationY;
    float gravity;
    bool isJumping;
    bool isGrounded;

    bool isMovingLeft; 
    bool isMovingRight;

    sf::Texture texture;
    sf::Sprite Mario; //Think of new sprite name

public:
    MarioP(float startX, float startY);

    void updateMovement(sf::RenderWindow& window);

    void jump();

    void moveLeft();

    void moveRight();

    void stopMoving();

    void setPosition(float newX, float newY);

    float getX() const;

    float getY() const;

    void draw(sf::RenderWindow& window);

    // Add other getter and setter methods as needed
};

#endif