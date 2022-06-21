//
// Created by 97250 on 6/20/2022.
//

#include "Gang.h"
using std::deque;
using std::string;


Gang::Gang(deque<string> &gang):
        Card("Gang")
{
    while (!gang.empty())
    {
        m_gang.push_back(createBattleCard(gang.front()));
        gang.pop_front();
    }
}

void Gang::applyEncounter(Player &player) const
{
    bool playerLost = false;
    for (int i = 0; i < int(m_gang.size()); i++)
    {
        m_gang[i]->applyEncounterAsGang(player,playerLost);
    }
    if (!playerLost)
    {
        player.levelUp();
        printWinBattle(player.getName(),"Gang");
    }
}

