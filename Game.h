#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow window;
    sf::View view;
    sf::Texture textureBackground;
    sf::Sprite background;

    // Other game-specific variables and objects go here...

    void handleEvent(const sf::Event& event);
    void update();
    void render();

public:
    Game();
    void run();
};

#endif
