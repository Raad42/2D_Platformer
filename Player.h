#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "PowerUp.h"
#include "BoundingBox.h"
#include <SFML/Graphics.hpp>

class Player : public Character {
private:
    float x;
    float y;
    float velocityX;
    float velocityY;
    float accelerationX;
    float accelerationY;

    float gravity = 1;

    bool isMovingLeft;
    bool isMovingRight;
    bool isJumping;
    
    sf::RenderWindow& window;

    BoundingBox boundingBox;

public:
    Player(int x, int y, int width, int height, int health, int damage, const std::string& name, sf::RenderWindow& window);
    Player();

    void moveLeft();
    void moveRight();
    void jump();
    void fall();
    void attack();
    void collectPowerUp(PowerUp power_up);

    bool IsColliding(Entity* other) override;
    void OnCollision(Entity* other) override;

    void handleInput();
    void update();

    bool getIsMovingLeft();
    bool getIsMovingRight();
    bool getIsJumping();

    void updateMovement(sf::Sprite& sprite, sf::RenderWindow& window);

};


#endif
