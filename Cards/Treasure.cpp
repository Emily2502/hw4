//
// Created by 97250 on 6/13/2022.
//

#include "Treasure.h"
// Todo: #defines

Treasure::Treasure() :
    Card("Treasure"),
    m_coins(10) {}

void Treasure::applyEncounter(Player &player) const
{
    player.addCoins(m_coins);
    printTreasureMessage();
}
