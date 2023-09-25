#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"

class Game {
private:
    sf::RenderWindow& window;
    Player mario;
    Obstacle brick1;

    // Add game-specific members such as player, enemies, power-ups, etc.
public:
    Game(sf::RenderWindow& window);

    void run(); // Run game
    void handleInput(); // Handle user input.
    void update(); // Update game logic.
    void render(); // Render game objects.
};


#endif
