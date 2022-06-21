//
// Created by 97250 on 6/13/2022.
//

#include "Pitfall.h"
const int PITFALL_HP_LOST = 10;


Pitfall::Pitfall() :
        Card("Pitfall"),
        m_hpLost(PITFALL_HP_LOST) {}

void Pitfall::applyEncounter(Player &player) const
{
    if (player.getType() != "Rogue")
    {
        player.damage(m_hpLost);
        printPitfallMessage(false);
    }
    else
    {
        printPitfallMessage(true);
    }
}
