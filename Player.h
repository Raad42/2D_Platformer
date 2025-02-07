#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "GameStats.h"
#include "BoundingBox.h"
#include "GameStats.h"
#include <SFML/Graphics.hpp>

class Player : public Character {
public:
    // attributes for mario position, size, movement etc
    float x;
    float y;
    float xBefore; 
    float yBefore; 
    float velocityX;
    float velocityY;
    float accelerationX;
    float accelerationY;
    float jumpVelocity; 
    float runSpeed; 
    float scale; 

    // gravity value (change if more gravity wanted)
    float gravity = 1;

    // flags to check for mario specific actions
    bool isDead;
    bool isPowerUp; 
    bool isMovingLeft;
    bool isMovingRight;
    bool isJumping;
    bool isGrounded;
    bool deathAlreadyChecked;
    
    sf::RenderWindow& window;
    sf::Clock powerUpTimer;
    
    GameStats gameStats;
    BoundingBox boundingBox;

    GameStats playerStats;

public:
    Player(int x, int y, int width, int height, float scale, int health, int damage, const std::string& name, sf::RenderWindow& window);
    Player();

    // movement functions
    void moveLeft();
    void moveRight();
    void jump();
    void fall();

    // functions altering marios position when dying or using powerup
    void reset();
    void PowerUp();

    // handle input and update mario
    void handleInput();
    void update();

    // flags that allow for movement
    bool getIsMovingLeft();
    bool getIsMovingRight();
    bool getIsJumping();

    // updates mario when he moves
    void updateMovement(sf::Sprite& sprite, sf::RenderWindow& window);

    // Getter function to get the local bounds
    sf::FloatRect getLocalBounds() const {
        return sprite.getLocalBounds();
    }

};


#endif
