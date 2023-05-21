#include "Hacker.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <array>
#include <stdlib.h>
#include <time.h>

using namespace std;


//helper function
//random number generator
int Hacker::randomNumber(int min, int max)
{
    return (rand() % (max - min) + 1) + min;
}

//default contructor
Hacker::Hacker()
{
    hackerName = "";
    hackerLevel = 1;
}

//parameterized constructor
Hacker::Hacker(int l, string n)
{
    hackerLevel = l;
    hackerName = n;
}
//getters
string Hacker::getRandomHackerName(int l)
{
    int randNum = randomNumber(0,4);
    string name;
    switch(l)
    {
        case 1 : name = level1Hackers[randNum];
        break;

        case 2 : name = level2Hackers[randNum];
        break;

        case 3 : name = level3Hackers[randNum];
        break;

        case 4 : name = level4Hackers[randNum];
        break;

        case 5 : name = level5Hackers[randNum];
        break;

        default : cout << "Error getting random hacker Name!" << endl;
        break;
    }
    return name;
}

string Hacker::getHackerName()
{
    return hackerName;
}

int Hacker::getHackerLevel()
{
    return hackerLevel;
}

//setters

void Hacker::setHackerName(string n)
{
    hackerName = n;
}

void Hacker::setHackerLevel(int l)
{
    hackerLevel = l;
}


//other memberfunctions
bool Hacker::fightHacker(Player p)
{
    bool win;
    int r1 = randomNumber(2,6);
    int r2 = randomNumber(1,6);
    int v = p.getNumVPN();
    int c = hackerLevel;
    int i = p.getInternetLevel();
    double outcome;

    outcome = (r1*i)-(r2*c*(1.0/v));

    if(outcome > 0)
    {
        win = 1;
    }
    else
    {
        win = 0;
    }

    return win;
}