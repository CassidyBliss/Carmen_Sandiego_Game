#ifndef BESTBUY_H
#define BESTBUY_H

#include "Player.h"
#include <string>
#include <array>
#include <fstream>
#include <iostream>


using namespace std;

class BestBuy
{
    public:
    //default constructor
    BestBuy();
    BestBuy(int s);

    //OTHER MEMBER FUNCTIONS
    void printSelection();
    Player shopBestBuy(Player p);
    void purchaseItem(Player p, string i, double d);
    void printIntro();

    private:
    int storeNum;
    string productNames[13] = {"CPU","GPU","PowerSupply","Computer Case","InternetCard", "Keyboard/Mouse", "Premade Computer", "Antivirus", "VPN", "InternetLevel 2", "InternetLevel 3", "InternetLevel 4", "IntenetLevel 5"};
    double productPrices1[13] = {10,20,5,15,5,10,100,10,20,10,25,40,50};
    double productPrices2[13]={10*0.1,20*0.1,5*0.1,15*0.1,5*0.1,10*0.1,100*0.1,10*0.1,20*0.1,10*0.1,25*0.1,40*0.1,50*0.1};
    double productPrices3[13]={10*0.2,20*0.2,5*0.2,15*0.2,5*0.2,10*0.2,100*0.2,10*0.2,20*0.2,10*0.2,25*0.2,40*0.2,50*0.2};
    double productPrices4[13]={10*0.25,20*0.25,5*0.25,15*0.25,5*0.25,10*0.25,100*0.25,10*0.25,20*0.25,10*0.25,25*0.25,40*0.25,50*0.25};
    double productPrices5[13]={10*0.3,20*0.3,5*0.3,15*0.3,5*0.3,10*0.3,100*0.3,10*0.3,20*0.3,10*0.3,25*0.3,40*0.3,50*0.3};


};
#endif