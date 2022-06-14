//
// Created by 97250 on 6/12/2022.
//

#ifndef HW4_PLAYER_H
#define HW4_PLAYER_H

#include "HealthPoints.h"
#include <string>

class Player {

public:

    /**
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @return
     *      A new instance of Player.
    */
    explicit Player(const std::string &name);


    /**
     * Here we are explicitly telling the compiler to use the default d'tor,
     * copy c'tor and assignment operator (the big 3)
    */
    Player(const Player&) = default;
    Player& operator=(const Player&) = default;
    virtual ~Player() = default;


    /**
     * Prints information of a Player as requested:
     *
     * @return
     *      reference to std::ostream
    */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);


    /**
     * Increases the level of a player by one
     * if player's level is at maximum value already nothing will be done
     *
     * @return
     *      void
    */
    void levelUp();


    /**
     * Gets the level of a player
     *
     * @return
     *      level of said player
    */
    int getLevel() const;


    /**
     * Gets HP of a player
     *
     * @return
     *      HP of said player
    */
    int getHP() const;

    /**
     * Gets name of a player
     *
     * @return
     *      name of said player
    */
    std::string getName() const;

    /**
     * Gets Coins of a player
     *
     * @return
     *      Coins of said player
    */
    int getCoins() const;


    /**
     * Increases the force of a player
     *
     * @param forcePointsToAdd - Number of points to increase player's force by.
     * @return
     *      void
    */
    void buff(int forcePointsToAdd);


    /**
     * Increases HP of a player
     *
     * @param hpPointsToAdd - Number of points to increase player's HP by.
     * @return
     *      void
    */
    virtual void heal(int hpPointsToAdd);


    /**
     * Decreases HP of a player
     *
     * @param hpPointsToSubtract - Number of points to decrease player's HP by.
     * @return
     *      void
    */
    void damage(int hpPointsToSubtract);


    /**
     * Decreases force of a player
     *
     * @param forcePointsToSubtract - Number of points to decrease player's force by.
     * @return
     *      void
    */
    void weaken(int forcePointsToSubtract);

    /**
     * Checks if HP of a player is zero
     *
     * @return
     *      true - if HP of said player is zero
     *      false - otherwise
    */
    bool isKnockedOut() const;


    /**
     * Makes a player pay
     * if said player has enough coins then this function decreases the number of coins
     * they have.
     *
     * @param coinsToPay - Number of points to a player has to pay.
     * @return
     *      true - if said player has enough coins
     *      false - otherwise
    */
    bool pay(int coinsToPay);


    /**
     * Increases number of coins of a player
     *
     * @param coinsToAdd - Number of points to increase player's coins by.
     * @return
     *      void
    */
    virtual void addCoins(int coinsToAdd);


    /**
     * Gets attack strength of a player
     *
     * @return
     *      attack strength of said player
    */
    virtual int getAttackStrength() const;

    /**
     * Gets type of a player
     *
     * @return
     *      name of said type
    */
    virtual std::string getType() const = 0;


private:

    std::string m_name;  /** English letters. no spaces */
    HealthPoints m_hp;  /** [0,maxHp] */
    int m_level;  /** [1,10] */
    int m_force;  /** natural number */
    int m_coins;  /** non-negative integer */
};

/**
 * Prints the details of the player:
 * Tip : Needed for the leaderBoard method (adjusted to print after the ranking section).

 * @param os - The ostream.
 * @param name - The name of the player.
 * @param job - The job class of the player.
 * @param level - The player's level.
 * @param force - The player's force.
 * @param hp - The player's HP points.
 * @param coins - The player's amount of coins.
 * @return
 *      void
 */
void printPlayerDetails(std::ostream &os, const std::string &name,
                        const std::string &job, int level, int force, int HP, int coins);


#endif //HW4_PLAYER_H
