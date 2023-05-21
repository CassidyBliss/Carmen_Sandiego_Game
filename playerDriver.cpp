#include "Player.h"
#include <string>
#include <array>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    Player player1 = Player();
    cout << "Default name: " <<player1.getName() << endl;
    cout << "Premade computers: "<<player1.getNumPremadeComp() << endl;
    cout << "Misfortune: " << player1.checkMisfortune() << endl;
    cout << "Location" << endl;
    for (int i=0; i < 2; i++)
    {
        cout << player1.getLocation()[i] << " ";
    }
    cout << endl;

    player1.printStats();
    player1.printInventory();

    return 0;
}