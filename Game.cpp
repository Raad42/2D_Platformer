#include "Game.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include "PowerUpBlock.h"
#include "Levels.h"
#include <iostream>
#include <cmath>

Game::Game(sf::RenderWindow& window, Levels& levels) : window(window), levels(levels),
    mario(100, 300, 32, 32, 4.0, 100, 10, "Mario", window),
    boundingBoxMario(mario.getSprite()), playerStats(playerStats) { 

    playerStats.setKills(0);

    mario.set_texture("MarioIdle.png");
    mario.x = 0;

    if (!font.loadFromFile("ClassicalDiary.ttf")) {
        std::cout << "faield to load font" << std::endl;
    }
    //gives instructions to user 
    text1.setFont(font);
    text1.setString("Press 'n' to progress");
    text1.setCharacterSize(50);
    text1.setFillColor(sf::Color::Transparent);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setPosition(0.f, -100.f);
    

    text2.setFont(font);
    text2.setString("Half way there!");
    text2.setCharacterSize(50);
    text2.setFillColor(sf::Color::Red);
    text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text2.setPosition(5000.f, 300.f);

    deathText.setFont(font);
    deathText.setCharacterSize(30);
    deathText.setFillColor(sf::Color::Red);
    deathText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    deathText.setPosition(-450.f, -100.f);

    highScoreText.setFont(font);
    highScoreText.setCharacterSize(30);
    highScoreText.setFillColor(sf::Color::Red);
    highScoreText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    highScoreText.setPosition(-450.f, -50.f);
    

    for (int i = 0; i < 5; i++){
        powerUpCollected[i] = false; 
    }
}


void Game::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
        
        // Update the view's position to follow the character
        view.setCenter(mario.x + mario.getLocalBounds().width, 325);
        window.setView(view);

    } 
}

void Game::handleInput() {
    sf::Event event;
    bool loadStats = false; 

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            endGame();
            window.close();
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::H) {
            loadStats = true; // Set the flag when 'H' key is pressed
        }
    }

    // Handle input for player and other game entities.
    mario.handleInput();
    
    if (loadStats) {
        loadPlayerStats(); // Call loadPlayerStats here if the flag is set
    }
}

void Game::update() {
    // Update game logic here.
    // Update player, enemies, power-ups, etc.
    mario.update();

    boundingBoxMario.update(mario.getSprite());

    levels.Update();

    playerStats.update_high_score(mario.x);

    deathText.setPosition(mario.x - 450, -100.f);
    deathText.setString("Deaths: " + std::to_string(playerStats.getDeaths()));

    highScoreText.setPosition(mario.x - 450, -50.f);
    highScoreText.setString("High Score: " + std::to_string(static_cast<int>(playerStats.getScore())));

    handleCollisions();
}


void Game::handleCollisions() {
    sf::FloatRect marioBounds = mario.getBoundingbox();
    MovingObstacle** movingObstacles = levels.getmovingObstacles();
  
    sf::FloatRect movingObstacleBounds1 = movingObstacles[0]->getBoundingbox();
    sf::FloatRect movingObstacleBounds2 = movingObstacles[1]->getBoundingbox();
    sf::FloatRect movingObstacleBounds3 = movingObstacles[2]->getBoundingbox();
    float movingX; 

    // Access obstacles and their bounding boxes through levels
    std::vector<Obstacle*>& obstacles = levels.getObstacles();
    std::vector<BoundingBox*>& obstacleBoundingBoxes = levels.getBoundingBoxes();

    std::vector<DamagingObstacle*>& damagingObstacles = levels.getDamagingObstacles();
    std::vector<BoundingBox*>& BoundingBoxesDamagingObstacles = levels.getBoundingBoxesDamagingObstacles();

    std::vector<PowerUpBlock*>& PowerUpBlocks = levels.getPowerUpBlocks();
    std::vector<BoundingBox*>& BoundingBoxesPowerUpBlocks = levels.getBoundingBoxesPowerUpBlocks();
   
    // Calculate and add sf::FloatRect for each obstacle's bounding box
    for (auto obstacle : obstacles) {
        obstacleBounds.push_back(obstacle->getBoundingbox());
    }

    for (auto damagingObstacle: damagingObstacles) {
        damagingObstacleBounds.push_back(damagingObstacle->getBoundingbox());
    }

    for (auto PowerUpBlock: PowerUpBlocks) {
        powerUpBlocksBounds.push_back(PowerUpBlock->getBoundingbox());
    }

    if (movingObstacleBounds1.intersects(movingObstacleBounds2)){
        movingObstacles[1]->set_x_position(movingObstacles[0]->get_x_position());
    }

    for (size_t i = 0; i < obstacles.size(); ++i) {
        if (i % 2 == 0) {
            if (marioBounds.intersects(obstacleBounds[i])) {
            mario.velocityY = 2;
            }
        } else {
            if (marioBounds.intersects(obstacleBounds[i])) {
                mario.isGrounded = true;
                mario.isJumping = false;
                float brickTopY;
                brickTopY = obstacleBounds[i].top + 1;
                // Set Mario's position to the top of the brick
                mario.y = brickTopY - marioBounds.height;
                mario.velocityY = -1; // Oppose gravity
            }
        }
    }

    for (int i = 0; i < 2; i++){
        if (i % 2 != 0) {
            if (marioBounds.intersects(movingObstacles[i]->getBoundingbox())) {
            mario.velocityY = 2;
            }
        } else {
            if (marioBounds.intersects(movingObstacles[i]->getBoundingbox())) {
                mario.isGrounded = true;
                mario.isJumping = false;
                float brickTopY;
                brickTopY = movingObstacles[i]->getBoundingbox().top + 1;
                // Set Mario's position to the top of the brick
                mario.y = brickTopY - marioBounds.height;
                mario.velocityY = -1; // Oppose gravity
            }
        }
    }

    for (size_t i = 0; i < damagingObstacles.size(); ++i){
        if (marioBounds.intersects(damagingObstacleBounds[i])&&mario.isPowerUp == false) {
            int health = mario.get_health();
            //mario.x = 0;
            if (mario.deathAlreadyChecked == false){
                playerStats.update_deaths();
                mario.deathAlreadyChecked = true; 
            }   
            
            mario.set_texture("MarioDeath.png");
            mario.isDead = true; 
        }
    }

    for (size_t i = 0; i < PowerUpBlocks.size(); ++i) {
    if (marioBounds.intersects(powerUpBlocksBounds[i]) && PowerUpBlocks[i]->get_IsCollected() == false)  {
            mario.velocityY = 2;
            mario.PowerUp();
            PowerUpBlocks[i]->dropPowerUp();
        }
    }

     text1.setFillColor(sf::Color::Transparent);
        if (marioBounds.intersects(obstacleBounds[31])){
            text1.setPosition(9800.f, 250.f);
            text1.setFillColor(sf::Color::Red);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::N))) {
                std::cout << "Deaths on level 1: " << playerStats.getDeaths() << std::endl; 
                levels.ClearLevel();
                obstacleBounds.clear();
                mario.x = 0;
                levels.levelLoadFunctions[1]();
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
    
    window.draw(deathText);
    window.draw(highScoreText);

    window.display();
}

void Game::savePlayerStats() {
    playerStats.saveToFile("player_stats.txt");
}

void Game::loadPlayerStats() {
    playerStats.printLast10GameStats("player_stats.txt");
}

void Game::endGame() {
    savePlayerStats();
    isGameEnded = true;
}