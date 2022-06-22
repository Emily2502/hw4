//
// Created by 97250 on 6/13/2022.
//

#include "Treasure.h"
const int TREASURE_COINS = 10;


Treasure::Treasure() :
    Card("Treasure"),
    m_coins(TREASURE_COINS) {}

void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(m_coins);
    printTreasureMessage();
}
