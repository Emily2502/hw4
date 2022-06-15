//
// Created by 97250 on 6/13/2022.
//

#ifndef HW4_MTMCHKIN_H
#define HW4_MTMCHKIN_H

#include "Cards/Card.h"
#include "Cards/Goblin.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Fairy.h"
#include "Players/Player.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Exception.h"
#include "utilities.h"
#include <deque>
#include <memory>
#include <fstream>
#include <map>


class Mtmchkin {

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * and delete copy c'tor and assignment operator (the big 3)
    */
    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin&) = delete;
    ~Mtmchkin() = default;

private:
    std::deque<std::unique_ptr<Card>> m_deck;
    std::deque<std::unique_ptr<Player>> m_winners;
    std::deque<std::unique_ptr<Player>> m_losers;
    std::deque<std::unique_ptr<Player>> m_players;
    int m_rounds;
};

/**------------------------ helper functions for c'tor --------------------------*/

template<class T>
std::unique_ptr<Card> createCardInstance()
{
    return std::unique_ptr<Card>(new T);
}

template<class T>
std::unique_ptr<Player> createPlayerInstance(const std::string& name)
{
    return std::unique_ptr<Player>(new T(name));
}

static std::unique_ptr<Card> createCard(const std::string& name);

static void readCards(const std::string& sourceFileName, std::deque<std::unique_ptr<Card>>& cardDeck);

static std::unique_ptr<Player> createPlayer(const std::string& name, const std::string& character);

static void getPlayers(std::deque<std::unique_ptr<Player>>& queue);

static bool cardNameIsValid(const std::string& card);

static int receiveSize();

static void receivePlayerName(std::string& playerName, std::string& playerCharacter);

static bool characterNameIsValid(const std::string& character);

/**------------------------------------------------------------------------------*/


#endif //HW4_MTMCHKIN_H
