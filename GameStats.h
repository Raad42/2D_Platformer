#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <string>

class GameStats {
private:
    int enemies_killed;
    float high_score;
    int deaths;


public:
    GameStats();

    void update_enemies_killed();
    void update_deaths();
    void update_high_score(float score);

    int getKills();
    int getDeaths();
    float getScore();

    void setKills(int enemies_killedIn);

    // Function to save game statistics to a file
    void saveToFile(const std::string& filename);

    // Function to load game statistics from a file
    void loadFromFile(const std::string& filename);

    void printLast10GameStats(const std::string& filename);
};



#endif