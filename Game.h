
#ifndef GAME_H
#define GAME_H
#include "Player.h"

using namespace std;


class Game
{
    public:
    //constructors
    Game();

    //getters/setters

    void setCarmenProgress(int p);
    int getCarmenProgress();

    void setServerRoom(int s);
    int getServerRoom();

    //other member functions
    Player startGame();
    //Player part1(Player p);
    Player serverRooms(Player p, string n);
    //Player part2(Player p);
    int endGame();
    int getRandomNum(int min, int max);
    void showMenu();
    bool clearedForNextLevel();
    
    

    
    private:
    int serverRoom;
    int carmenProgress;

    
};  

#endif