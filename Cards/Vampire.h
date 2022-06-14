//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_VAMPIRE_H
#define HW4_VAMPIRE_H
#include "BattleCard.h"


class Vampire : public BattleCard {

public:

    /**
     * C'tor of Vampire class
     *
     *
     * @return
     *      A new instance of Vampire.
    */
    Vampire();

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Vampire(const Vampire&) = default;
    Vampire& operator=(const Vampire& other) = default;
    ~Vampire() override = default;

    /**
     * Handling the player's applyEncounter with a Vampire card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    int m_forceLost;
};


#endif //HW4_VAMPIRE_H
