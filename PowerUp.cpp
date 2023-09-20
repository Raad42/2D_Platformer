#include "PowerUp.h"

PowerUp::PowerUp(const std::string& bonusType, int bonusValue)
    : bonus_type(bonusType), bonus_value(bonusValue) {}

std::string PowerUp::get_bonus_type() const {
    return bonus_type;
}

int PowerUp::get_bonus_value() const {
    return bonus_value;
}
