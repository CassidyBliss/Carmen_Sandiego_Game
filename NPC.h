#ifndef NPC_H
#define NPC_H
#include <string>
#include <array>
#include "Player.h"

using namespace std;

class NPC
{
    public:
    //default constructor
    NPC();
    //parameterized constructor
    NPC(string n);

    //getters/setters
    string getNPCName();
    void setNPCName(string s);

    //other memberfunctions
    bool meetNPC();
    int getRandomNumber(int min, int max);
    string getRandomNPCName();
    int showPuzzle();
    bool isFriend();
    bool playNPC(int l, int a);
    bool playRockPaperScissors(Player p);

    private:
    string NPCname;
    string NPCnames[5] = {"Ruth", "Ben", "Khalilah", "Jaquez", "Becca"};
    string puzzles[5] = {"puzze1.txt", "puzzle2.txt", "puzzle3.txt", "puzzle4.txt", "puzzle5.txt"};
    int answer1 = 21;
    int answer2 = 13;
    int answer3 = 2;
    int answer4 = 1;
    int answer5 = 4;

};
#endif