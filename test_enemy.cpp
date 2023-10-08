#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Enemy {
    sf::RectangleShape body;
    bool alive;

public:
    Enemy() {
        // Load an image for the enemy
        sf::Texture texture;
        if (!texture.loadFromFile("enemy_texture.png")) {
            std::cerr << "Failed to load enemy texture!" << std::endl;
            // Handle the error (e.g., set a default color)
            body.setFillColor(sf::Color::Red);
        } else {
            // If the texture is loaded successfully, set it for the body
            body.setTexture(&texture);
        }

        body.setSize(sf::Vector2f(40, 40)); // Set the size of the enemy
        body.setPosition(-1, -1);
        body.setOrigin(20, 20);
        alive = false;
    }

    void spawn(int x, int y) {
        int rand_y = rand() % y + 1;
        body.setPosition(x, rand_y);
        this->alive = true;
    }

    void draw(sf::RenderWindow* win) {
        if (this->alive) {
            body.move(-0.1, 0);
            win->draw(body);
        }
    }
};
