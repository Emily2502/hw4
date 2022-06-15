//
// Created by 97250 on 6/13/2022.
//

#include "Mtmchkin.h"
using std::deque;
using std::unique_ptr;

static std::unique_ptr<Card> createCard(const std::string& name);

static void readCards(const std::string& sourceFileName, std::deque<std::unique_ptr<Card>>& cardDeck);

static std::unique_ptr<Player> createPlayer(const std::string& name, const std::string& character);

static void getPlayers(std::deque<std::unique_ptr<Player>>& queue);

static bool cardNameIsValid(const std::string& card);

static int receiveSize();

static void receivePlayerName(std::string& playerName, std::string& playerCharacter);

static bool characterNameIsValid(const std::string& character);

Mtmchkin::Mtmchkin(const std::string fileName)
{
    printStartGameMessage();
    readCards(fileName, m_deck);
    getPlayers(m_players);
    m_rounds = 0;
}

void Mtmchkin::playRound()
{
    m_rounds++;
    printRoundStartMessage(m_rounds);
    int size = m_players.size();

    for (int i = 0; i < size; i++)
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
    for (int i = 0; i < int(m_winners.size()); i++)
    {
        printPlayerLeaderBoard(ranking, *m_winners[i]);
        ranking++;
    }
    for (int i = 0; i < int(m_players.size()); i++)
    {
        printPlayerLeaderBoard(ranking, *m_players[i]);
        ranking++;
    }
    for (int i = 0; i < int(m_losers.size()); i++)
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
        throw DeckFileNotFound();
    }

    int line = 1;
    std::string card;
    while (std::getline(source, card))
    {
        if (!cardNameIsValid(card))
        {
            throw DeckFileFormatError(line);
        }
        line++;
        cardDeck.push_back(createCard(card));
    }
    if (cardDeck.size() < 5)
    {
        throw DeckFileInvalidSize();
    }
}

void getPlayers(deque<unique_ptr<Player>>& players)
{
    int size = receiveSize();

    std::string name;
    std::string character;
    for (int i = 0; i < size; i++)
    {
        receivePlayerName(name,character);
        players.push_back(createPlayer(name, character));
    }
}

bool cardNameIsValid(const std::string& card)
{
    return card == "Goblin" || card == "Vampire" || card == "Dragon"
     || card == "Merchant" || card == "Treasure" || card == "Pitfall"
     || card == "Barfight" || card == "Fairy";
}

int receiveSize()
{
    printEnterTeamSizeMessage();
    std::string buffer;
    std::getline(std::cin,buffer);

    while (buffer.size() != 1 || buffer[0] < '2' || buffer[0] > '6')
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::cin >> buffer;
    }
    return std::stoi(buffer);
}

void receivePlayerName(std::string& playerName, std::string& playerCharacter)
{
    printInsertPlayerMessage();
    std::string name;
    std::cin >> name;

    std::string character;
    std::cin >> character;

    std::string buffer;
    std::getline(std::cin, buffer);
    while (true)
    {
        if (!buffer.empty())
        {
            printInvalidInput();
        }
        else if (name.size() > 15)
        {
            printInvalidName();
        }
        else if (!characterNameIsValid(character))
        {
            printInvalidClass();
        }
        else
        {
            break;
        }

        std::cin >> name;
        std::cin >> character;
        std::getline(std::cin, buffer);
    }
    playerName = name;
    playerCharacter = character;
}

bool characterNameIsValid(const std::string& character)
{
    return character == "Fighter" || character == "Wizard" || character == "Rogue";
}









