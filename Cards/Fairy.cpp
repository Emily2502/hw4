//
// Created by 97250 on 6/13/2022.
//

#include "Fairy.h"
// Todo: #defines


Fairy::Fairy() :
        Card("Fairy"),
        m_hpWin(10) {}

void Fairy::applyEncounter(Player &player) const
{
    if (player.getType() == "Wizard")
    {
        player.heal(m_hpWin);
        printFairyMessage(true);
    }
    else
    {
        printFairyMessage(false);
    }
}
