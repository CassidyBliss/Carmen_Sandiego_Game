#include <stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

int randomNumbers(int min, int max)
{

    return (rand() % (max - min) + 1) + min;
}

bool checkMisfortune()
{
    srand(time(0));
    int num;
    bool flag;
    int PROB = 40;
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

int main()
{
    srand(time(0)); //seed needs to be different every time 
    cout << "Max: " << RAND_MAX << endl;
    for(int i =0; i < 7; i++)
    {
        cout << (rand() % 10)+1 << endl; 
    }

        //If I need between 1 and 10 -> rand() % 10 + 1
        //Generalized formula:
        //If I need b/w min and max -> rand() % (max - min + 1) + min
    
    int num;
    const int PROB_A = 40;
    num = randomNumbers(1, 100);

    if(num <= PROB_A)
    {
        cout << "Misfortune" << endl;
    }
    else
    {
        cout << "not misfortunate" << endl;
    }
    cout << checkMisfortune() << endl;
    return 0;
}