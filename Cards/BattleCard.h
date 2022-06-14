//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_BATTLECARD_H
#define HW4_BATTLECARD_H
#include "Card.h"

class BattleCard : public Card {

public:

    /**
     * C'tor of BattleCard class
     *
     *
     * @return
     *      A new instance of BattleCard.
    */
    BattleCard(const std::string& name, int force, int damage, int loot);

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    BattleCard(const BattleCard&) = default;
    BattleCard& operator=(const BattleCard& other) = default;
    ~BattleCard() override = default;

    /**
     * Prints information of a Card as requested:
     *
     * @return
     *      reference to std::ostream
    */
    void printCard(std::ostream &os) const override;

    /**
     * Handling the player's applyEncounter with a battle card
     * Class BattleCard is an interface!
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override = 0;

protected:
    int m_force;
    int m_damage;
    int m_loot;
};


#endif //HW4_BATTLECARD_H
