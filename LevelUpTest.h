#ifndef LEVEL_UP_TEST_H
#define LEVEL_UP_TEST_H

#include <SFML/Graphics.hpp>

class LevelUpTest {
public:
    LevelUpTest();

    void runTests();
    void testLevelUp();

private:
    sf::Texture level1Texture;
    sf::Texture level2Texture;
    sf::Sprite backgroundSprite;
};

#endif  // LEVEL_UP_TEST_H
