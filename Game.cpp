#include "Game.h"
#include "Obstacle.h"
#include <iostream>

Game::Game(sf::RenderWindow& window) : window(window), 
    mario(100, 300, 32, 32, 100, 10, "Mario", window), 
    brick1(400, 600, 64, 64, window),
    brick2(400, 600, 64, 64, window),   
    
    boundingBoxMario(mario.getSprite()),
    boundingBoxBrick1(brick1.getSprite()),
    boundingBoxBrick2(brick2.getSprite()) {


    mario.set_texture("8bitMario1.png");
    brick1.set_texture("Bricks.png");
    brick2.set_texture("Bricks.png");

    brick1.getSprite().setScale(0.4f, 0.1f);
    brick1.getSprite().setPosition(400, 620);
    
    brick2.getSprite().setScale(0.4f, 0.1f);
    brick2.getSprite().setPosition(400, 600);

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

    // float marioTop = marioBounds.top;
    // float marioBottom = marioBounds.width;
    // float marioLeft = marioBounds.left;
    // float marioRight = marioBounds.height;

    // float brickTop = brickBounds.top;
    // float brickBottom = brickBounds.width;
    // float brickLeft = brickBounds.left;
    // float brickRight = brickBounds.height;

    // When he hits his head on the bottom
    if (marioBounds.intersects(brick1Bounds)) {
        mario.velocityY = 2;
    }
    // When he lands on the brick
    if (marioBounds.intersects(brick2Bounds)) {
        mario.isGrounded = true;
        mario.isJumping = false;
        mario.velocityY = -1;
    }
}


void Game::render() {
    window.clear();
    
    window.draw(mario.getSprite());
    window.draw(brick1.getSprite());
    window.draw(brick2.getSprite());

    boundingBoxMario.draw(window);
    boundingBoxBrick1.draw(window);
    boundingBoxBrick2.draw(window);

    window.display();
}