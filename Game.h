#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include "BoundingBox.h"
#include "Levels.h"
#include "Enemy.h" 

class Game {
private:
    sf::RenderWindow& window;
    sf::View view;
    sf::Font font;
    sf::Text text1;
    
    bool isPaused; // To track if the game is paused
    sf::VertexArray pauseTriangle; // Triangle displayed during the pause  
     
    Player mario;
    BoundingBox boundingBoxMario;
    Enemy goomba; 
    
    std::vector<sf::FloatRect> obstacleBounds;

    Levels& levels;

public:
    Game(sf::RenderWindow& window, Levels& levels);

    void run(); // Run game
    void handleInput(); // Handle user input.
    void update(); // Update game logic.
    void render(); // Render game objects.

    void handleCollisions(); //  A separate function for collision handling

    void resetPlayerPosition();
};

#endif
