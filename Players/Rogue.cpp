//
// Created by 97250 on 6/13/2022.
//

#include "Rogue.h"

void Rogue::addCoins(int coinsToAdd)
{
    Player::addCoins(2 * coinsToAdd);
}

std::string Rogue::getType() const
{
    return "Rogue";
}
