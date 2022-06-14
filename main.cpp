#include <iostream>
#include "Mtmchkin.h"
using std::deque;
using std::unique_ptr;

int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    Mtmchkin game("../deck.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
        game.playRound();
    }
    game.printLeaderBoard();


    return 0;
}

/* works

queue<unique_ptr<Card>> deck;
readCards("../CardsFile.txt", deck);

queue<unique_ptr<Player>> players;
getPlayers(players);

int rounds = 0;
while (!players.empty())
{
rounds++;
printRoundStartMessage(rounds);

for (int i = 0; i < players.size(); i++)
{
printTurnStartMessage(players.front()->getName());
deck.front()->applyEncounter(*players.front());

deck.push(std::move(deck.front()));
deck.pop();

if (players.front()->isKnockedOut())
{
// add to losers
}
else if (players.front()->getLevel() == 10) // replace -> isAtMaxLevel()
{
// add to winners
}
else
{
players.push(std::move(players.front()));
}
players.pop();
}
}
printGameEndMessage();

*/
