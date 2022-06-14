//
// Created by 97250 on 6/13/2022.
//

#include "Mtmchkin.h"
using std::queue;
using std::stack;
using std::unique_ptr;

Mtmchkin::Mtmchkin(const std::string fileName)
{
    readCards(fileName, m_cardDeck);
    //getPlayers(m_stillInGame);
}

void Mtmchkin::playRound()
{

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

void readCards(const std::string& sourceFileName, queue<unique_ptr<Card>>& cardDeck)
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
        cardDeck.push(createCard(name));
    }
}

void getPlayers(queue<unique_ptr<Player>>& players)
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

        players.push(createPlayer(name, character));
    }
}
