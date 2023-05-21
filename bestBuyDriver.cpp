#include "BestBuy.h"
#include "Player.h"
#include <fstream>
#include <string>
#include <array>
#include <iostream>

using namespace std;

int main()
{
    Player p1 = Player();
    BestBuy currentStore = BestBuy();
    currentStore.printIntro();
    currentStore.shopBestBuy(p1);

    return 0;
}