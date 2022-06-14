#include <iostream>
#include "Mtmchkin.h"


int main()
{
    std::queue<std::unique_ptr<Player>> players;
    getPlayers(players);

    while (!players.empty())
    {
        std::cout << *players.front() << std::endl;
        players.pop();
    }



    return 0;
}
