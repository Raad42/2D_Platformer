#include <iostream>
#include "Player.h"

class PlayerTest {
public:
    void runTests() {
        testMoveLeft();
        testMoveRight();
        testJump();
    }

private:
    void testMoveLeft() {
        Player player;
        player.moveLeft();
        if (!player.getIsMovingLeft() || player.getIsMovingRight() || player.getIsJumping()) {
            std::cout << "Test moveLeft failed!" << std::endl;
        }
    }

    void testMoveRight() {
        Player player;
        player.moveRight();
        if (player.getIsMovingLeft() || !player.getIsMovingRight() || player.getIsJumping()) {
            std::cout << "Test moveRight failed!" << std::endl;
        }
    }

    void testJump() {
        Player player;
        player.jump();
        if (player.getIsMovingLeft() || player.getIsMovingRight() || !player.getIsJumping()) {
            std::cout << "Test jump failed!" << std::endl;
        }
    }
};
