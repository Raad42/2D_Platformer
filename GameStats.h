#ifndef GAMESTATS_H
#define GAMESTATS_H

class GameStats {
public:
    GameStats();

    void update_enemies_killed();
    void update_damage_taken(int damage);
    void update_damage_dealt(int damage);
    void update_high_score(int score);

private:
    int enemies_killed;
    int damage_taken;
    int damage_dealt;
    int high_score;
};


#endif