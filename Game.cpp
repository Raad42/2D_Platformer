#include "Game.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include "Levels.h"
#include <iostream>
#include <cmath>

Game::Game(sf::RenderWindow& window, Levels& levels) : window(window), levels(levels),
    mario(100, 300, 32, 32, 4.0, 100, 10, "Mario", window),
    boundingBoxMario(mario.getSprite()) {

    mario.set_texture("MarioIdle.png");
    mario.x = 0;

    if (!font.loadFromFile("ClassicalDiary.ttf")) {
        std::cout << "faield to load font" << std::endl;
    }
    
    text1.setFont(font);
    text1.setString("Press 'n' to progress");
    text1.setCharacterSize(50);
    text1.setFillColor(sf::Color::Transparent);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setPosition(0.f, -100.f);
    
    text2.setFont(font);
    text2.setString("PAUSED - Press P to unpause");
    text2.setCharacterSize(50);
    text2.setFillColor(sf::Color::Transparent);
    text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text2.setPosition(0.f, -100.f);

    //mario.getSprite().setScale(5.f, 5.f);
}


void Game::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
        
        // Update the view's position to follow the character
        view.setCenter(mario.x + mario.getLocalBounds().width, 300);
        window.setView(view);

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

    boundingBoxMario.update(mario.getSprite());

    levels.Update();

    handleCollisions();
}


void Game::handleCollisions() {
    sf::FloatRect marioBounds = mario.getBoundingbox();

    // Access obstacles and their bounding boxes through levels
    std::vector<Obstacle*>& obstacles = levels.getObstacles();
    std::vector<BoundingBox*>& obstacleBoundingBoxes = levels.getBoundingBoxes();

    // Calculate and add sf::FloatRect for each obstacle's bounding box
    for (auto obstacle : obstacles) {
        obstacleBounds.push_back(obstacle->getBoundingbox());
    }


    for (size_t i = 0; i < obstacles.size(); ++i) {
        // When he hits his head on the bottom
        if (marioBounds.intersects(obstacleBounds[0])||marioBounds.intersects(obstacleBounds[2])) {
            mario.velocityY = 2;
        }
        // When he lands on the brick
        if (marioBounds.intersects(obstacleBounds[1])||marioBounds.intersects(obstacleBounds[3])) {
            mario.isGrounded = true;
            mario.isJumping = false;
            float brickTopY;
        
            if (marioBounds.intersects(obstacleBounds[1])){
                brickTopY = obstacleBounds[1].top+1;
            }
            else{
                brickTopY = obstacleBounds[3].top+1;
            }
        
            // Set Mario's position to the top of the brick
            mario.y = brickTopY - marioBounds.height;
            mario.velocityY = -1; //Oppose gravity
        }
        //If mario collides with spike //Make mario death into player function
        if (marioBounds.intersects(obstacleBounds[4])) {
            int health = mario.get_health();
            mario.x = 0;
            if (dynamic_cast<DamagingObstacle*>(obstacles[4])) {
                // Access the get_damage function through the obstacle
                int damage = dynamic_cast<DamagingObstacle*>(obstacles[4])->get_damage();
                health -= damage;
                mario.set_health(health);
                mario.set_texture("MarioDeath.png");
            }
            // std::cout << "Collision " << mario.get_health() << std::endl;
        }
        text1.setFillColor(sf::Color::Transparent);
        if (marioBounds.intersects(obstacleBounds[5])){
            text1.setPosition(650.f, 250.f);
            text1.setFillColor(sf::Color::Red);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                levels.ClearLevel();
                obstacleBounds.clear();
                mario.x = 0;
                levels.levelLoadFunctions[1]();
            }
        }
    }
}

void Game::render() {
    window.clear();

    levels.Render(window);

    window.draw(mario.getSprite());

    boundingBoxMario.draw(window);

    window.draw(text1);
    window.draw(text2);

    window.display();
}