//
// Created by 97250 on 6/13/2022.
//

#include "Barfight.h"
const int BARFIGHT_HP_LOST = 10;

Barfight::Barfight() :
        Card("Barfight"),
        m_hpLost(BARFIGHT_HP_LOST) {}

void Barfight::applyEncounter(Player &player) const
{
    if (player.getType() != "Fighter")
    {
        player.damage(m_hpLost);
        printBarfightMessage(false);
    }
    else
    {
        printBarfightMessage(true);
    }
}
