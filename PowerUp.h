#ifndef POWERUP_H
#define POWERUP_H

#include <string>

class PowerUp {
private:
    // for different types of power-ups
    std::string bonus_type;
    int bonus_value;
   
public:
    PowerUp(const std::string& bonusType, int bonusValue);

    // functions to determine powerup type and affect
    std::string get_bonus_type() const;
    int get_bonus_value() const;
    bool get_IsCollected();
};


#endif