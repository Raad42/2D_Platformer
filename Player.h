#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "PowerUp.h"
#include "BoundingBox.h"
#include <SFML/Graphics.hpp>

class Player : public Character {
public:
    float x;
    float y;
    float xBefore; 
    float yBefore; 
    float velocityX;
    float velocityY;
    float accelerationX;
    float accelerationY;
    float scale; 

    float gravity = 1;

    bool isDead;
    bool isMovingLeft;
    bool isMovingRight;
    bool isJumping;
    bool isGrounded;
    
    sf::RenderWindow& window;

    BoundingBox boundingBox;

public:
    Player(int x, int y, int width, int height, float scale, int health, int damage, const std::string& name, sf::RenderWindow& window);
    Player();

    void moveLeft();
    void moveRight();
    void jump();
    void fall();
    //void takeDamage();
    void attack(); 
    void die(); //Code this part
    void collectPowerUp(PowerUp power_up);

    void handleInput();
    void update();

    bool getIsMovingLeft();
    bool getIsMovingRight();
    bool getIsJumping();

    void updateMovement(sf::Sprite& sprite, sf::RenderWindow& window);

    // Getter function to get the local bounds
    sf::FloatRect getLocalBounds() const {
        return sprite.getLocalBounds();
    }

};


#endif
