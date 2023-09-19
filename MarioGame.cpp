#include <SFML/Graphics.hpp>
#include "MarioGame.h"
#include "MarioP.h"
#include <string>

MarioGame::MarioGame(int sizeWidth, int sizeHeight, std::string title){
    window = new sf::RenderWindow(sf::VideoMode(sizeWidth, sizeHeight), title);
    Mario = new MarioP(0,0);
};

void MarioGame::run(){
    while (window->isOpen()){
        sf::Event event; 
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            //Make this part better
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Left) {
                    Mario->stopMoving();
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    Mario->stopMoving();
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                    Mario->jump();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                Mario->moveLeft();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                Mario->moveRight();
            }

            else{
                Mario->stopMoving();
            }
            Mario->updateMovement(*window); //Test this i dont think this is right; do u pass pointer
            Mario->setPosition(Mario->getX(),Mario->getY()); //Idk if this is good or not
        }
        window->clear();
        Mario->draw(*window); //Test this i dont think this is right; do u pass pointer
        window->display();
    }
};

//~MarioGame::MarioGame();