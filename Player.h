#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "BoundingBox.h"

class Player {
private:
    sf::Sprite Mario;
    BoundingBox boundingBoxMario;
    float x, y;
    float velocityX, velocityY;
    float accelerationX, accelerationY;
    float gravity;
    bool isJumping;
    bool isGrounded;  // Add a flag to track if the player is grounded
    sf::Texture playerTexture; // Texture for the player
    float gameWorldWidth; // Width of the game world
    sf::Vector2u window; // Window size

public:
    Player(float startX, float startY); // Constructor
    void loadTexture(const std::string& texturePath); // Method to load the player's texture
    void handleInput();
    void update();
    void draw(sf::RenderWindow& window);

    // Add getters and setters as needed

    // Add other player-specific methods
};

#endif
