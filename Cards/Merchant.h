//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H
#include "Card.h"

class Merchant : public Card {

public:

    /**
     * C'tor of Merchant class
     *
     *
     * @return
     *      A new instance of Merchant.
    */
    Merchant();

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Merchant(const Merchant&) = default;
    Merchant& operator=(const Merchant& other) = default;
    ~Merchant() override = default;

    /**
     * Handling the player's applyEncounter with a Merchant card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    int m_healthPotion;
    int m_healthPotionPrice;
    int m_forceBoost;
    int m_forceBoostPrice;
};



#endif //HW4_MERCHANT_H
