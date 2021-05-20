#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

struct ciag
{
    int dzielnik;
    int pierwszaLiczba;
    int dlugosc;

    ciag()
    {
        dlugosc = 0;
    }

    ciag(int _pierwszaLiczba)
    {
        dlugosc = 1;
        pierwszaLiczba = _pierwszaLiczba;
        dzielnik = _pierwszaLiczba;
    }
};

int fNWD(int x, int y)
{
    while (x!=y)
    {
        if(x>y)
            x-=y;
        else
            y-=x;
    }
    return x;
}

int main()
{
    ifstream sourceFile("liczby.txt");
    array<int, 500> liczby;

    for(int i=0; i<liczby.size(); i++)
        sourceFile >> liczby[i];

    ciag najdluzszyCiag;
    ciag obecnyCiag(liczby[0]);
    
    for(int i=1; i<500; i++)
    {
        if( fNWD(liczby[i], obecnyCiag.dzielnik) > 1)
        {
            obecnyCiag.dzielnik = fNWD(liczby[i], obecnyCiag.dzielnik);
            obecnyCiag.dlugosc++;
        }
        
        if(obecnyCiag.dlugosc > najdluzszyCiag.dlugosc)
            najdluzszyCiag = obecnyCiag;

        if( fNWD(liczby[i], obecnyCiag.dzielnik) == 1)
        {
            if( fNWD(liczby[i], liczby[i-1]) > 1)
            {
                obecnyCiag.dlugosc = 2;
                obecnyCiag.pierwszaLiczba = liczby[i-1];
                obecnyCiag.dzielnik = fNWD(liczby[i], liczby[i-1]);
            }
            else
            {
                obecnyCiag.dlugosc = 1;
                obecnyCiag.pierwszaLiczba = liczby[i];
                obecnyCiag.dzielnik = liczby[i];
            }
        }
    }

    cout << najdluzszyCiag.pierwszaLiczba << " " << najdluzszyCiag.dlugosc << " " << najdluzszyCiag.dzielnik << endl;

    return 0;
}