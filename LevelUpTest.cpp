#include "LevelUpTest.h"
#include <iostream>


LevelUpTest::LevelUpTest() {
    // Assuming these images are in the same directory as your executable
    if (!level1Texture.loadFromFile("level1BG.png")) {
        std::cerr << "Failed to load level1BG.png" << std::endl;
        exit(1);
    }

    if (!level2Texture.loadFromFile("level2BG.png")) {
        std::cerr << "Failed to load level2BG.png" << std::endl;
        exit(1);
    }

    backgroundSprite.setTexture(level1Texture);
}

void LevelUpTest::runTests() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Level Up Test");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N) {
                testLevelUp();
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        window.display();
    }
}

void LevelUpTest::testLevelUp() {
    backgroundSprite.setTexture(level2Texture);
    std::cout << "Level Up Test passed!\n";
}

int main() {
    LevelUpTest levelUpTest;
    levelUpTest.runTests();
    return 0;
}
