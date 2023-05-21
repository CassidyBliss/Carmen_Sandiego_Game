#ifndef HACKER_H
#define HACKER_H
#include <array>
#include <string>
#include "Player.h"
using namespace std;

class Hacker
{
    public:
    //default constructor
    Hacker();

    //parameterized contsructor
    Hacker(int l, string n);

    //getters
    string getRandomHackerName(int l);
    int getHackerLevel();
    string getHackerName();
    //setters
    void setHackerName(string s);
    void setHackerLevel(int l);

    //other member functions
    bool fightHacker(Player P);
    
    int randomNumber(int min, int max);

    private:
    string hackerName;
    int hackerLevel;
    string level1Hackers[4]= {"hansolo1337", "gandalf5000", "tomato_cultivator20", "cheeto_dweller"};
    string level2Hackers[4]= {"thejoker33", "furiosa_11", "woodythesheriff", "lizzathealien" };
    string level3Hackers[4]= {"ironman123", "pizzaIsKnowledge", "bing_bong_2015", "num1_carmenfan77"};
    string level4Hackers[4]= {"free_almonds", "uzer_1000", "twinkle_star99", "team-3dward-5evr"};
    string level5Hackers[4]= {"crazyCatLady76", "numba_1programmer", "myNameisJeff", "treatYoSelf"};

};
#endif