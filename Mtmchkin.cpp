//
// Created by 97250 on 6/13/2022.
//

#include "Mtmchkin.h"
using std::deque;
using std::unique_ptr;

Mtmchkin::Mtmchkin(const std::string fileName)
{
    readCards(fileName, m_deck);
    getPlayers(m_players);
    m_rounds = 0;
}

void Mtmchkin::playRound()
{
    m_rounds++;
    printRoundStartMessage(m_rounds);

    for (int i = 0; i < m_players.size(); i++)
    {
        printTurnStartMessage(m_players.front()->getName());
        m_deck.front()->applyEncounter(*m_players.front());

        m_deck.push_back(std::move(m_deck.front()));
        m_deck.pop_front();

        if (m_players.front()->isKnockedOut())
        {
            m_losers.push_front(std::move(m_players.front()));
        }
        else if (m_players.front()->getLevel() == 10) // Todo: replace -> isAtMaxLevel()
        {
            m_winners.push_back(std::move(m_players.front()));
        }
        else
        {
            m_players.push_back(std::move(m_players.front()));
        }
        m_players.pop_front();
    }

    if (isGameOver())
    {
        printGameEndMessage();
    }
}

bool Mtmchkin::isGameOver() const
{
    return m_players.empty();
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds;
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking = 1;
    for (int i = 0; i < m_winners.size(); i++)
    {
        printPlayerLeaderBoard(ranking, *m_winners[i]);
        ranking++;
    }
    for (int i = 0; i < m_players.size(); i++)
    {
        printPlayerLeaderBoard(ranking, *m_players[i]);
        ranking++;
    }
    for (int i = 0; i < m_losers.size(); i++)
    {
        printPlayerLeaderBoard(ranking, *m_losers[i]);
        ranking++;
    }
}


unique_ptr<Card> createCard(const std::string& name)
{
    std::map<std::string, unique_ptr<Card> (*)()> cardConstructors;
    cardConstructors["Goblin"] = createCardInstance<Goblin>;
    cardConstructors["Vampire"] = createCardInstance<Vampire>;
    cardConstructors["Dragon"] = createCardInstance<Dragon>;
    cardConstructors["Merchant"] = createCardInstance<Merchant>;
    cardConstructors["Treasure"] = createCardInstance<Treasure>;
    cardConstructors["Pitfall"] = createCardInstance<Pitfall>;
    cardConstructors["Barfight"] = createCardInstance<Barfight>;
    cardConstructors["Fairy"] = createCardInstance<Fairy>;

    return cardConstructors[name]();
}

std::unique_ptr<Player> createPlayer(const std::string& name, const std::string& character)
{
    std::map<std::string, unique_ptr<Player> (*)(const std::string&)> playerConstructors;
    playerConstructors["Fighter"] = createPlayerInstance<Fighter>;
    playerConstructors["Rogue"] = createPlayerInstance<Rogue>;
    playerConstructors["Wizard"] = createPlayerInstance<Wizard>;

    return playerConstructors[character](name);
}

void readCards(const std::string& sourceFileName, deque<unique_ptr<Card>>& cardDeck)
{
    std::ifstream source(sourceFileName);
    if (!source)
    {
        //Exceptions
        return;
    }

    std::string name;
    while (std::getline(source, name))
    {
        //check name + Exceptions
        cardDeck.push_back(createCard(name));
    }
}

void getPlayers(deque<unique_ptr<Player>>& players)
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int size = 0;
    std::cin >> size;

    while (size > 6 || size < 2)
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::cin >> size;
    }

    for (int i = 0; i < size; i++)
    {
        printInsertPlayerMessage();
        std::string name;
        std::cin >> name;

        std::string character;
        std::cin >> character;
        //check name of character

        players.push_back(createPlayer(name, character));
    }
}
