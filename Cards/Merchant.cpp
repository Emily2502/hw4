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

    std::string buffer;
    std::cin >> buffer;

    while (buffer.size() != 1 || buffer[0] < '0' || buffer[0] > '2')
    {
       printInvalidInput();
       std::cin >> buffer;
    }

    int input = std::stoi(buffer);
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
            player.buff(m_forceBoost);
            cost = m_forceBoostPrice;
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    printMerchantSummary(std::cout, player.getName(), input, cost);
}
