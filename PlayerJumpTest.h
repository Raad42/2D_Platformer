#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

class TestablePlayer {
public:
    TestablePlayer() : isJumping(false) {}

    void jump() {
        isJumping = true;
    }

    bool getIsJumping() const {
        return isJumping;
    }

private:
    bool isJumping;
};

class PlayerTest {
public:
    PlayerTest() = default;

    void runTests();
    void testJump() {
        player.jump();
        if (player.getIsJumping()) {
            std::cout << "TestJump passed!\n";
        } else {
            std::cerr << "TestJump failed: Player jump not as expected!\n";
            exit(1);
        }
    }

private:
    TestablePlayer player;
};

#endif  // PLAYER_TEST_H
