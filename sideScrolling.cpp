#include <SFML/Graphics.hpp>
#include <iostream>

float x = 0;
float y = 0;
float velocityX = 0;
float velocityY = 0;
float accelerationX = 0;
float accelerationY = 0;

// for game world
int numSections = 6;
float sectionWidth = 1200.0f;
float gameWorldWidth = numSections * sectionWidth;

float gravity = 1;
// This was to see if I could fix something, couldn't :( (it doesnt do anything now)
bool isJumping = false;

// platform logic for gravity stopping
bool isGrounded = false;


// ----------------- MARIO CAN CURRENTLY SPAM JUMP IDK HOW TO CHANGE IT ------------------
 
void updateMovement(sf::Sprite& Mario, sf::RenderWindow& window) {
    // Add gravity
    velocityY += gravity;

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
    if (x + Mario.getLocalBounds().width * 0.1f > gameWorldWidth) {
        x = gameWorldWidth - Mario.getLocalBounds().width * 0.1f;
        velocityX = 0;  // Stop horizontal movement when the sprite hits the right border
    }
    if (y < 0) {
        y = 0;
        velocityY = 0;  // Stop vertical movement when the sprite hits the top border
    }
    if (y + Mario.getLocalBounds().height * 0.1f > window.getSize().y) {
        y = window.getSize().y - Mario.getLocalBounds().height * 0.1f;
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
    text1.setPosition(350.f, 0.f);

    sf::Text text2;
    text2.setFont(font2);
    text2.setString("this is a test to see how this shit will look");
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::Blue);
    //text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text2.setPosition(250.f, 50.f);

    
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Side-Scrolling Game");

    // Set up the view
    sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    window.setView(view);

    sf::Texture textureMario;

    // Load the original image directly into an sf::Texture
    if (!textureMario.loadFromFile("8bitMario.png"))
    {
        return -1; // Exit the program if texture loading fails.
    }

    // Create a sprite and set its texture
    sf::Sprite Mario(textureMario);

    // Set the scale of the sprite to resize it (e.g., 0.1 for 10% of the original size)
    Mario.setScale(0.05f, 0.05f);

    sf::Texture textureBricks;

    // Load the original image directly into an sf::Texture
    if (!textureBricks.loadFromFile("Bricks.png"))
    {
        return -1; // Exit the program if texture loading fails.
    }

    // Create a sprite and set its texture
    sf::Sprite Bricks(textureBricks);

    // Set the scale of the sprite to resize it (e.g., 0.1 for 10% of the original size)
    Bricks.setScale(0.4f, 0.2f);

    Bricks.setPosition(400.f, 600.f);

    
    // // check collision with a point
    // sf::Vector2f point = ...;
    // if (boundingBoxMario.contains(point))
    // {
    //     // collision!
    // }

    // Calculate the initial position to ensure the sprite is within the window bounds
    // This can be removed but might need it later
    // float initialX = (window.getSize().x - Mario.getLocalBounds().width * 0.1f) / 2.0f;
    // float initialY = window.getSize().y - Mario.getLocalBounds().height * 0.1f;
    // Mario.setPosition(initialX, initialY);

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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                    velocityY = -20;
                    isJumping = true;
                }

            if (event.type == sf::Event::KeyReleased) {
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

        // Update character's movement
        updateMovement(Mario, window);
        Mario.setPosition(x, y);

        // Update the view's position to follow the character
        view.setCenter(x + Mario.getLocalBounds().width * 0.1f, window.getSize().y / 2);
        window.setView(view);

        // Get bounding Box
        sf::FloatRect boundingBoxMario = Mario.getGlobalBounds();

        // Create a rectangle shape to represent the bounding box
        sf::RectangleShape boundingBoxShape;
        boundingBoxShape.setSize(sf::Vector2f(boundingBoxMario.width, boundingBoxMario.height));
        boundingBoxShape.setPosition(boundingBoxMario.left, boundingBoxMario.top);
        boundingBoxShape.setFillColor(sf::Color::Transparent);  // Set the color of the bounding box
        boundingBoxShape.setOutlineColor(sf::Color::Red);                      // Set the outline color
        boundingBoxShape.setOutlineThickness(2);  // Set the outline thickness


        // Get bounding Box
        sf::FloatRect boundingBoxBricks = Bricks.getGlobalBounds();

        // Create a rectangle shape to represent the bounding box
        sf::RectangleShape boundingBoxShape2;
        boundingBoxShape2.setSize(sf::Vector2f(boundingBoxBricks.width, boundingBoxBricks.height));
        boundingBoxShape2.setPosition(boundingBoxBricks.left, boundingBoxBricks.top);  
        boundingBoxShape2.setFillColor(sf::Color::Transparent);  // Set the color of the bounding box
        boundingBoxShape2.setOutlineColor(sf::Color::Red);                      // Set the outline color
        boundingBoxShape2.setOutlineThickness(2);  // Set the outline thickness

        //check collision with another box (like the bounding box of another entity)
        if (boundingBoxMario.intersects(boundingBoxBricks))
        {
            velocityY = 0;
        }

        // Render
        window.clear();
        window.draw(Mario);
        window.draw(Bricks);
        window.draw(text1);
        window.draw(text2);
        window.draw(boundingBoxShape);
        window.draw(boundingBoxShape2);
        window.display();
    }

    return 0;
}
