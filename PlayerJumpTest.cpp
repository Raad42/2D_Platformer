#include "PlayerJumpTest.h"

void PlayerTest::runTests() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Player Test");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                testJump();
            }
        }
    }
}

int main() {
    PlayerTest playerTest;
    playerTest.runTests();
    return 0;
}
