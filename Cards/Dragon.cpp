//
// Created by 97250 on 6/13/2022.
//
#include "Dragon.h"
const int DRAGON_FORCE = 25;
const int DRAGON_DAMAGE = -1;
const int DRAGON_LOOT = 1000;


Dragon::Dragon() :
        BattleCard("Dragon", DRAGON_FORCE, DRAGON_DAMAGE, DRAGON_LOOT) {}

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

void Dragon::applyEncounterAsGang(Player &player, bool& playerLost) const
{
    if (player.getAttackStrength() >= m_force && !playerLost)
    {
        player.addCoins(m_loot);
    }
    else
    {
        playerLost = true;
        player.damage(player.getHP());
        printLossBattle(player.getName(),"Dragon");
    }
}
