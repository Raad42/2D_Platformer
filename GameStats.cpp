#include "GameStats.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>


GameStats::GameStats()
    : enemies_killed(0), high_score(0), deaths(0) {
}

void GameStats::update_enemies_killed() {
    enemies_killed++;
}

void GameStats::update_deaths() {
    this->deaths = deaths;
    deaths++;
}

void GameStats::update_high_score(float score) {
    if (score > high_score) {
        high_score = score;
    }
}

void GameStats::setKills(int enemies_killedIn) {
    enemies_killed = enemies_killedIn;
}

int GameStats::getKills() {
    return enemies_killed;
}

int GameStats::getDeaths() {
    return deaths ;
}

float GameStats::getScore() {
    return high_score;
}

void GameStats::saveToFile(const std::string& filename) {
    std::ofstream outputFile(filename, std::ios::app); // Open in append mode

    if (outputFile.is_open()) {
        outputFile << "Enemies Killed: " << getKills() << "; " << "Deaths: " << getDeaths() << "; " << "High Score: " << getScore() << "\n";
        outputFile.close();
    } else {
        std::cout << "Error: Could not open the file for writing." << std::endl;
    }
}

void GameStats::loadFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        inputFile >> enemies_killed >> high_score >> deaths;
        inputFile.close();
    } else {
        std::cout << "Error: Could not open the file for reading." << std::endl;
    }
}

void GameStats::printLast10GameStats(const std::string& filename) {
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string line;
        std::vector<std::string> gameStats;
        bool inGameEntry = false;

        while (std::getline(inputFile, line)) {
                gameStats.push_back(line);
                inGameEntry = true;
            }

        // Print the last 10 game stats
        int startIndex = std::max(0, static_cast<int>(gameStats.size()) - 10);
        for (int i = startIndex; i < gameStats.size(); ++i) {
            std::cout << gameStats[i] << std::endl;
        }

        inputFile.close();
    } else {
        std::cout << "Error: Could not open the file for reading." << std::endl;
    }
}