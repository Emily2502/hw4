//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H
#include "Card.h"


class Barfight : public Card {

public:

    /**
     * C'tor of Barfight class
     *
     *
     * @return
     *      A new instance of Barfight.
    */
    Barfight();


    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight& other) = default;
    ~Barfight() override = default;


    /**
     * Handling the player's applyEncounter with a Barfight card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    int m_hpLost;

};


#endif //HW4_BARFIGHT_H
