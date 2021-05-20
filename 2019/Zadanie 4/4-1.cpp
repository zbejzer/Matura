#include <fstream>
#include <iostream>

using namespace std;

bool isPowerOf3(int sprawdzanaLiczba)
{
    for(int obecnaLiczba = 1; obecnaLiczba<=sprawdzanaLiczba; obecnaLiczba*=3) {
        if(obecnaLiczba == sprawdzanaLiczba)
            return true;
    }

    return false;
}

int main()
{
    ifstream sourceFile("liczby.txt");

    int powOf3Counter = 0;
    
    for(int i=0; i<500; i++)
    {
        int obecnaLiczba;
        sourceFile >> obecnaLiczba;

        if( isPowerOf3(obecnaLiczba) )
            powOf3Counter++;
    }

    cout << powOf3Counter;

    return 0;
}