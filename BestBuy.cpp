#include "BestBuy.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <array>
#include <fstream>

using namespace std;

//default constructor
BestBuy::BestBuy()
{
    storeNum = 1;
}

//parameterized constructor
BestBuy::BestBuy(int s)
{
    storeNum = s;
}

void BestBuy::printSelection()
{
    int store = storeNum;
    switch(store)
    {
        case 1 :
                cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
                for (int i = 0; i < 13; i++)
                {
                    cout << (i+1) << ". " << productNames[i] << " : " << productPrices1[i] << endl;
                }
        break;

        case 2 :
                cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
                for (int i = 0; i < 13; i++)
                {
                    cout << (i+1) << ". " << productNames[i] << " : " << productPrices2[i] << endl;
                }
        break;

        case 3:
                cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
                for (int i = 0; i < 13; i++)
                {
                    cout << (i+1) << ". " << productNames[i] << " : " << productPrices3[i] << endl;
                }
        break;

        case 4 : 
                cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
                for (int i = 0; i < 13; i++)
                {
                    cout << (i+1) << ". " << productNames[i] << " : " << productPrices4[i] << endl;
                }
        break;

        case 5 : 
                cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
                for (int i = 0; i < 13; i++)
                {
                    cout << (i+1) << ". " << productNames[i] << " : " << productPrices5[i] << endl;
                }
        break;

    }
}

void BestBuy::printIntro()
{
    ifstream in_file;
    string line;
    in_file.open("bestBuyInfo.txt");
    while(!in_file.eof())
    {
        getline(in_file, line);
        cout << line << endl;
    }
}

void BestBuy::purchaseItem(Player p, string i, double d)
{
    double amountAvailable = p.getDogeCoin();
    string item = i;
    double price = d;
    if ((amountAvailable - price) < 0)
    {
        cout << "Not enough dogecoin to complete this purchase :( please select another item or -1 to quit" << endl;
    }
    else if (amountAvailable - price >= 0)
    {
        p.setDogeCoin(amountAvailable-price);
        cout << "Purchase completed" << endl;

        if(item == "GPU")
        {
            p.setNumGPU(p.getNumGPU() + 1);
        }
        else if(item == "CPU")
        {
            p.setNumCPU(p.getNumCPU() + 1);
        }
        else if(item == "PowerSupply")
        {
            p.setNumPower(p.getNumPower() + 1);
        }
        else if(item == "Computer Case")
        {
            p.setNumCompCase(p.getNumCompCase() + 1);
        }
        else if(item == "InternetCard")
        {
            p.setNumInternetCard(p.getNumInternetCard() + 1);
        }
        else if(item == "Premade Computer")
        {
            p.setNumPremadeComp(p.getNumPremadeComp() + 1);
        }   
        else if(item == "Antivirus")
        {
            p.setNumAntivirus(p.getNumAntivirus() + 1);
        }
        else if(item == "VPN")
        {
            p.setNumVPN(p.getNumVPN() + 1);
        }
        else if(item == "InternetLevel 2")
        {
            p.setInternetLevel(2);
        }
        else if(item == "InternetLevel 3")
        {
            p.setInternetLevel(3);
        }
        else if(item == "InternetLevel 4")
        {
            p.setInternetLevel(4);
        }
        else if(item == "InternetLevel 5")
        {
            p.setInternetLevel(5);
        }
    }

    
    
}


//other member functions
Player BestBuy::shopBestBuy(Player p)
{
    int userChoice;
    int store = storeNum;

    if(storeNum == 1)
    {
        while(userChoice != -1)
        {
            //display options
            int amountAvailable = p.getDogeCoin();
            cout << endl;
            cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
            cout << "You currently have " << amountAvailable << " dogecoin" << endl << endl;;
            printSelection();
            cin >> userChoice;
            
            if(userChoice > 0 && userChoice < 14)
            {
                double price = productPrices1[userChoice-1];
                string item = productNames[userChoice-1];
                if ((amountAvailable - price) < 0)
                {
                    cout << "Not enough dogecoin to complete this purchase :( please select another item or -1 to quit" << endl;
                }
                else if (amountAvailable - price >= 0)
                {
                    p.setDogeCoin(amountAvailable-price);
                    cout << "Purchase completed" << endl;

                    if(item == "GPU")
                    {
                        p.setNumGPU(p.getNumGPU() + 1);
                    }
                    else if(item == "CPU")
                    {
                        p.setNumCPU(p.getNumCPU() + 1);
                    }
                    else if(item == "PowerSupply")
                    {
                        p.setNumPower(p.getNumPower() + 1);
                    }
                    else if(item == "Computer Case")
                    {
                        p.setNumCompCase(p.getNumCompCase() + 1);
                    }
                    else if(item == "InternetCard")
                    {
                        p.setNumInternetCard(p.getNumInternetCard() + 1);
                    }
                    else if(item == "Premade Computer")
                    {
                        p.setNumPremadeComp(p.getNumPremadeComp() + 1);
                    }   
                    else if(item == "Antivirus")
                    {
                        p.setNumAntivirus(p.getNumAntivirus() + 1);
                    }
                    else if(item == "VPN")
                    {
                        p.setNumVPN(p.getNumVPN() + 1);
                    }
                    else if(item == "InternetLevel 2")
                    {
                        p.setInternetLevel(2);
                    }
                    else if(item == "InternetLevel 3")
                    {
                        p.setInternetLevel(3);
                    }
                    else if(item == "InternetLevel 4")
                    {
                        p.setInternetLevel(4);
                    }
                    else if(item == "InternetLevel 5")
                    {
                        p.setInternetLevel(5);
                    }
                }
            }
                    
        }
    }
    else if(storeNum == 2)
    {
        while(userChoice != -1)
        {
            //display options
            int amountAvailable = p.getDogeCoin();
            cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
            cout << "You currently have " << amountAvailable << " dogecoin" << endl;
            printSelection();
            cin >> userChoice;

            if(userChoice > 0 && userChoice < 14)
            {
                double price = productPrices2[userChoice-1];
                string item = productNames[userChoice-1];
                if ((amountAvailable - price) < 0)
                {
                    cout << "Not enough dogecoin to complete this purchase :( please select another item or -1 to quit" << endl;
                }
                else if (amountAvailable - price >= 0)
                {
                    p.setDogeCoin(amountAvailable-price);
                    cout << "Purchase completed" << endl;

                    if(item == "GPU")
                    {
                        p.setNumGPU(p.getNumGPU() + 1);
                    }
                    else if(item == "CPU")
                    {
                        p.setNumCPU(p.getNumCPU() + 1);
                    }
                    else if(item == "PowerSupply")
                    {
                        p.setNumPower(p.getNumPower() + 1);
                    }
                    else if(item == "Computer Case")
                    {
                        p.setNumCompCase(p.getNumCompCase() + 1);
                    }
                    else if(item == "InternetCard")
                    {
                        p.setNumInternetCard(p.getNumInternetCard() + 1);
                    }
                    else if(item == "Premade Computer")
                    {
                        p.setNumPremadeComp(p.getNumPremadeComp() + 1);
                    }   
                    else if(item == "Antivirus")
                    {
                        p.setNumAntivirus(p.getNumAntivirus() + 1);
                    }
                    else if(item == "VPN")
                    {
                        p.setNumVPN(p.getNumVPN() + 1);
                    }
                    else if(item == "InternetLevel 2")
                    {
                        p.setInternetLevel(2);
                    }
                    else if(item == "InternetLevel 3")
                    {
                        p.setInternetLevel(3);
                    }
                    else if(item == "InternetLevel 4")
                    {
                        p.setInternetLevel(4);
                    }
                    else if(item == "InternetLevel 5")
                    {
                        p.setInternetLevel(5);
                    }
                }
            }
            
        }
    }
    else if(storeNum == 3)
    {
        while(userChoice != -1)
        {
            //display options
            int amountAvailable = p.getDogeCoin();
            cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
            cout << "You currently have " << amountAvailable << " dogecoin" << endl;
            printSelection();
            cin >> userChoice;

    
            if(userChoice > 0 && userChoice < 14)
            {
                double price = productPrices3[userChoice-1];
                string item = productNames[userChoice-1];
                if ((amountAvailable - price) < 0)
                {
                    cout << "Not enough dogecoin to complete this purchase :( please select another item or -1 to quit" << endl;
                }
                else if (amountAvailable - price >= 0)
                {
                    p.setDogeCoin(amountAvailable-price);
                    cout << "Purchase completed" << endl;

                    if(item == "GPU")
                    {
                        p.setNumGPU(p.getNumGPU() + 1);
                    }
                    else if(item == "CPU")
                    {
                        p.setNumCPU(p.getNumCPU() + 1);
                    }
                    else if(item == "PowerSupply")
                    {
                        p.setNumPower(p.getNumPower() + 1);
                    }
                    else if(item == "Computer Case")
                    {
                        p.setNumCompCase(p.getNumCompCase() + 1);
                    }
                    else if(item == "InternetCard")
                    {
                        p.setNumInternetCard(p.getNumInternetCard() + 1);
                    }
                    else if(item == "Premade Computer")
                    {
                        p.setNumPremadeComp(p.getNumPremadeComp() + 1);
                    }   
                    else if(item == "Antivirus")
                    {
                        p.setNumAntivirus(p.getNumAntivirus() + 1);
                    }
                    else if(item == "VPN")
                    {
                        p.setNumVPN(p.getNumVPN() + 1);
                    }
                    else if(item == "InternetLevel 2")
                    {
                        p.setInternetLevel(2);
                    }
                    else if(item == "InternetLevel 3")
                    {
                        p.setInternetLevel(3);
                    }
                    else if(item == "InternetLevel 4")
                    {
                        p.setInternetLevel(4);
                    }
                    else if(item == "InternetLevel 5")
                    {
                        p.setInternetLevel(5);
                    }
                }
            }
        }
    }
    else if(storeNum == 4)
    {
        while(userChoice != -1)
        {
            //display options
            int amountAvailable = p.getDogeCoin();
            cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
            cout << "You currently have " << amountAvailable << " dogecoin" << endl;
            printSelection();
            cin >> userChoice;
            

            if(userChoice > 0 && userChoice < 14)
            {
                double price = productPrices4[userChoice-1];
                string item = productNames[userChoice-1];
                if ((amountAvailable - price) < 0)
                {
                    cout << "Not enough dogecoin to complete this purchase :( please select another item or -1 to quit" << endl;
                }
                else if (amountAvailable - price >= 0)
                {
                    p.setDogeCoin(amountAvailable-price);
                    cout << "Purchase completed" << endl;

                    if(item == "GPU")
                    {
                        p.setNumGPU(p.getNumGPU() + 1);
                    }
                    else if(item == "CPU")
                    {
                        p.setNumCPU(p.getNumCPU() + 1);
                    }
                    else if(item == "PowerSupply")
                    {
                        p.setNumPower(p.getNumPower() + 1);
                    }
                    else if(item == "Computer Case")
                    {
                        p.setNumCompCase(p.getNumCompCase() + 1);
                    }
                    else if(item == "InternetCard")
                    {
                        p.setNumInternetCard(p.getNumInternetCard() + 1);
                    }
                    else if(item == "Premade Computer")
                    {
                        p.setNumPremadeComp(p.getNumPremadeComp() + 1);
                    }   
                    else if(item == "Antivirus")
                    {
                        p.setNumAntivirus(p.getNumAntivirus() + 1);
                    }
                    else if(item == "VPN")
                    {
                        p.setNumVPN(p.getNumVPN() + 1);
                    }
                    else if(item == "InternetLevel 2")
                    {
                        p.setInternetLevel(2);
                    }
                    else if(item == "InternetLevel 3")
                    {
                        p.setInternetLevel(3);
                    }
                    else if(item == "InternetLevel 4")
                    {
                        p.setInternetLevel(4);
                    }
                    else if(item == "InternetLevel 5")
                    {
                        p.setInternetLevel(5);
                    }
                }
            }
        }
    }
    else if(storeNum == 5)
    {
        while(userChoice != -1)
        {
            //display options
            int amountAvailable = p.getDogeCoin();
            cout << "select the product you would like to purchase using the number on the left or -1 to quit shopping!" << endl;
            cout << "You currently have " << amountAvailable << " dogecoin" << endl;
            printSelection();
            cin >> userChoice;
           
            if(userChoice > 0 && userChoice < 14)
            {
                double price = productPrices5[userChoice-1];
                string item = productNames[userChoice-1];
                if ((amountAvailable - price) < 0)
                {
                    cout << "Not enough dogecoin to complete this purchase :( please select another item or -1 to quit" << endl;
                }
                else if (amountAvailable - price >= 0)
                {
                    p.setDogeCoin(amountAvailable-price);
                    cout << "Purchase completed" << endl;

                    if(item == "GPU")
                    {
                        p.setNumGPU(p.getNumGPU() + 1);
                    }
                    else if(item == "CPU")
                    {
                        p.setNumCPU(p.getNumCPU() + 1);
                    }
                    else if(item == "PowerSupply")
                    {
                        p.setNumPower(p.getNumPower() + 1);
                    }
                    else if(item == "Computer Case")
                    {
                        p.setNumCompCase(p.getNumCompCase() + 1);
                    }
                    else if(item == "InternetCard")
                    {
                        p.setNumInternetCard(p.getNumInternetCard() + 1);
                    }
                    else if(item == "Premade Computer")
                    {
                        p.setNumPremadeComp(p.getNumPremadeComp() + 1);
                    }   
                    else if(item == "Antivirus")
                    {
                        p.setNumAntivirus(p.getNumAntivirus() + 1);
                    }
                    else if(item == "VPN")
                    {
                        p.setNumVPN(p.getNumVPN() + 1);
                    }
                    else if(item == "InternetLevel 2")
                    {
                        p.setInternetLevel(2);
                    }
                    else if(item == "InternetLevel 3")
                    {
                        p.setInternetLevel(3);
                    }
                    else if(item == "InternetLevel 4")
                    {
                        p.setInternetLevel(4);
                    }
                    else if(item == "InternetLevel 5")
                    {
                        p.setInternetLevel(5);
                    }
                }
            }
            
        }
    }
    return p;
}

