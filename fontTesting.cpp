#include <SFML/Graphics.hpp>
#include <iostream>

float x = 0;
float y = 0;
float velocityX = 0;
float velocityY = 0;
float accelerationX = 0;
float accelerationY = 0;

float gravity = 1;
// This was to see if I could fix something, couldn't :( (it doesnt do anything now)
bool isJumping = false;

// ----------------- MARIO CAN CURRENTLY SPAM JUMP IDK HOW TO CHANGE IT ------------------
 
void updateMovement(sf::Sprite& sprite, sf::RenderWindow& window) {
    // Add gravity
    if (y < 600) {
        velocityY += gravity;
    }
    else if (y > 600) {
        y = 600;
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

    sf::Font font1;
    if (!font1.loadFromFile("IMPACTFUL.ttf"))
    {
        return -1; // Exit the program if font loading fails.
    }
    sf::Font font2;
    if (!font2.loadFromFile("ClassicalDiary.ttf"))
    {
        return -1; // Exit the program if font loading fails.
    }

    sf::Text text1;
    text1.setFont(font1);
    text1.setString("MARIO 2D PLATFORMER");
    text1.setCharacterSize(24);
    text1.setFillColor(sf::Color::Red);
    text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1.setPosition(250.f, 0.f);

    sf::Text text2;
    text2.setFont(font2);
    text2.setString("this is a test to see how this shit will look");
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::Blue);
    //text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text2.setPosition(150.f, 50.f);







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
    sprite.setScale(0.05f, 0.05f);

    // Calculate the initial position to ensure the sprite is within the window bounds
    // This can be removed but might need it later
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
            // Change this velocity to make him jump higher
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                velocityY = -20;
                isJumping = true;
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
        window.draw(text1);
        window.draw(text2);
        window.display();
    }

    return 0;
}
