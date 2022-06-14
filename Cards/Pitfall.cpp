//
// Created by 97250 on 6/13/2022.
//

#include "Pitfall.h"
// Todo: #defines


Pitfall::Pitfall() :
        Card("Pitfall"),
        m_hpLost(10) {}

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
