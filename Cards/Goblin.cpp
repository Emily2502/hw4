//
// Created by 97250 on 6/13/2022.
//

#include "Goblin.h"

Goblin::Goblin() :
        BattleCard("Goblin", 6, 10, 2) {}

void Goblin::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),"Goblin");
    }
    else
    {
        player.damage(m_damage);
        printLossBattle(player.getName(),"Goblin");
    }
}
