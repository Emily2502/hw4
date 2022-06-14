//
// Created by 97250 on 6/12/2022.
//

#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H
#include "Player.h"

class Fighter : public Player {

public:

    /**
     * C'tor of Fighter class
     *
     * @param name - The name of the player.
     * @return
     *      A new instance of Fighter.
    */
    explicit Fighter(const std::string &name): Player(name) {}

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Fighter(const Fighter&) = default;
    Fighter& operator=(const Fighter&) = default;
    ~Fighter() override = default;

    /**
     * Gets attack strength of a fighter
     *
     * @return
     *      attack strength of said fighter
    */
    int getAttackStrength() const override;

    /**
     * Gets type of a fighter
     *
     * @return
     *      name of said type
    */
    std::string getType() const override;
};


#endif //HW4_FIGHTER_H
