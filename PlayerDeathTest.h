#ifndef PLAYER_DEATH_TEST_H
#define PLAYER_DEATH_TEST_H

#include <SFML/Graphics.hpp>
#include "Game.h"

class PlayerDeathTest {
public:
    PlayerDeathTest();
    void run();

private:
    sf::RenderWindow window;
    Levels level;
};

#endif  // PLAYER_DEATH_TEST_H
