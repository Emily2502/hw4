#include <iostream>
#include "Mtmchkin.h"
#include "test.h"


void run_game();

int main()
{

    int choice;
    std::string buffer;
    std::cout << "Enter 1 for tests" << std::endl;
    std::getline(std::cin, buffer);
    choice = stoi(buffer);


    if (choice == 1)
    {
        tests();
    }
    else
    {
        run_game();
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
