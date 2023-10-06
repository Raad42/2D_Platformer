#include "Game.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include <iostream>
#include <cmath>

Game::Game(sf::RenderWindow& window) : window(window), 
    mario(100, 300, 32, 32, 4.0, 100, 10, "Mario", window), 
    brick1(400, 600, 64, 64, window),
    brick2(400, 600, 64, 64, window),
    brick3(600, 500, 64, 64, window),
    brick4(600, 500, 64, 64, window),
    spike1(400, 600, 64, 64, window, 10),   
    
    boundingBoxMario(mario.getSprite()),
    boundingBoxBrick1(brick1.getSprite()),
    boundingBoxBrick2(brick2.getSprite()),
    boundingBoxBrick3(brick3.getSprite()),
    boundingBoxBrick4(brick4.getSprite()),
    boundingBoxSpike1(spike1.getSprite()) {


    mario.set_texture("MarioIdle.png");
    brick1.set_texture("Bricks.png");
    brick2.set_texture("Bricks.png");
    brick3.set_texture("Bricks.png");
    brick4.set_texture("Bricks.png");
    spike1.set_texture("Thwomp.png");

    //mario.getSprite().setScale(5.f, 5.f);

    //Testing with making top brick layer really thin
    brick1.getSprite().setScale(0.4f, 0.20f);
    brick1.getSprite().setPosition(400, 610);
    brick2.getSprite().setScale(0.4f, 0.01f);
    brick2.getSprite().setPosition(400, 605);

    brick3.getSprite().setScale(0.4f, 0.1f);
    brick3.getSprite().setPosition(600, 380);
    
    brick4.getSprite().setScale(0.4f, 0.1f);
    brick4.getSprite().setPosition(600, 360);

    spike1.getSprite().setScale(1.f, 1.f);
    spike1.getSprite().setPosition(700, 700);

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
    boundingBoxBrick1.update(brick1.getSprite());
    boundingBoxBrick2.update(brick2.getSprite());
    boundingBoxBrick3.update(brick3.getSprite());
    boundingBoxBrick4.update(brick4.getSprite());
    boundingBoxSpike1.update(spike1.getSprite());

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
    sf::FloatRect brick1Bounds = brick1.getBoundingbox();
    sf::FloatRect brick2Bounds = brick2.getBoundingbox();
    sf::FloatRect brick3Bounds = brick3.getBoundingbox();
    sf::FloatRect brick4Bounds = brick4.getBoundingbox();
    sf::FloatRect spike1Bounds = spike1.getBoundingbox();

    // float marioTop = marioBounds.top;
    // float marioBottom = marioBounds.width;
    // float marioLeft = marioBounds.left;
    // float marioRight = marioBounds.height;

    // float spike1Top = spike1Bounds.top;
    // float spike1Bottom = spike1Bounds.width;
    // float spike1Left = spike1Bounds.left;
    // float spike1Right = spike1Bounds.height;    

    // float brickTop = brickBounds.top;
    // float brickBottom = brickBounds.width;
    // float brickLeft = brickBounds.left;
    // float brickRight = brickBounds.height;

    // When he hits his head on the bottom
    if (marioBounds.intersects(brick1Bounds)||marioBounds.intersects(brick3Bounds)) {
        mario.velocityY = 2;
    }
    // When he lands on the brick
    if (marioBounds.intersects(brick2Bounds)||marioBounds.intersects(brick4Bounds)) {
        mario.isGrounded = true;
        mario.isJumping = false;
        float brickTopY;
        
        if (marioBounds.intersects(brick2Bounds)){
            brickTopY = brick2Bounds.top+1;
        }
        else{
            brickTopY = brick4Bounds.top+1;
        }
        
        // Set Mario's position to the top of the brick
        mario.y = brickTopY - marioBounds.height;
        mario.velocityY = -1; //Oppose gravity
    }

    //If mario collides with spike //Make mario death into player function
    if (marioBounds.intersects(spike1Bounds)) {
        int health = mario.get_health();
        health -= spike1.get_damage();
        mario.set_health(health);
        mario.set_texture("MarioDeath.png");

        std::cout << "Collision " << mario.get_health() << std::endl;
    }

}


void Game::render() {
    window.clear();
    
    window.draw(mario.getSprite());
    window.draw(brick1.getSprite());
    window.draw(brick2.getSprite());
    window.draw(brick3.getSprite());
    window.draw(brick4.getSprite());
    window.draw(spike1.getSprite());

    boundingBoxMario.draw(window);
    boundingBoxBrick1.draw(window);
    boundingBoxBrick2.draw(window);
    boundingBoxBrick3.draw(window);
    boundingBoxBrick4.draw(window);
    boundingBoxSpike1.draw(window);

    window.display();
}