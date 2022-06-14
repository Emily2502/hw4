//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H
#include "Card.h"

class Treasure : public Card {

public:

    /**
     * C'tor of Treasure class
     *
     *
     * @return
     *      A new instance of Treasure.
    */
    Treasure();

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Treasure(const Treasure&) = default;
    Treasure& operator=(const Treasure& other) = default;
    ~Treasure() override = default;

    /**
     * Handling the player's applyEncounter with a Treasure card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    int m_coins;

};


#endif //HW4_TREASURE_H
