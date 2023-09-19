#include "Game.h"
#include "Player.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(1200, 800), "Side-Scrolling Game") {
    // Initialize other game-specific variables and objects here...

    // Load fonts
    if (!font1.loadFromFile("IMPACTFUL.ttf")) {
        std::cout << "Failed to load font1." << std::endl;
        return;
    }

    if (!font2.loadFromFile("ClassicalDiary.ttf")) {
        std::cout << "Failed to load font2." << std::endl;
        return;
    }

    // Initialize text objects
    text1.setFont(font1);
    text1.setString("MARIO 2D PLATFORMER");
    text1.setCharacterSize(24);
    text1.setFillColor(sf::Color::Red);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setPosition(350.f, 0.f);

    text2.setFont(font2);
    text2.setString("this is a test to see how this will look");
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::Blue);
    text2.setPosition(250.f, 50.f);

    // Initialize game objects
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

    // Initialize Mario and bricks
    // You may want to pass textures and positions as arguments here
    Mario = sf::Sprite(/* Set your Mario texture here */);
    boundingBoxMario = BoundingBox(Mario);

    // Load the texture for the bricks (load once, reuse)
    sf::Texture textureBricks;
    if (!textureBricks.loadFromFile("Bricks.png")) {
        return -1; // Exit the program if texture loading fails.
    }

    // Creating bricks from brick class
    Bricks brick1(textureBricks, sf::Vector2f(400.f, 600.f));
    Bricks brick2(textureBricks, sf::Vector2f(800.f, 500.f));
    Bricks brick3(textureBricks, sf::Vector2f(1600.f, 700.f));

    boundingBoxBrick1 = BoundingBox(brick1.getSprite());
    boundingBoxBrick2 = BoundingBox(brick2.getSprite());
    boundingBoxBrick3 = BoundingBox(brick3.getSprite());

    // Initialize other variables...
}

void Game::handleEvent(const sf::Event& event) {
    // Handle events like window close, key presses, etc.
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    // Handle other events as needed...
}

void Game::updateMovement() {
    // Implement your movement logic here
}

void Game::update() {
    // Update game state, including character movement, collisions, etc.
    // You can call functions or methods of your game objects here...
    updateMovement();

    // Implement collision logic and other updates here...
}

void Game::render() {
    window.clear();
    window.draw(background);

    window.draw(Mario);
    boundingBoxMario.draw(window);

    brick1.draw(window);
    brick2.draw(window);
    brick3.draw(window);
    boundingBoxBrick1.draw(window);
    boundingBoxBrick2.draw(window);
    boundingBoxBrick3.draw(window);

    window.draw(text1);
    window.draw(text2);
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
