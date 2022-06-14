//
// Created by 97250 on 6/13/2022.
//

#include "Dragon.h"

Dragon::Dragon() :
        BattleCard("Dragon", 25, -1, 1000) {}

void Dragon::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),"Dragon");
    }
    else
    {
        player.damage(player.getHP());
        printLossBattle(player.getName(),"Dragon");
    }
}

void Dragon::printCard(std::ostream &os) const
{
    Card::printCard(os);
    printMonsterDetails(os, m_force, m_damage, m_loot, true);
}
