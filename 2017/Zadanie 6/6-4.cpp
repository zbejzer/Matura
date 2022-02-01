#include <iostream>
#include <fstream>
#include <array>

using namespace std;

int main()
{
    fstream dane_wejsciowe("dane.txt");
    array<array<int, 320>, 200> wczytany_wiersz;

    int najdluzsza_linia = 1;

    for(int i=0; i<200; i++)
        for(int j=0; j<320; j++)
            dane_wejsciowe >> wczytany_wiersz[i][j];

    for(int i=0; i<320; i++)
    {
        int dlugosc_lini = 1;

        for(int j=0; j<199; j++)
        {
            if( wczytany_wiersz[j][i] == wczytany_wiersz[j+1][i] )
                dlugosc_lini++;

            if( wczytany_wiersz[j][i] != wczytany_wiersz[j+1][i] || j >= 198 )
            {
                if(dlugosc_lini > najdluzsza_linia)
                    najdluzsza_linia = dlugosc_lini;

                dlugosc_lini = 1;
            }
        }
    }

    cout << "Dlugosc lini: " << najdluzsza_linia << endl;

    system("pause");
    return 0;
}