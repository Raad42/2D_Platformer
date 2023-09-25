#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "PowerUp.h"
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
    
    sf::RenderWindow& window;
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

};


#endif
