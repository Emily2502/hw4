//
// Created by 97250 on 6/13/2022.
//

#include "Vampire.h"
const int VAMPIRE_FORCE = 10;
const int VAMPIRE_DAMAGE = 10;
const int VAMPIRE_LOOT = 2;
const int VAMPIRE_FORCE_LOST = 1;

Vampire::Vampire() :
        BattleCard("Vampire", VAMPIRE_FORCE, VAMPIRE_DAMAGE, VAMPIRE_LOOT),
        m_forceLost(VAMPIRE_FORCE_LOST) {}

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

void Vampire::applyEncounterAsGang(Player &player, bool& playerLost) const
{
    if (player.getAttackStrength() >= m_force && !playerLost)
    {
        player.addCoins(m_loot);
    }
    else
    {
        playerLost = true;
        player.weaken(m_forceLost);
        player.damage(m_damage);
        printLossBattle(player.getName(),"Vampire");
    }
}
