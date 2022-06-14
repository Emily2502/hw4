//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H
#include "Card.h"


class Fairy : public Card {
public:

    /**
     * C'tor of Fairy class
     *
     *
     * @return
     *      A new instance of Fairy.
    */
    Fairy();


    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Fairy(const Fairy&) = default;
    Fairy& operator=(const Fairy& other) = default;
    ~Fairy() override = default;


    /**
     * Handling the player's applyEncounter with a Fairy card
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

private:
    int m_hpWin;

};


#endif //HW4_FAIRY_H
