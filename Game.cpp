#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "BestBuy.h"
#include "Hacker.h"
#include "NPC.h"

#include <string>
#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

Game::Game()
{
    carmenProgress = 0;
    serverRoom = 1;
}


void Game::setCarmenProgress(int p)
{
    carmenProgress = p;
}

int Game::getCarmenProgress()
{
    return carmenProgress;
}

void Game::setServerRoom(int s)
{
    serverRoom = s;
}

int Game::getServerRoom()
{
    return serverRoom;
}

int Game::getRandomNum(int min, int max)
{
    return (rand() % (max - min) + 1) + min;
}

void Game::showMenu()
{
    cout << "You can choose the following options: " << endl;
    cout << "1. Fight a hacker -- if you win get to the next room" << endl;
    cout << "2. Wander around the room, and you may interact with an NPC who could help you out" << endl;
    cout << "3. Quit the game" << endl;
    cout << endl;
    cout << "Note that wandering can cause a misfortune --- or a fortune... the choice is yours" << endl;
}

int Game::endGame()
{
    return 0;
}

Player Game::startGame()
{
    //variables/objects
    string playerName = "";

    //generate a player object:
    Player player1 = Player();
    Map currentMap = Map();
    BestBuy currentStore = BestBuy();

    //get name from user:
    cout << "Enter your name: " << endl;
    cin >> playerName;

    //set name for player object
    player1.setName(playerName);

    //display current map and welcome player:
    cout << endl;
    cout << "Welcome " << player1.getName()  << " !" << endl;
    cout << "----- WHERE IN THE CODE IS CARMEN SANDIEGO -----" << endl;
    cout << endl;
    currentMap.spawnNPC(getRandomNum(1,4), getRandomNum(1,8));
    currentMap.displayMap();

    //print default stats and inventory
    cout << endl;
    player1.printStats();
    cout << endl;
    player1.printInventory();
    cout << endl;

    //shop at first best buy
    cout << "Your first stop is BEST BUY!" << endl;
    currentStore.printIntro();
    Player player1EndPart1 = currentStore.shopBestBuy(player1);

    cout << "Great! Here are your current stats and updated inventory:" << endl;
    player1EndPart1.printStats();
    player1EndPart1.printInventory();
    return player1EndPart1;
}   

Player Game::part1(Player p)
{
    bool questCompleted = 0;
    int userChoice = 0;
    char userMove;
    bool npcSuccess;
    bool misfortunate;
    bool fightOutcome;
    Hacker hacker1 = Hacker();
    Hacker hacker2 = Hacker();
    Hacker hacker3 = Hacker();
    NPC npc1 = NPC();
    NPC npc2 = NPC();
    NPC npc3 = NPC();
    cout << endl;
    cout << "Welcome to the Turing room " << p.getName() << endl;
    cout << "The NPC'S can be seen on the map and may be friendly or have prizes you can win!" << endl;
    cout << "There are hackers hidden in the map so beware!" << endl;
    cout << "you must battle a hacker or engage with an NPC before proceeding to the next room" << endl;
    cout << endl;
    Map level1 = Map();
    level1.spawnHacker(getRandomNum(0,4), getRandomNum(0,8));
    level1.spawnHacker(getRandomNum(0,4), getRandomNum(0,8));
    level1.spawnHacker(getRandomNum(0,4), getRandomNum(0,8));
    level1.spawnNPC(getRandomNum(0,4), getRandomNum(0,8));
    level1.spawnNPC(getRandomNum(0,4), getRandomNum(0,8));
    level1.spawnNPC(getRandomNum(0,4), getRandomNum(0,8));
    level1.displayMap();
    cout << endl;
    cout << "CarmenProgress: " << carmenProgress <<endl;

    //while carmen has not won, or lost, or the quest has not yet been completed:
    while (userChoice != 3)
    {
        //show menu
        showMenu();
        //user makes choice
        cin >> userChoice;
        //act on choice depending which one
        switch(userChoice)
        {
            case 1: cout << "Fight a Hacker" << endl;
                    //generate Hacker
                    hacker1.setHackerName(hacker1.getRandomHackerName(1));
                    cout << endl << "Meet your contender...." << hacker1.getHackerName() << endl << endl;
                    //cout << "Meet your contender...." << hacker1.getHackerName() << endl;
                    fightOutcome = hacker1.fightHacker(p);
                    if(fightOutcome == 1)
                    {
                        cout << "You won your battle!" << endl <<endl;
                        p.setDogeCoin(p.getDogeCoin()+50);
                        cout << "You get 50 dogecoins! : )" << endl;
                        cout << "But you have lost a computer part :(" << endl << endl;
                        p.executeMisfortune();
                        p.printStats();
                        p.printInventory();
                    }
                    else if (fightOutcome == 0)
                    {
                        cout << "You lost this one!" << endl <<endl;
                        cout << "Your computer maintenance level is down by 20 :(" << endl;
                        p.setCompMaintLevel(p.getCompMaintLevel()-20);
                        cout << "But you have lost a computer part :(" << endl << endl;
                        p.executeMisfortune();
                        cout << "You have a 10% chance that you're computer has been infected with a virus" << endl;
                        p.setHasVirus(p.checkForVirus());
                        if(p.getHasVirus())
                        {
                            cout << "Indeed, you have been infected" << endl;
                            if(p.getNumAntivirus() > 0)
                            {
                                cout << "Fixing this now with one of your Antivirus USB's !! :)" << endl;
                                p.setNumAntivirus(p.getNumAntivirus() - 1);
                                p.setHasVirus(0);
                            }
                        }
                        else
                        {
                            cout << "You have no Antivirus USB to fix this. You will have to continue...But it may be a little more dangerous :(" << endl;
                            cout << "Make sure to get an Antivirus as soon as you can at the nearest Best Buy! $$$" << endl;
                        }
                        //check virus function integrate & bool hasVirus / fix computer members for player object

                        //display new stats/Inventory
                        p.printStats();
                        p.printInventory();
                    }

                    //when a computer is infected : 1 virus = maintenance level drops by 10 every action
                    //(add bool isInfected to player class)
            break;

            case 2: cout << "Okay then..." << endl << endl;
                    level1.displayMoves();
                    cout << endl;
                    cin >> userMove;
                    level1.executeMove(userMove);
                    level1.displayMap();
                    //every move comes with the possibility of misfortune
                    p.setDogeCoin(p.getDogeCoin()+15);
                    misfortunate = p.checkMisfortune();
                    if (misfortunate == true)
                    {
                        cout << "Your move has caused some misfortune--better luck next time!" << endl << endl;
                        p.executeMisfortune();
                        p.printStats();
                        p.printInventory();
                    }
                    if(level1.isNPCLocation())
                    {
                        cout << "You have met an NPC!" << endl <<endl;
                        npcSuccess = npc1.meetNPC();
                        if(npcSuccess)
                        {
                            cout << "A gift from your new friend.." << endl;
                            p.executeFortune();
                            
                        }
                    }

                    //check if hacker is in this location
                    if(level1.isHackerLocation())
                    {
                        cout << "You ran into a hacker! Time to battle!" << endl << endl;
                        //generate Hacker
                        hacker1.setHackerName(hacker1.getRandomHackerName(1));
                        cout << "Meet your contender...." << hacker1.getHackerName() << endl <<endl;
                        fightOutcome = hacker1.fightHacker(p);
                        if(fightOutcome == 1)
                        {
                            cout << "You won your battle!" << endl << endl;
                            p.setDogeCoin(p.getDogeCoin()+50);
                            cout << "You get 50 dogecoins! : )" << endl;
                            cout << "But you have lost a computer part :(" << endl << endl;
                            p.executeMisfortune();
                            p.printStats();
                            p.printInventory();
                        }
                        else if (fightOutcome == 0)
                        {
                            cout << "You lost this one!" << endl << endl;
                            cout << "Your computer maintenance level is down by 20 :(" << endl;
                            p.setCompMaintLevel(p.getCompMaintLevel()-20);
                            cout << "A computer part has broken and needs to be repaired :(" << endl << endl;
                            p.executeMisfortune();

                            //check virus function integrate & bool hasVirus / fix computer members for player object

                            //display new stats/Inventory
                            p.printStats();
                            p.printInventory();
                        }
                    }
                    

            break;

            case 3: cout << "Already??...your choice.. " << endl;
                    p.setDidQuit(1);
            break;

            default : cout << "Invalid Option---try again..." << endl;
            break;
        }
    }

    return p;
}

