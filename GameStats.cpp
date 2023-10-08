#include "GameStats.h"

GameStats::GameStats()
    : enemies_killed(0), damage_taken(0), damage_dealt(0), high_score(0) {}

void GameStats::update_enemies_killed() {
    enemies_killed++;
}

void GameStats::update_damage_taken(int damage) {
    damage_taken += damage;
}

void GameStats::update_damage_dealt(int damage) {
    damage_dealt += damage;
}

void GameStats::update_high_score(int score) {
    if (score > high_score) {
        high_score = score;
    }
}