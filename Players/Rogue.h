//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H
#include "Player.h"


class Rogue : public Player {

public:

    /**
     * C'tor of Fighter class
     *
     * @param name - The name of the player.
     * @return
     *      A new instance of Fighter.
    */
    explicit Rogue(const std::string &name): Player(name) {}

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Rogue(const Rogue&) = default;
    Rogue& operator=(const Rogue&) = default;
    ~Rogue() override = default;

    /**
     * Increases number of coins of a player
     *
     * @param coinsToAdd - Number of points to increase player's coins by.
     * @return
     *      void
    */
    void addCoins(int coinsToAdd) override;


    /**
     * Gets type of a fighter
     *
     * @return
     *      name of said type
    */
    std::string getType() const override;
};




#endif //HW4_ROGUE_H
