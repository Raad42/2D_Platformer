#include "GameStatsTest.h"
#include <iostream>

GameStatsTest::GameStatsTest() {}

void GameStatsTest::runAllTests() {
    std::cout << "Running tests...\n";
    testInitialValues();
    testUpdateEnemiesKilled();
    testUpdateDeaths();
    testUpdateHighScore();
    std::cout << "Finished GameStats tests.\n";
}

void GameStatsTest::testInitialValues() {
    if (gameStatsUnderTest.getKills() == 0 && gameStatsUnderTest.getDeaths() == 0) {
        std::cout << "Initial values test passed!\n";
    } else {
        std::cout << "Initial values test failed.\n";
    }
}

void GameStatsTest::testUpdateEnemiesKilled() {
    gameStatsUnderTest.update_enemies_killed();
    if (gameStatsUnderTest.getKills() == 1) {
        std::cout << "Update enemies killed test passed!\n";
    } else {
        std::cout << "Update enemies killed test failed.\n";
    }
}

void GameStatsTest::testUpdateDeaths() {
    gameStatsUnderTest.update_deaths();
    if (gameStatsUnderTest.getDeaths() == 1) {
        std::cout << "Update deaths test passed!\n";
    } else {
        std::cout << "Update deaths test failed.\n";
    }
}

void GameStatsTest::testUpdateHighScore() {
    gameStatsUnderTest.update_high_score(100);
    std::cout << "No getter to update highscore.\n";
}

int main() {
    GameStatsTest tester;
    tester.runAllTests();
    return 0;
}
