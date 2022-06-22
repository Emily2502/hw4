//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H
#include "BattleCard.h"


class Dragon : public BattleCard {

public:

    /**
     * C'tor of Dragon class
     *
     *
     * @return
     *      A new instance of Dragon.
    */
    Dragon();

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon& other) = default;
    ~Dragon() override = default;

    /**
     * Prints information of a Card as requested:
     *
     * @return
     *      reference to std::ostream
    */
    void printCard(std::ostream &os) const override;


    /**
     * Handling the player's encounter with a Dragon card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /**
     * Handling the player's encounter with a Dragon card in a gang
     *
     * @param player - The player.
     * @param playerLost - true if said player had previously lost to card in gang.
     * @return
     *      void
    */
    void applyEncounterAsGang(Player& player, bool& playerLost) const override;

};


#endif //HW4_DRAGON_H
