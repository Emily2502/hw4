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
#include "Cards/Gang.h"

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



/**
    * Creates a new card
    *
    * @param name - name of the card to create.
    * @return
    *      unique pointer to the new card.
    */
std::unique_ptr<Card> createCard(const std::string& name);


/**
    * Creates a new player
    *
    * @param name - name of the player to create.
    * @return
    *      unique pointer to the new player.
    */
std::unique_ptr<Player> createPlayer(const std::string& name, const std::string& character);


/**
    * Checks if card's name is valid
    *
    * @param name - name to check.
    * @return
    *      true if valid and false otherwise.
    */
bool cardNameIsValid(const std::string& card);


/**
    * Checks if character's name is valid
    *
    * @param name - name to check.
    * @return
    *      true if valid and false otherwise.
    */
bool characterNameIsValid(const std::string& character);

/**
    * Checks if player's name is valid
    *
    * @param name - name to check.
    * @return
    *      true if valid and false otherwise.
    */
bool playerNameIsValid(const std::string& name);


/**
    * Reads cards from file into a given deck
    *
    * @param sourceFileName - name of the file from which to read.
    * @param cardDeck - card deck to read into.
    * @return
    *      void.
    */
void receiveCards(const std::string& sourceFileName, std::deque<std::unique_ptr<Card>>& cardDeck);

/**
    * Receives cards from the user into a given queue
    *
    * @param queue - queue to store players.
    * @return
    *      void.
    */
void receivePlayers(std::deque<std::unique_ptr<Player>>& queue);

/**
    * Receives number of players from the user
    *
    * @return
    *      number of players.
    */
int receiveTeamSize();

/**
    * Receives name of one player from the user
    *
    * @param playerName - reference to store player's name in.
    * @param playerCharacter - reference to store player's character in.
    * @return
    *      void.
    */
void receivePlayerName(std::string& playerName, std::string& playerCharacter);


/**------------------------------------------------------------------------------*/
#endif //HW4_MTMCHKIN_H
