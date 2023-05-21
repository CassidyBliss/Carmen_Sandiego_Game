#include "NPC.h"
#include <string>
#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int NPC::getRandomNumber(int min, int max)
{
    srand(time(0));
    return (rand() % (max - min) + 1) + min;
}

//default constructor
NPC::NPC()
{
    NPCname =  "";
}
//parameterized constructor

NPC::NPC(string n)
{
    NPCname = n;
}

void NPC::setNPCName(string s)
{
    NPCname = s;
}

string NPC::getNPCName()
{
    return NPCname;
}

string NPC::getRandomNPCName()
{
    int randNum = getRandomNumber(0,4);
    return NPCnames[randNum];
}

int NPC::showPuzzle()
{
    ifstream inFile;
    string puzzle;
    string line;
    int randNum = getRandomNumber(0,4);
    puzzle = puzzles[randNum];
    inFile.open(puzzle);

    if(inFile.fail())
    {
        cout << "There was an error loading a document. Make sure they are all there -- puzzles1.txt - puzzles5.txt" << endl;
    }

    while(!inFile.eof())
    {
        getline(inFile, line);
        cout << line << endl;
    }
    return randNum;
}


bool NPC::isFriend()
{
    int num;
    bool flag;
    int PROB = 60;
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

bool NPC::playNPC(int l ,int a)
{
    int keyLocation = l;
    int correctAnswer;
    int userAnswer = a;
    bool correct =0;
    switch (keyLocation)
    {
        case 0 : correctAnswer = answer1;
                 if(userAnswer == correctAnswer)
                 {
                     cout << "That's correct!" << endl;
                     correct = 1;
                 }
                 else
                 {
                     cout << "Nope. Better luck next time" << endl;
                     correct = 0;
                 }
        break;

        case 1 : correctAnswer = answer2;
                 if(userAnswer == correctAnswer)
                 {
                     cout << "That's correct!" << endl;
                     correct = 1;
                 }
                 else
                 {
                     cout << "Nope. Better luck next time" << endl;
                     correct = 0;
                 }
                 
        break;

        case 2 : correctAnswer = answer3;
                 if(userAnswer == correctAnswer)
                 {
                     cout << "That's correct!" << endl;
                     correct = 1;
                 }
                 else
                 {
                     cout << "Nope. Better luck next time" << endl;
                     correct = 0;
                 }
        break;

        case 3 : correctAnswer = answer4;
                 if(userAnswer == correctAnswer)
                 {
                     cout << "That's correct!" << endl;
                     correct = 1;
                 }
                 else
                 {
                     cout << "Nope. Better luck next time" << endl;
                     correct = 0;
                 }
        break;

        case 4 : correctAnswer = answer5;
                 if(userAnswer == correctAnswer)
                 {
                     cout << "That's correct!" << endl;
                     correct = 1;
                 }
                 else
                 {
                     cout << "Nope. Better luck next time" << endl;
                     correct = 0;
                 }
        break;

        default: cout << "Error found in playing NPC" << endl;
        break;
    }
    return correct;
}

bool NPC::meetNPC()
{
    
    //bool indicates good or bad interaction
    int userAnswer;
    int userChoice;
    bool friendly;
    bool winPuzzle;
    int key;
    NPC npc1 = NPC();
    npc1.setNPCName(npc1.getRandomNPCName());
    cout << endl;
    cout << npc1.getNPCName() << " would like you to solve a puzzle" << endl;
    
    cout << "You can choose to: "<< endl;
    cout << "1. solve a puzzle" << endl; 
    cout << "2. Refuse and you can see if they are as friendy as they appear..." << endl;
    cout << "What will it be?" << endl;
    cin >> userChoice;
    switch(userChoice)
    {
        case 1 : cout << "Great, now enter your answer to the puzzle when you're ready:" << endl;
                 key = npc1.showPuzzle();
                 cin >> userAnswer;
                 winPuzzle = npc1.playNPC(key, userAnswer);
                 if(winPuzzle)
                 {
                     friendly = 1;
                 }
                 else
                 {
                     friendly = 0;
                 }
        break;

        case 2 : friendly = npc1.isFriend();
                 if(friendly)
                 {
                     cout << "Looks like " << npc1.getNPCName() << " is your friend!" << endl;
                 }
                 else
                 {
                     cout << "Uh Oh.." << npc1.getNPCName() << "isn't as friendly as they look." << endl;
                 }
        break;
    }
    return friendly;
}

/*
bool NPC::playRockPaperScissors(Player p)
{

}
*/