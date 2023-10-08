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

    // Set up the view
    // sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    // window.setView(view);

    // Create a Levels object
    Levels levels(window);
    levels.levelLoadFunctions[0]();

    // Create the Game object, passing both sf::RenderWindow and Levels objects
    Game game(window, levels);

    game.run();

    return 0;
}

