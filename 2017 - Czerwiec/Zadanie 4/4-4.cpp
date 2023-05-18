#include <iostream>
#include <fstream>
#include <math.h>

#define LICZBA_WIERSZY 1000

using namespace std;

bool is_inside_square(int punkt_x, int punkt_y)
{
    if (punkt_x < 5000 && punkt_y < 5000)
    {
        return true;
    }
    
    return false;
}

bool is_on_square_side(int punkt_x, int punkt_y)
{
    if (punkt_x == 5000 || punkt_y == 5000)
    {
        return true;
    }
    
    return false;
}

int main()
{
    int punkty_x[LICZBA_WIERSZY], punkty_y[LICZBA_WIERSZY];
    int wewnatrz = 0, boki = 0, zewnatrz = 0;
    
    ifstream wejscie("punkty.txt");

    for (size_t i = 0; i < LICZBA_WIERSZY; i++)
    {
        wejscie >> punkty_x[i] >> punkty_y[i];
    }

    for (size_t i = 0; i < LICZBA_WIERSZY; i++)
    {
        wewnatrz += is_inside_square(punkty_x[i], punkty_y[i]);
        boki += is_on_square_side(punkty_x[i], punkty_y[i]);
    }

    zewnatrz = LICZBA_WIERSZY - wewnatrz - boki;

    cout << wewnatrz << '\t' << boki << '\t' << zewnatrz << endl;

    wejscie.close();

    return 0;
}