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

#include <SFML/Graphics.hpp>



int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML Mario Game");

    Game game(window);

    while (window.isOpen()) {
        game.run(); // Handle input, update, and render inside the Game class
    }

    return 0;
}

