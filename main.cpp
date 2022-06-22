#include <iostream>
#include "Mtmchkin.h"
#include "test.h"
using std::deque;
using std::unique_ptr;
using std::string;
using std::cin;
using std::cout;
using std::endl;

void run_game();

int main()
{

    int choice;
    std::string buffer;
    cout << "Enter 1 for tests, 2 for regular or 3 for anything else" << endl;
    std::getline(cin, buffer);
    choice = stoi(buffer);

    if (choice == 1)
    {
        tests();
        return 0;
    }
    if (choice == 2)
    {
        run_game();
        return 0;
    }



    return 0;

}

void run_game()
{
    try
    {
        Mtmchkin game("../deck.txt");
        while(!game.isGameOver())
        {
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
}
