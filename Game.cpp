#include "Game.h"
#include "Obstacle.h"
#include <iostream>

Game::Game(sf::RenderWindow& window) : window(window), 
    mario(100, 300, 32, 32, 100, 10, "Mario", window), 
    brick1(400, 600, 64, 64, window),   
    
    boundingBoxMario(mario.getSprite()),
    boundingBoxBrick1(brick1.getSprite()) {


    mario.set_texture("8bitMario1.png");
    brick1.set_texture("Bricks.png");

    brick1.getSprite().setScale(0.4f, 0.2f);
    brick1.getSprite().setPosition(400, 600);

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
    sf::FloatRect brickBounds = brick1.getBoundingbox();

    float marioTop = marioBounds.top;
    float marioBottom = marioBounds.width;
    float marioLeft = marioBounds.left;
    float marioRight = marioBounds.height;

    float brickTop = brickBounds.top;
    float brickBottom = brickBounds.width;
    float brickLeft = brickBounds.left;
    float brickRight = brickBounds.height;

    if (marioBounds.intersects(brickBounds)) {
        // When he lands on the brick
        if (marioBottom < brickTop && marioTop > brickTop) {
            std::cout << "knee pain" << std::endl;
            mario.isGrounded = true;
        }
        // When he hits his head on the bottom
        if (marioBottom < brickBottom && marioTop > brickBottom) {
            std::cout << "bonk" << std::endl;
            mario.velocityY = 2;
        }
    } 
}


void Game::render() {
    window.clear();
    
    window.draw(mario.getSprite());
    window.draw(brick1.getSprite());

    boundingBoxMario.draw(window);
    boundingBoxBrick1.draw(window);

    window.display();
}
