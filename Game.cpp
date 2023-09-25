#include "Game.h"

Game::Game(sf::RenderWindow& window) : window(window), mario(100, 300, 32, 32, 100, 10, "Mario", window), brick1(400, 600, 64, 64, window) {
    // Initialize your game-specific members here.
    mario.set_texture("8bitMario.png");
    
    brick1.set_texture("Bricks.png"); // Load the obstacle texture
}


void Game::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
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
    mario.handleInput();
}

void Game::update() {
    // Update game logic here.
    // Update player, enemies, power-ups, etc.
    mario.update();
    
    brick1.getSprite().setScale(0.4f, 0.2f);
    brick1.getSprite().setPosition(400, 600);
}

void Game::render() {
    window.clear();
    
    // Render game entities here.
    window.draw(mario.getSprite());
    window.draw(brick1.getSprite());

    window.display();
}
