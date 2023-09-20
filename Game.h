#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"

#pragma once
#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow& window;
    // Add game-specific members such as player, enemies, power-ups, etc.
public:
    Game(sf::RenderWindow& window);

    void init(); // Initialize the game.
    void handleInput(); // Handle user input.
    void update(); // Update game logic.
    void render(); // Render game objects.
};


#endif
