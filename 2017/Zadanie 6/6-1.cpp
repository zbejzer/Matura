#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream dane_wejsciowe("dane.txt");
    int najwieksza = 0, najmniejsza = 255;

    for(int i=0; i<320*200; i++)
    {
        int wczytana;
        dane_wejsciowe >> wczytana;

        if(wczytana > najwieksza)
            najwieksza = wczytana;
        if(wczytana < najmniejsza)
            najmniejsza = wczytana; 
    }

    cout << "Najwieksza, najmniejsza: " << najwieksza << " " << najmniejsza << endl;

    system("pause");
    return 0;
}