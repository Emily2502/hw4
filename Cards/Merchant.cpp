//
// Created by 97250 on 6/13/2022.
//

#include "Merchant.h"
const int MERCHANT_HEALTH_POTION = 1;
const int MERCHANT_HEALTH_POTION_PRICE = 5;
const int MERCHANT_FORCE_BOOST = 1;
const int MERCHANT_FORCE_BOOST_PRICE = 10;
const int MERCHANT_HEALTH_POTION_INPUT = 1;
const int MERCHANT_FORCE_BOOST_INPUT = 2;


Merchant::Merchant() :
    Card("Merchant"),
    m_healthPotion(MERCHANT_HEALTH_POTION),
    m_healthPotionPrice(MERCHANT_HEALTH_POTION_PRICE),
    m_forceBoost(MERCHANT_FORCE_BOOST),
    m_forceBoostPrice(MERCHANT_FORCE_BOOST_PRICE) {}

void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter
            (std::cout, player.getName(), player.getCoins());

    std::string buffer;

    while (!std::getline(std::cin, buffer) || buffer.size() != 1 || buffer[0] < '0' || buffer[0] > '2')
    {
       printInvalidInput();
    }

    int input = std::stoi(buffer);
    int cost = 0;

    if (input == MERCHANT_HEALTH_POTION_INPUT)
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
    else if (input == MERCHANT_FORCE_BOOST_INPUT)
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
