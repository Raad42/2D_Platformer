#include "Entity.h"
#include "Character.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "GameStats.h"
#include "Game.h"
#include "BoundingBox.h"
#include "Levels.h"

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML Game");

    // Create a Levels object
    Levels levels(window);
    levels.LoadLevel1(); // Load the initial level

    // Create the Game object, passing both sf::RenderWindow and Levels objects
    Game game(window, levels);

    game.run();

    return 0;
}

