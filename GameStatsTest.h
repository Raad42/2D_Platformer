#ifndef GAMESTATS_TEST_H
#define GAMESTATS_TEST_H

#include "GameStats.h"

class GameStatsTest {
public:
    GameStatsTest();
    void runAllTests();

private:
    void testInitialValues();
    void testUpdateEnemiesKilled();
    void testUpdateDamageTaken();
    void testUpdateDamageDealt();
    void testUpdateDeaths();
    void testUpdateHighScore();

    GameStats gameStatsUnderTest;
};

#endif  // GAMESTATS_TEST_H
