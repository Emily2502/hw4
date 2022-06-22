//
// Created by 97250 on 6/13/2022.
//

#include "Mtmchkin.h"
const int MAX_LEVEL = 10;
using std::deque;
using std::unique_ptr;


Mtmchkin::Mtmchkin(const std::string fileName)
{
    printStartGameMessage();
    receiveCards(fileName, m_deck);
    receivePlayers(m_players);
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
        else if (m_players.front()->getLevel() == MAX_LEVEL)
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
        printPlayerLeaderBoard(ranking++, *m_winners[i]);
    }
    for (int i = 0; i < int(m_players.size()); i++)
    {
        printPlayerLeaderBoard(ranking++, *m_players[i]);
    }
    for (int i = 0; i < int(m_losers.size()); i++)
    {
        printPlayerLeaderBoard(ranking++, *m_losers[i]);
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

unique_ptr<BattleCard> createBattleCard(const std::string& name)
{
    std::map<std::string, unique_ptr<BattleCard> (*)()> cardConstructors;
    cardConstructors["Goblin"] = createBattleCardInstance<Goblin>;
    cardConstructors["Vampire"] = createBattleCardInstance<Vampire>;
    cardConstructors["Dragon"] = createBattleCardInstance<Dragon>;

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


void receiveCards(const std::string& sourceFileName, deque<unique_ptr<Card>>& cardDeck)
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
        if (card == "Gang")
        {
            deque<std::string> gang;
            receiveGang(source, gang, line);
            cardDeck.push_back(unique_ptr<Card>(new Gang(gang)));
        }
        else
        {
            cardDeck.push_back(createCard(card));
        }
        line++;
    }
    if (cardDeck.size() < 5)
    {
        throw DeckFileInvalidSize();
    }
}

void receivePlayers(deque<unique_ptr<Player>>& queue)
{
    int size = receiveTeamSize();

    std::string name;
    std::string character;
    for (int i = 0; i < size; i++)
    {
        receivePlayerName(name,character);
        queue.push_back(createPlayer(name, character));
    }
}


int receiveTeamSize()
{
    printEnterTeamSizeMessage();
    std::string buffer;
    std::getline(std::cin,buffer);

    while (buffer.size() != 1 || buffer[0] < '2' || buffer[0] > '6')
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::getline(std::cin,buffer);
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
        else if (!playerNameIsValid(name))
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

bool playerNameIsValid(const std::string& name)
{
    if (name.size() > 15)
    {
        return false;
    }
    for (char letter : name)
    {
        if ((letter < 'a' || letter > 'z') && (letter < 'A' || letter > 'Z'))
        {
            return false;
        }
    }
    return true;
}

bool cardNameIsValid(const std::string& card)
{
    return card == "Goblin" || card == "Vampire" || card == "Dragon"
           || card == "Merchant" || card == "Treasure" || card == "Pitfall"
           || card == "Barfight" || card == "Fairy" || card == "Gang";
}

bool characterNameIsValid(const std::string& character)
{
    return character == "Fighter" || character == "Wizard" || character == "Rogue";
}

bool monsterNameIsValid(const std::string& card)
{
    return card == "Goblin" || card == "Vampire" || card == "Dragon"|| card == "EndGang";
}

void receiveGang(std::istream& source, std::deque<std::string>& gang, int& line)
{
    std::string card;
    while (true)
    {
        if (!std::getline(source, card) || !monsterNameIsValid(card))
        {
            throw DeckFileFormatError(line);
        }
        line++;
        if (card == "EndGang")
        {
            break;
        }
        gang.push_back(card);
    }
}

