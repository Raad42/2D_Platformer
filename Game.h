#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include "BoundingBox.h"
#include "Levels.h"

class Game {
private:
    sf::RenderWindow& window;
    Player mario;
    BoundingBox boundingBoxMario;

    std::vector<Obstacle*> obstacles;
    std::vector<BoundingBox*> BoundingBoxes;
    std::vector<sf::FloatRect> obstacleBounds;


public:
    Game(sf::RenderWindow& window);
    ~Game();

    void run(); // Run game
    void handleInput(); // Handle user input.
    void update(); // Update game logic.
    void render(); // Render game objects.

    void handleCollisions(); //  A separate function for collision handling

};


#endif
