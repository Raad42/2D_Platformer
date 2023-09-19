#include <SFML/Graphics.hpp>
#include <string>

#ifndef MARIOGAME_H
#define MARIOGAME_H

#include "MarioP.h"

//Basically runs the game window

class MarioGame{
    private:
        sf::RenderWindow* window;
        MarioP* Mario;
    public: 
        MarioGame(int sizeWidth, int sizeHeight, std::string title);
        void run();
        ~MarioGame();
};

#endif 