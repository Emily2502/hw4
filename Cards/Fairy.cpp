//
// Created by 97250 on 6/13/2022.
//

#include "Fairy.h"
const int FAIRY_HP_WIN = 10;


Fairy::Fairy() :
        Card("Fairy"),
        m_hpWin(FAIRY_HP_WIN) {}

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
