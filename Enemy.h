#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Character.h"

class Enemy : public Character {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool isAlive;

public:
    Enemy(int x, int y, int width, int height, int health, int damage, const std::string& name, const std::string& texturePath);
    Enemy();
    void setAlive(bool status);

    void move();
    void attack();
    void draw(sf::RenderWindow& window);
    bool alive() const;  // Added this function
};

#endif