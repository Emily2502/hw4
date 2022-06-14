//
// Created by 97250 on 6/13/2022.
//

#include "Merchant.h"
// Todo: #defines

Merchant::Merchant() :
    Card("Merchant"),
    m_healthPotion(1),
    m_healthPotionPrice(5),
    m_forceBoost(1),
    m_forceBoostPrice(10) {}

void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter
            (std::cout, player.getName(), player.getCoins());
    int input = -1;
    std::cin >> input;

    while (input != 0 && input != 1 && input != 2)
    {
       printInvalidInput();
       std::cin >> input;
    }

    int cost = 0;

    if (input == 1)
    {
        if (player.pay(m_healthPotionPrice))
        {
            player.heal(m_healthPotion);
            cost = m_healthPotionPrice;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    else if (input == 2)
    {
        if (player.pay(m_forceBoostPrice))
        {
            player.heal(m_forceBoost);
            cost = m_forceBoostPrice;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    printMerchantSummary(std::cout, player.getName(), input, cost);
}
