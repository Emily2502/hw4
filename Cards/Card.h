//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_CARD_H
#define HW4_CARD_H
#include "../Players/Player.h"
#include "../utilities.h"
#include <iostream>

class Card {

public:

    /**
     * C'tor of Card class
     *
     *
     * @return
     *      A new instance of Card.
    */
    explicit Card(const std::string& name) : m_name(name) {}

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Card(const Card&) = default;
    Card& operator=(const Card& other) = default;
    virtual ~Card() = default;

    /**
     * Prints information of a Card as requested:
     *
     * @return
     *      reference to std::ostream
    */
    virtual void printCard(std::ostream &os) const;


    /**
     * Handling the player's applyEncounter with a card
     * Class Card is an interface!
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;

private:
    std::string m_name;
};

std::ostream& operator<<(std::ostream& os, const Card& card);


#endif //HW4_CARD_H
