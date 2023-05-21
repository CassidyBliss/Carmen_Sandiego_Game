#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<array>
#include<vector>
#include<iostream>

using namespace std;

class Player
{
    public:

    //default constructor
    Player();

    //parameterized constructor (may not need)

    //getters
    string getName();
    //stats
    vector <int> getLocation();
    double getDogeCoin();
    int getInternetLevel();
    int getFrustrationLevel();
    int getCompMaintLevel();
    bool getDidQuit();
    //inventory
    int getNumCPU();
    int getNumGPU();
    int getNumPower();
    int getNumCompCase();
    int getNumInternetCard();
    int getNumKeyboardMouse();
    int getNumAntivirus();
    int getNumVPN();
    int getNumPremadeComp();
    int getRandomNumber(int min, int max);
    bool getHasVirus();
    bool getDidWin();
    bool getWonAFight();

    //setters
    void setName(string n);
    //stats
    void setLocation(int r, int c);
    void setDogeCoin(double d);
    void setInternetLevel(int i);
    void setFrustrationLevel(int f);
    void setCompMaintLevel(int c);
    void setDidQuit(bool q);

    //inventory
    void setHasVirus(bool v);
    void setNumCPU(int c);
    void setNumGPU(int g);
    void setNumPower(int p);
    void setNumCompCase(int c);
    void setNumInternetCard(int i);
    void setNumKeyboardMouse(int k);
    void setNumAntivirus(int a);
    void setNumVPN(int v);
    void setNumPremadeComp(int p);
    void setDidWin(bool w);
    void setWonAFight(bool f);
    //other member functions
    bool checkMisfortune();
    bool checkForVirus();
    void printStats();
    void printInventory();
    void executeMisfortune();
    void executeFortune();
    //bool canFixComp();
    
    private:
    bool didWin;
    int const maxFrustration = 100;
    bool didQuit = 0;
    string name;
    bool hasVirus;
    //stats
    //vector <int> location;
    double dogeCoin;
    int internetLevel;
    int frustrationLevel;
    int compMaintLevel;
    //inventory
    int numCPU;
    int numGPU;
    int numPower;
    int numCompCase;
    int numInternetCard;
    int numKeyboardMouse;
    int numAntivirus;
    int numVPN;
    int numPremadeComp;
    bool misfortune;
    bool wonAFight;
    
};

#endif