#include <iostream>
#include <fstream>
#include <array>

using namespace std;

int main()
{
    fstream dane_wejsciowe("dane.txt");
    int ilosc_wierszy = 0;

    for(int i=0; i<200; i++)
    {
        array<int, 320> wczytany_wiersz;
        bool do_usuniecia = false;

        for(int j=0; j<320; j++)
            dane_wejsciowe >> wczytany_wiersz[j];

        for(int j=0; j<160; j++)
            if( wczytany_wiersz[j] != wczytany_wiersz[wczytany_wiersz.size() - 1 - j] )
                do_usuniecia = true;

        if(do_usuniecia)
            ilosc_wierszy++;
    }

    cout << "Ilosc wierszy: " << ilosc_wierszy << endl;

    system("pause");
    return 0;
}