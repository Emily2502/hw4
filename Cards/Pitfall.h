//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H
#include "Card.h"


class Pitfall : public Card {

public:

    /**
     * C'tor of Pitfall class
     *
     *
     * @return
     *      A new instance of Pitfall.
    */
    Pitfall();


    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Pitfall(const Pitfall&) = default;
    Pitfall& operator=(const Pitfall& other) = default;
    ~Pitfall() override = default;


    /**
     * Handling the player's applyEncounter with a Pitfall card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    int m_hpLost;

};


#endif //HW4_PITFALL_H
