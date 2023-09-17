#include <SFML/Graphics.hpp>
#include <iostream>

float x = 0;
float y = 0;
float velocityX = 0;
float velocityY = 0;
float accelerationX = 0;
float accelerationY = 0;

float gravity = 1;

void updateMovement(sf::Sprite& sprite, sf::RenderWindow& window) {
    // Add gravity
    if (y < 500) {
        velocityY += gravity;
    }
    else if (y > 500) {
        y = 500;
        velocityY = 0;  // Stop vertical movement when the sprite hits the ground
    }

    // Update velocity with acceleration
    velocityX += accelerationX;
    velocityY += accelerationY;

    // Update position
    x += velocityX;
    y += velocityY;

    // Boundary checks to keep the sprite within the window
    if (x < 0) {
        x = 0;
        velocityX = 0;  // Stop horizontal movement when the sprite hits the left border
    }
    if (x + sprite.getLocalBounds().width * 0.1f > window.getSize().x) {
        x = window.getSize().x - sprite.getLocalBounds().width * 0.1f;
        velocityX = 0;  // Stop horizontal movement when the sprite hits the right border
    }
    if (y < 0) {
        y = 0;
        velocityY = 0;  // Stop vertical movement when the sprite hits the top border
    }
    if (y + sprite.getLocalBounds().height * 0.1f > window.getSize().y) {
        y = window.getSize().y - sprite.getLocalBounds().height * 0.1f;
        velocityY = 0;  // Stop vertical movement when the sprite hits the bottom border
    }
}



int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Side-Scrolling Game");

    sf::Texture texture;

    // Load the original image directly into an sf::Texture
    if (!texture.loadFromFile("8bitMario.png"))
    {
        return -1; // Exit the program if texture loading fails.
    }

    // Create a sprite and set its texture
    sf::Sprite sprite(texture);

    // Set the scale of the sprite to resize it (e.g., 0.1 for 10% of the original size)
    sprite.setScale(0.1f, 0.1f); // Adjust this scale as needed

    // Calculate the initial position to ensure the sprite is within the window bounds
    float initialX = (window.getSize().x - sprite.getLocalBounds().width * 0.1f) / 2.0f;
    float initialY = window.getSize().y - sprite.getLocalBounds().height * 0.1f;
    sprite.setPosition(initialX, initialY);

    bool isMovingLeft = false;
    bool isMovingRight = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // change this velocity to make him jump higher
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                velocityY = -20;
            }
            else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Left) {
                    isMovingLeft = false;
                    velocityX = 0; // Stop horizontal movement when left key is released
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    isMovingRight = false;
                    velocityX = 0; // Stop horizontal movement when right key is released
                }
            }
        }

        // Handle keyboard input for movement
        // Change the velocities for change in speed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            isMovingLeft = true;
            isMovingRight = false;
            velocityX = -3;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            isMovingLeft = false;
            isMovingRight = true;
            velocityX = 3;
        }
        else {
            // If neither left nor right keys are pressed, stop horizontal movement
            isMovingLeft = false;
            isMovingRight = false;
            velocityX = 0;
        }

        updateMovement(sprite, window);
        sprite.setPosition(x, y);

        // Render
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
