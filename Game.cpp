#include "Game.h"

Game::Game(sf::RenderWindow& window) : window(window) {
    // Initialize your game-specific members here.
}

void Game::init() {
    // Initialize game resources here.
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Handle other user input events here.
    }

    // Handle input for player and other game entities.
}

void Game::update() {
    // Update game logic here.
    // Update player, enemies, power-ups, etc.
}

void Game::render() {
    window.clear();

    // Render game objects here.
    // Render player, enemies, power-ups, etc.

    window.display();
}
