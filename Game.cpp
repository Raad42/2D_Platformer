#include "Game.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include <iostream>
#include <cmath>

Game::Game(sf::RenderWindow& window) : window(window), 
    mario(100, 300, 32, 32, 4.0, 100, 10, "Mario", window),
    boundingBoxMario(mario.getSprite()) {

    
    // Create and add obstacles to the vector
    Obstacle* brick1 = new Obstacle(400, 600, 64, 64, window);
    Obstacle* brick2 = new Obstacle(400, 600, 64, 64, window);
    Obstacle* brick3 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* brick4 = new Obstacle(600, 500, 64, 64, window);
    Obstacle* spike1 = new DamagingObstacle(400, 600, 64, 64, window, 10);

    obstacles.push_back(brick1);
    obstacles.push_back(brick2);
    obstacles.push_back(brick3);
    obstacles.push_back(brick4);
    obstacles.push_back(spike1);

    // Create BoundingBox objects for each obstacle and add them to BoundingBoxes vector
    for (auto obstacle : obstacles) {
        BoundingBoxes.push_back(new BoundingBox(obstacle->getSprite()));
    }

    mario.set_texture("MarioIdle.png");
    brick1->set_texture("Bricks.png");
    brick2->set_texture("Bricks.png");
    brick3->set_texture("Bricks.png");
    brick4->set_texture("Bricks.png");
    spike1->set_texture("Thwomp.png");

    //mario.getSprite().setScale(5.f, 5.f);

    //Testing with making top brick layer really thin
    brick1->getSprite().setScale(0.4f, 0.20f);
    brick1->getSprite().setPosition(400, 610);
    brick2->getSprite().setScale(0.4f, 0.01f);
    brick2->getSprite().setPosition(400, 605);

    brick3->getSprite().setScale(0.4f, 0.1f);
    brick3->getSprite().setPosition(600, 380);
    
    brick4->getSprite().setScale(0.4f, 0.1f);
    brick4->getSprite().setPosition(600, 360);

    spike1->getSprite().setScale(1.f, 1.f);
    spike1->getSprite().setPosition(700, 700);

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

    boundingBoxMario.update(mario.getSprite());

    for (size_t i = 0; i < obstacles.size(); ++i) {
        BoundingBoxes[i]->update(obstacles[i]->getSprite());
    }

    handleCollisions();

    // if (boundingBoxMario.intersects(boundingBoxBrick1)) {
    //     mario.velocityY = 1;
    // }

    // if (mario.IsColliding(&brick1)) {
    //     mario.OnCollision(&brick1);
    // }
}

void Game::handleCollisions() {
    sf::FloatRect marioBounds = mario.getBoundingbox();
    // Calculate and add sf::FloatRect for each obstacle's bounding box
    for (auto obstacle : obstacles) {
        obstacleBounds.push_back(obstacle->getBoundingbox());
    }

    // float marioTop = marioBounds.top;
    // float marioBottom = marioBounds.width;
    // float marioLeft = marioBounds.left;
    // float marioRight = marioBounds.height;

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
            if (dynamic_cast<DamagingObstacle*>(obstacles[4])) {
                // Access the get_damage function through the obstacle
                int damage = dynamic_cast<DamagingObstacle*>(obstacles[4])->get_damage();
                health -= damage;
                mario.set_health(health);
                mario.set_texture("MarioDeath.png");
            }
            std::cout << "Collision " << mario.get_health() << std::endl;
        }
    }
}


void Game::render() {
    window.clear();

    // Draw obstacles and their bounding boxes
    for (size_t i = 0; i < obstacles.size(); ++i) {
        window.draw(obstacles[i]->getSprite()); // Draw the obstacle sprite

        // Draw the bounding box using your BoundingBox class
        BoundingBoxes[i]->draw(window);
    }

    
    window.draw(mario.getSprite());
    // window.draw(brick1.getSprite());
    // window.draw(brick2.getSprite());
    // window.draw(brick3.getSprite());
    // window.draw(brick4.getSprite());
    // window.draw(spike1.getSprite());

    boundingBoxMario.draw(window);
    // boundingBoxBrick1.draw(window);
    // boundingBoxBrick2.draw(window);
    // boundingBoxBrick3.draw(window);
    // boundingBoxBrick4.draw(window);
    // boundingBoxSpike1.draw(window);

    window.display();
}

Game::~Game(){
    for (auto obstacle : obstacles) {
        delete obstacle;
    }
    for (auto boundingBox : BoundingBoxes) {
        delete boundingBox;
    }
}