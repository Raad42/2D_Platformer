#include "Entity.h"
#include "Character.h"
#include "Obstacle.h"
#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "GameStats.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Mario Game");
    Game game(window);

    game.init(); // Initialize the game.

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        game.handleInput(); // Handle user input.
        game.update(); // Update game logic.
        game.render(); // Render game objects.

        window.display();
    }

    return 0;
}
