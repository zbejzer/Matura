#include <iostream>
#include <fstream>
#include <array>
#include <math.h>

using namespace std;

int main()
{
    fstream dane_wejsciowe("dane.txt");
    array<array<int, 320>, 200> wczytany_wiersz;
    int ilosc_kontrastujacych = 0;

    for(int i=0; i<200; i++)
        for(int j=0; j<320; j++)
            dane_wejsciowe >> wczytany_wiersz[i][j];

    for(int i=0; i<200; i++)
        for(int j=0; j<320; j++)
        {
            bool czy_kontrasuje = false;

            if(i > 0)
                if( abs(wczytany_wiersz[i][j] - wczytany_wiersz[i-1][j]) > 128 ) 
                    czy_kontrasuje = true;

            if(i < 199)
                if( abs(wczytany_wiersz[i][j] - wczytany_wiersz[i+1][j]) > 128 ) 
                        czy_kontrasuje = true;

            if(j > 0)
                if( abs(wczytany_wiersz[i][j] - wczytany_wiersz[i][j-1]) > 128 ) 
                        czy_kontrasuje = true;    

            if(j < 319)
                if( abs(wczytany_wiersz[i][j] - wczytany_wiersz[i][j+1]) > 128 ) 
                        czy_kontrasuje = true;

            if(czy_kontrasuje) ilosc_kontrastujacych++;
        }

    cout << "Ilosc kontrastujacych: " << ilosc_kontrastujacych << endl;

    system("pause");
    return 0;
}