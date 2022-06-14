//
// Created by 97250 on 6/13/2022.
//

#include "BattleCard.h"

BattleCard::BattleCard(const std::string &name, int force, int damage, int loot) :
        Card(name),
        m_force(force),
        m_damage(damage),
        m_loot(loot) {}

void BattleCard::printCard(std::ostream &os) const
{
    Card::printCard(os);
    printMonsterDetails(os, m_force, m_damage, m_loot);
}


