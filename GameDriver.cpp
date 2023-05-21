#include "Map.h"
#include "Hacker.h"
#include "ServerRoom.h"
#include "Game.h"
#include "Player.h"
#include "NPC.h"
#include "BestBuy.h"

#include <string>
#include <array>
#include <iostream>
#include <fstream>

using namespace std;

//helper function
//random number generator
int randomNumber(int min, int max)
{
    srand(time(0));
    return (rand() % (max - min) + 1) + min;
}

int main()
{
    ofstream outFile;
    //beginning of game
    Game currentGame = Game();

    //catchh player after part 1 of game
    Player playerLevel1 = currentGame.startGame();

    //catch player after part 1 of game as player level 2
    Player playerLevel2 = currentGame.serverRooms(playerLevel1, "Turid Room");
    
    //catch player after part 2 of game as player level 3
    Player playerLevel3 = currentGame.serverRooms(playerLevel2, "Orchid Room");
   
    
    //catch player after part 3 of game as player level 4
    Player playerLevel4 = currentGame.serverRooms(playerLevel3, "Grease Room");



    //catch player after part 4 of game as player level 5
    Player playerLevel5 = currentGame.serverRooms(playerLevel4, "Ellis Room");



    //catch player after part 5 of game as a winner
    Player playerWinner = currentGame.serverRooms(playerLevel5, "Donkey Kong");


    if(playerWinner.getDidWin())
    {
        cout << "YOU HAVE MADE IT THROUGH ALL FIVE SERVER ROOMS AND COME OUT A CHAMPION" << endl;
        cout << "Congradulations on winning the game! " << playerWinner.getName() << endl;
    }

    

    



    return 0;
}