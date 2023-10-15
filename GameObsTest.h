
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SFML/Graphics.hpp>

// Obstacle (brick) class
class Obstacle {
public:
    sf::FloatRect getBoundingbox();
};

class Game {
public:
    Game();
    void handleCollisions();

    sf::FloatRect marioBounds;
    Obstacle brick;
};

#endif  // GAME_H
