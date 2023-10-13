#include "Game.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include "PowerUpBlock.h"
#include "Levels.h"
#include <iostream>
#include <cmath>

//constructor for the game class and initilisation
Game::Game(sf::RenderWindow& window, Levels& levels) : window(window), levels(levels),
    mario(100, 300, 32, 32, 4.0, 100, 10, "Mario", window),
    boundingBoxMario(mario.getSprite()) {

    mario.set_texture("MarioIdle.png");
    mario.x = 0;

    //attempt to load file and output
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
    text2.setString("Half way there!");
    text2.setCharacterSize(50);
    text2.setFillColor(sf::Color::Red);
    text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text2.setPosition(5000.f, 300.f);

    for (int i = 0; i < 5; i++){
        powerUpCollected[i] = false; 
    }
    //mario.getSprite().setScale(5.f, 5.f);
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
//checks if window is open and delegates the handling of Mario's input to its respective method
void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        
    }

    mario.handleInput();
}

void Game::update() {
   
    mario.update();

    boundingBoxMario.update(mario.getSprite());

    levels.Update();

    handleCollisions();
}

//handle collosions between mario and other objects
void Game::handleCollisions() {
    sf::FloatRect marioBounds = mario.getBoundingbox();
    MovingObstacle** movingObstacles = levels.getmovingObstacles();
    sf::FloatRect movingObstacleBounds1 = movingObstacles[0]->getBoundingbox();
    sf::FloatRect movingObstacleBounds2 = movingObstacles[1]->getBoundingbox();
    float movingX; 

    // Access obstacles and their bounding boxes through levels
    std::vector<Obstacle*>& obstacles = levels.getObstacles();
    std::vector<BoundingBox*>& obstacleBoundingBoxes = levels.getBoundingBoxes();

    // Calculate and add sf::FloatRect for each obstacle's bounding box
    for (auto obstacle : obstacles) {
        obstacleBounds.push_back(obstacle->getBoundingbox());
    }
    // positions the two moving obstacles at the same horizontal position if moving
    if (movingObstacleBounds1.intersects(movingObstacleBounds2)){
        movingObstacles[1]->set_x_position(movingObstacles[0]->get_x_position());
    }

    for (size_t i = 0; i < obstacles.size(); ++i) {

        //Mario intersects obstacle; if power-up not collected, adjust values, drop power-up.
        if (marioBounds.intersects(obstacleBounds[6]) && powerUpCollected[0] == false){
            powerUpCollected[0] = true;
            if (marioBounds.top > (obstacleBounds[6].width)) {
                mario.velocityY = 4;
                int health = dynamic_cast<PowerUpBlock*>(obstacles[6])->get_health();
                health = health - 10;
                if (health <= 0) {
                    dynamic_cast<PowerUpBlock*>(obstacles[6])->dropPowerUp();
                }

            }
        }
        // When he hits his head on the bottom
        if (marioBounds.intersects(obstacleBounds[0])||marioBounds.intersects(obstacleBounds[2])||marioBounds.intersects(movingObstacleBounds2)) {
            mario.velocityY = 2;
        }
        // Mario checks collisions with bricks. If landed on one, he's grounded, and his position adjusts to brick's top edge.
        if (marioBounds.intersects(obstacleBounds[1])||marioBounds.intersects(obstacleBounds[3])||marioBounds.intersects(movingObstacleBounds1)) {
            mario.isGrounded = true;
            mario.isJumping = false;
            float brickTopY;
        
            if (marioBounds.intersects(obstacleBounds[1])){
                brickTopY = obstacleBounds[1].top+1;
            }

            else  if (marioBounds.intersects(movingObstacleBounds1)){
                brickTopY = movingObstacleBounds1.top+1;
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
            gameStats.update_deaths();
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
            text1.setPosition(9800.f, 250.f);
            text1.setFillColor(sf::Color::Red);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::N))) {
                std::cout << "Deaths on level 1: " << gameStats.getDeaths() << std::endl;
                levels.ClearLevel();
                obstacleBounds.clear();
                mario.x = 0;
                levels.levelLoadFunctions[1]();
            }
        }
    }
}
// Method to render game elements
void Game::render() {
    window.clear();

    levels.Render(window);

    window.draw(mario.getSprite());

    boundingBoxMario.draw(window);

    window.draw(text1);
    window.draw(text2);

    window.display();
}
