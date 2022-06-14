//
// Created by 97250 on 6/13/2022.
//

#include "Barfight.h"
// Todo: #defines


Barfight::Barfight() :
        Card("Barfight"),
        m_hpLost(10) {}

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
