#include "PlayerDeathTest.h"
#include <iostream>

PlayerDeathTest::PlayerDeathTest() : window(sf::VideoMode(800, 600), "Player Death Test"), level(window) {
    // Initialize the window and the level
}

void PlayerDeathTest::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update the level and check for collisions
        level.Update();
        level.handleCollisions();

        // Clear the screen and render the level
        window.clear();
        level.Render(window);
        window.display();
    }
}

int main() {
    Game game;
    game.handleCollisions();  // This will call handleCollisions of the Game class
    return 0;
}
