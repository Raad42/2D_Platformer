#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "json.hpp"
#include <cstring>

class GameStats {
private:
    int enemies_killed;
    int high_score;
    int deaths;

public:
    GameStats();
    
    // Methods to load and save stats
    void loadStats(const std::string& filename);
    void saveStats(const std::string& filename) const;
    std::string getStatsJsonString() const;

    void update_enemies_killed();
    void update_deaths();
    void update_high_score(int score);
    int getKills();
    int getDeaths();
};



#endif