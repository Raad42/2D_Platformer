#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <iostream>
#include <SFML/Graphics.hpp>

class MockPlayer {
public:
    void moveLeft() {
        isMovingLeft = true;
        isMovingRight = false;
    }

    bool getIsMovingLeft() {
        return isMovingLeft;
    }

    bool getIsMovingRight() {
        return isMovingRight;
    }

    void reset() {
        isMovingLeft = false;
        isMovingRight = false;
    }

private:
    bool isMovingLeft = false;
    bool isMovingRight = false;
};

class PlayerTest {
public:
    void runTests();
    void testMoveLeft() {
        player.moveLeft();

        if (player.getIsMovingLeft() && !player.getIsMovingRight()) {
            std::cout << "TestMoveLeft passed!\n";
        } else {
            std::cerr << "TestMoveLeft failed: Player movement not as expected!\n";
            exit(1);
        }

        player.reset();
    }

private:
    MockPlayer player;
};

#endif  // PLAYER_TEST_H
