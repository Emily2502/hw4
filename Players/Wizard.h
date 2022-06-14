//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_WIZARD_H
#define HW4_WIZARD_H
#include "Player.h"

class Wizard : public Player {

public:

    /**
     * C'tor of Fighter class
     *
     * @param name - The name of the player.
     * @return
     *      A new instance of Fighter.
    */
    explicit Wizard(const std::string &name): Player(name) {}

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Wizard(const Wizard&) = default;
    Wizard& operator=(const Wizard&) = default;
    ~Wizard() override = default;


    /**
     * Increases HP of a player
     *
     * @param hpPointsToAdd - Number of points to increase player's HP by.
     * @return
     *      void
    */
    void heal(int hpPointsToUpgrade) override;


    /**
     * Gets type of a fighter
     *
     * @return
     *      name of said type
    */
    std::string getType() const override;
};


#endif //HW4_WIZARD_H
