#include <fstream>
#include <iostream>

using namespace std;

bool isPowerOf3(int przyjetaLiczba)
{
    int obecnaLiczba = 1;

    while(obecnaLiczba <= 100000)
    {
        if(obecnaLiczba == przyjetaLiczba)
            return true;

        obecnaLiczba *= 3;
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