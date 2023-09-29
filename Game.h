#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include "BoundingBox.h"

class Game {
private:
    sf::RenderWindow& window;
    Player mario;
    Obstacle brick1;
    Obstacle brick2;
    DamagingObstacle spike1;

    BoundingBox boundingBoxMario;
    BoundingBox boundingBoxBrick1;
    BoundingBox boundingBoxBrick2;
    BoundingBox boundingBoxSpike1; 

public:
    Game(sf::RenderWindow& window);

    void run(); // Run game
    void handleInput(); // Handle user input.
    void update(); // Update game logic.
    void render(); // Render game objects.

    void handleCollisions(); //  A separate function for collision handling

};


#endif
