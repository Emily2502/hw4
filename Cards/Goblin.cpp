//
// Created by 97250 on 6/13/2022.
//

#include "Goblin.h"
const int GOBLIN_FORCE = 6;
const int GOBLIN_DAMAGE = 10;
const int GOBLIN_LOOT = 2;

Goblin::Goblin() :
        BattleCard("Goblin", GOBLIN_FORCE, GOBLIN_DAMAGE, GOBLIN_LOOT) {}

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

void Goblin::applyEncounterAsGang(Player &player, bool& playerLost) const
{
    if (player.getAttackStrength() >= m_force && !playerLost)
    {
        player.addCoins(m_loot);
    }
    else
    {
        playerLost = true;
        player.damage(m_damage);
        printLossBattle(player.getName(),"Goblin");
    }
}
