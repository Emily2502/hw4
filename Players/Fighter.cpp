//
// Created by 97250 on 6/12/2022.
//

#include "Fighter.h"

int Fighter::getAttackStrength() const
{
    return 2 * Player::getAttackStrength() - Player::getLevel();
}

std::string Fighter::getType() const
{
    return "Fighter";
}

