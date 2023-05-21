#include "Player.h"

#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//default constructor ----------------------------------------------------------------
Player::Player()
{
    //set all default values:
    name = "";
    //stats
    //location.push_back(0);
    //location.push_back(0);
    dogeCoin = 200;
    internetLevel = 1;
    frustrationLevel = 0;
    compMaintLevel = 100;
    //inventory
    numCPU = 0;
    numGPU = 0;
    numVPN = 1;
    numInternetCard = 0;
    numKeyboardMouse = 0;
    numPower = 0;
    numCompCase = 0;
    numAntivirus = 0;
    numPremadeComp = 1;
    didWin = 1;
    didQuit = 0;
    wonAFight = 0;
    
}



//getters------------------------------------------------------

string Player::getName()
{
    return name;
}

//stats
/*
vector <int> Player::getLocation() 
{
    return location;
}
*/

double Player::getDogeCoin()
{
    return dogeCoin;
}

int Player::getInternetLevel() 
{
    return internetLevel;
}

int Player::getFrustrationLevel() 
{
    return frustrationLevel;
}

int Player::getCompMaintLevel()
{
    return compMaintLevel;
}

//inventory

int Player::getNumAntivirus() 
{
    return numAntivirus;
}

int Player::getNumVPN()
{
    return numVPN;
}

int Player::getNumCPU()
{
    return numCPU;
}

int Player::getNumGPU()
{
    return numGPU;
}

int Player::getNumPower()
{
    return numPower;
}

int Player::getNumCompCase()
{
    return numCompCase;
}

int Player::getNumInternetCard()
{
    return numInternetCard;
}

int Player::getNumKeyboardMouse()
{
    return numKeyboardMouse;
}

int Player::getNumPremadeComp()
{
    return numPremadeComp;
}

bool Player::getDidQuit()
{
    return didQuit;
}

bool Player::getHasVirus()
{
    return hasVirus;
}

bool Player::getDidWin()
{
    return didWin;
}

bool Player::getWonAFight()
{
    return wonAFight;
}
//setters-----------------------------------------

void Player::setDidQuit(bool q)
{
    didQuit = q;
}

void Player::setName(string n)
{
    name = n;
}

void Player::setWonAFight(bool f)
{
    wonAFight = f;
}
// set stats
/*
void Player::setLocation(int r, int c)
{
    location.pop_back();
    location.pop_back();
    location.push_back(r);
    location.push_back(c);
}
*/

void Player::setHasVirus(bool v)
{
    hasVirus = v;
}

void Player::setDogeCoin(double d)
{
    dogeCoin = d;
}

void Player::setInternetLevel(int i)
{
    internetLevel = i;
}

void Player::setFrustrationLevel(int f)
{
    frustrationLevel = f;
}

void Player::setCompMaintLevel(int c)
{
    compMaintLevel = c;
}

//inventory
void Player::setNumCPU(int c)
{
    numCPU = c;
}

void Player::setNumGPU(int g)
{
    numGPU = g;
}

void Player::setNumPower(int p)
{
    numPower = p;
}

void Player::setNumCompCase(int c)
{
    numCompCase = c;
}

void Player::setNumInternetCard(int i)
{
    numInternetCard = i;
}

void Player::setNumKeyboardMouse(int k)
{
    numKeyboardMouse = k;
}

void Player::setNumAntivirus(int a)
{
    numAntivirus = a;
}

void Player::setNumVPN(int v)
{
    numVPN = v;
}

void Player::setNumPremadeComp(int p)
{
    numPremadeComp = p;
}

void Player::setDidWin(bool w)
{
    didWin = w;
}

//other member functions

int Player::getRandomNumber(int min, int max)
{
    return (rand() % (max - min) + 1) + min;
}

bool Player::checkMisfortune()
{
    srand(time(0));
    int num;
    bool flag;
    int PROB = 30;

    num = (rand() % (100 - 1) + 1) ;

    if(num <= PROB)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }

    return flag;
}

bool Player::checkForVirus()
{
    srand(time(0));
    int num;
    bool flag;
    int PROB = 10;

    num = (rand() % (100 - 1) + 1) ;

    if(num <= PROB)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }

    return flag;
}

void Player::printStats()
{
    
    cout << "-----" << name <<  " Stats -----" << endl;
    cout << "DogeCoin: " << dogeCoin << endl;
    //cout << "Location: " << location[0] << "," << location[1] << endl;
    cout << "Frustration Level: " << frustrationLevel << endl;
    cout << "Internet Level: " << internetLevel << endl;
    cout << "Computer Maintenance Level: " << compMaintLevel << endl;

}


void Player::printInventory()
{
    cout << "-----" << name << " Inventory -----" << endl;
    cout << "CPU: " << numCPU << endl;
    cout << "GPU: " << numGPU << endl; 
    cout << "VPN: " << numVPN << endl;
    cout << "Power Supply: " << numPower << endl;
    cout << "Computer Case: " << numCompCase << endl;
    cout << "Internet Card: " << numInternetCard << endl;
    cout << "KeyBoard/Mouse: " << numKeyboardMouse << endl;
    cout << "Antivirus: " << numAntivirus << endl;
    cout << "Premade Comp: " << numPremadeComp << endl;
}


void Player::executeMisfortune()
{
    int randNum = getRandomNumber(1,9);
    switch(randNum)
    {
        case 1 : if(numCPU > 0)
                 {
                     cout << "You have lost a CPU :(" << endl;
                     numCPU -= 1;
                 }
                 else
                 {
                    executeMisfortune();
                 }   
        break;

        case 2 : if(numGPU > 0)
                 {
                     cout << "You have lost a GPU :(" << endl;
                     numGPU -= 1;
                 }
                 else
                 {
                    executeMisfortune();
                 }  
        break;

        case 3 : if(numVPN > 0)
                 {
                     cout << "You have lost a VPN :(" << endl;
                     numVPN -= 1;
                 }
                 else
                 {
                    executeMisfortune();
                 }  
        break;

        case 4 : if(numPower > 0)
                 {
                     cout << "You have lost a PowerSupply :(" << endl;
                     numPower -= 1;
                 }
                 else
                 {
                    executeMisfortune();
                 }  
        break;

        case 5 : if(numCompCase > 0)
                 {
                     cout << "You have lost a Computer Case :(" << endl;
                     numCompCase -= 1;
                 }
                 else
                 {
                    executeMisfortune();
                 }  
        break;

        case 6 : if(numKeyboardMouse > 0)
                 {
                     cout << "You have lost a Keyboard/Mouse :(" << endl;
                     numKeyboardMouse -= 1;
                 }
                 else
                 {
                    executeMisfortune();
                 }  
        break;

        case 7 : if(numAntivirus > 0)
                 {
                     cout << "You have lost an Antivirus :(" << endl;
                     numAntivirus -= 1;
                 }
                 else
                 {
                    executeMisfortune();
                 }  
        break;

        case 8 :if(numInternetCard > 0)
                 {
                     cout << "You have lost an Internet Card :(" << endl;
                     numInternetCard -= 1;
                 }
                 else
                 {
                    executeMisfortune();
                 }  
        break;

        default : cout << "The odds are in your favor! The misfortune Bunny is out of town!" << endl;
        break;
    }


}

void Player::executeFortune()
{
    int randNum = getRandomNumber(1,9);
    switch(randNum)
    {
        case 1 : if(numCPU == 0)
                 {
                     cout << "You have a new CPU :)" << endl;
                     numCPU += 1;
                 }
                 else
                 {
                    executeFortune();
                 }   
        break;

        case 2 : if(numGPU == 0)
                 {
                     cout << "You have a new GPU :)" << endl;
                     numGPU += 1;
                 }
                 else
                 {
                    executeFortune();
                 }  
        break;

        case 3 : if(numVPN == 0)
                 {
                     cout << "You have a new VPN :)" << endl;
                     numVPN += 1;
                 }
                 else
                 {
                    executeFortune();
                 }  
        break;

        case 4 : if(numPower == 0)
                 {
                     cout << "You have a new PowerSupply! :)" << endl;
                     numPower += 1;
                 }
                 else
                 {
                    executeFortune();
                 }  
        break;

        case 5 : if(numCompCase == 0)
                 {
                     cout << "You have a new Computer Case :)" << endl;
                     numCompCase += 1;
                 }
                 else
                 {
                    executeFortune();
                 }  
        break;

        case 6 : if(numKeyboardMouse == 0)
                 {
                     cout << "You have a new Keyboard/Mouse :)" << endl;
                     numKeyboardMouse += 1;
                 }
                 else
                 {
                    executeFortune();
                 }  
        break;

        case 7 : if(numAntivirus == 0)
                 {
                     cout << "You have lost a new Antivirus :)" << endl;
                     numAntivirus += 1;
                 }
                 else
                 {
                    executeFortune();
                 }  
        break;

        case 8 :if(numInternetCard == 0)
                 {
                     cout << "You have a new Internet Card :(" << endl;
                     numInternetCard += 1;
                 }
                 else
                 {
                    executeFortune();
                 }  
        break;

        default : cout << "Silly NPC was playing you for a fool! weird." << endl;
        break;
    }


}