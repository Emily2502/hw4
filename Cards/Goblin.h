//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H
#include "BattleCard.h"

class Goblin : public BattleCard {

public:

    /**
     * C'tor of Goblin class
     *
     *
     * @return
     *      A new instance of Goblin.
    */
    Goblin();

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Goblin(const Goblin&) = default;
    Goblin& operator=(const Goblin& other) = default;
    ~Goblin() override = default;

    /**
     * Handling the player's encounter with a Goblin card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /**
     * Handling the player's encounter with a Goblin card in a gang
     *
     * @param player - The player.
     * @param playerLost - true if said player had previously lost to card in gang.
     * @return
     *      void
    */
    void applyEncounterAsGang(Player& player, bool& playerLost) const override;
};


#endif //HW4_GOBLIN_H
