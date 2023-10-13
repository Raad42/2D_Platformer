#include "GameStats.h"
#include "json.hpp"
#include <fstream>
#include <string>
#include <iostream>

using json = nlohmann::json;

GameStats::GameStats()
    : enemies_killed(0), high_score(0), deaths(0) {
    // Load existing stats when the GameStats object is created
    loadStats("game_stats.json");
}

void GameStats::loadStats(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        json gameData;
        inputFile >> gameData;
        inputFile.close();

        // Update class members with loaded data
        if (gameData.find("enemies_killed") != gameData.end()) {
            enemies_killed = gameData["enemies_killed"];
        }
        if (gameData.find("high_score") != gameData.end()) {
            high_score = gameData["high_score"];
        }
        if (gameData.find("deaths") != gameData.end()) {
            deaths = gameData["deaths"];
        }
    }
}

void GameStats::saveStats(const std::string& filename) const {
    json gameData;
    gameData["enemies_killed"] = enemies_killed;
    gameData["high_score"] = high_score;
    gameData["deaths"] = deaths / 6;

    std::ifstream inputFile(filename);
    json existingData;

    if (inputFile.is_open()) {
        inputFile >> existingData;
        inputFile.close();
    }

    existingData.push_back(gameData); // Append the new session's data to the existing data

    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << std::setw(4) << existingData;
        outputFile.close();
    } else {
        std::cout << "output failed" << std::endl;
    }
}

std::string GameStats::getStatsJsonString() const {
    json gameData;
    gameData["enemies_killed"] = enemies_killed;
    gameData["high_score"] = high_score;
    gameData["deaths"] = deaths / 6;
    
    return gameData.dump(4); // Indent and return latest write
}



void GameStats::update_enemies_killed() {
    enemies_killed++;
    saveStats("game_stats.json");
}

void GameStats::update_deaths() {
    deaths++;
    saveStats("game_stats.json");
}

void GameStats::update_high_score(int score) {
    if (score > high_score) {
        high_score = score;
        saveStats("game_stats.json");
    }
}

int GameStats::getKills() {
    return enemies_killed;
}

int GameStats::getDeaths() {
    return deaths / 6;
}
