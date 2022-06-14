//
// Created by 97250 on 6/13/2022.
//

#include "Vampire.h"

Vampire::Vampire() :
        BattleCard("Vampire", 10, 10, 2),
        m_forceLost(1) {}

void Vampire::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),"Vampire");
    }
    else
    {
        player.weaken(m_forceLost);
        player.damage(m_damage);
        printLossBattle(player.getName(),"Vampire");
    }
}
