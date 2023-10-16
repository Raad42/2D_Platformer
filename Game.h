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
    sf::View view;
    sf::Font font;
    sf::Text text1;
    sf::Text text2;

    bool powerUpCollected[5];

    Player mario;
    BoundingBox boundingBoxMario;

    Enemy goomba;

    std::vector<sf::FloatRect> obstacleBounds;
    std::vector<sf::FloatRect> damagingObstacleBounds;
    std::vector<sf::FloatRect> powerUpBlocksBounds;
    MovingObstacle** movingObstacleBounds;

    Levels& levels;
    GameStats gameStats;

public:
    Game(sf::RenderWindow& window, Levels& levels);

    void run(); // Run game
    void handleInput(); // Handle user input.
    void update(); // Update game logic.
    void render(); // Render game objects.

    void handleCollisions(); //  A separate function for collision handling


};


#endif
