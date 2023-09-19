#include "Game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(1200, 800), "Side-Scrolling Game") {
    // Initialize other game-specific variables and objects here...

    if (!textureBackground.loadFromFile("pixelBackground.jpg")) {
        std::cout << "Failed to load background texture." << std::endl;
        return;
    }

    background.setTexture(textureBackground);
    background.setScale(
        static_cast<float>(window.getSize().x) / textureBackground.getSize().x,
        static_cast<float>(window.getSize().y) / textureBackground.getSize().y
    );

    // Set up the view
    view.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    view.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    window.setView(view);
}

void Game::handleEvent(const sf::Event& event) {
    // Handle events like window close, key presses, etc.
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    // Handle other events as needed...
}

void Game::update() {
    // Update game state, including character movement, collisions, etc.
    // You can call functions or methods of your game objects here...
}

void Game::render() {
    window.clear();
    window.draw(background);
    // Render game objects, characters, obstacles, etc.
    // You can call the draw methods of your game objects here...
    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            handleEvent(event);
        }

        update();
        render();
    }
}
