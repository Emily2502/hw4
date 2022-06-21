#include "Player.h"
#include <iostream>
const int INITIAL_HP = 100;
const int INITIAL_LEVEL = 1;
const int INITIAL_COINS = 10;
const int INITIAL_FORCE = 5;
const int MINIMUM_FORCE = 0;
const int MINIMUM_HP = 0;
const int MAX_LEVEL = 10;

Player::Player(const std::string &name) :
    m_name(name),
    m_hp(INITIAL_HP),
    m_level(INITIAL_LEVEL),
    m_force(INITIAL_FORCE),
    m_coins(INITIAL_COINS) {}


void Player::levelUp()
{
    if (m_level < MAX_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}


int Player::getHP() const
{
    return int(m_hp);
}


std::string Player::getName() const
{
    return m_name;
}


int Player::getCoins() const
{
    return m_coins;
}


void Player::buff(const int forcePointsToAdd)
{
    if (forcePointsToAdd > 0)
    {
        m_force += forcePointsToAdd;
    }
}

void Player::heal(const int hpPointsToAdd)
{
    m_hp = m_hp + hpPointsToAdd;
}

void Player::damage(const int hpPointsToSubtract)
{
    m_hp = m_hp - hpPointsToSubtract;
}

void Player::weaken(int forcePointsToSubtract)
{
    m_force -= forcePointsToSubtract;

    if (m_force < MINIMUM_FORCE)
    {
        m_force = MINIMUM_FORCE;
    }
}


bool Player::isKnockedOut() const
{
    return int(m_hp) == MINIMUM_HP;
}

bool Player::pay(const int coinsToPay)
{
    if (coinsToPay > 0)
    {
        if (coinsToPay > m_coins)
        {
            return false;
        }
        m_coins -= coinsToPay;
    }
    return true;
}

void Player::addCoins(const int coinsToAdd)
{
    if (coinsToAdd > 0)
    {
        m_coins += coinsToAdd;
    }
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    printPlayerDetails(os, player.m_name, player.getType(), player.m_level,
                       player.m_force, int(player.m_hp), player.m_coins);
    return os;
}

