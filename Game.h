#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Bricks.h"
#include "BoundingBox.h"
#include "Player.h"

class Game {
private:
    sf::RenderWindow window;
    sf::View view;
    sf::Texture textureBackground;
    sf::Sprite background;

    Player player;
    
    Bricks brick1;
    Bricks brick2;
    Bricks brick3;
    BoundingBox boundingBoxBrick1;
    BoundingBox boundingBoxBrick2;
    BoundingBox boundingBoxBrick3;

    sf::Font font1;
    sf::Font font2;
    sf::Text text1;
    sf::Text text2;

    void handleEvent(const sf::Event& event);
    void updateMovement();
    void update();
    void render();

public:
    Game();
    void run();
};

#endif
