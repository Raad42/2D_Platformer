#ifndef POWERUP_H
#define POWERUP_H

#include <string>

class PowerUp {
private:
    std::string bonus_type;
    int bonus_value;
public:
    PowerUp(const std::string& bonusType, int bonusValue);

    std::string get_bonus_type() const;
    int get_bonus_value() const;
};


#endif