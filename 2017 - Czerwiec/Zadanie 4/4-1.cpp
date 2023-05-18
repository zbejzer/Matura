#include <iostream>
#include <fstream>
#include <math.h>

#define LICZBA_WIERSZY 1000

using namespace std;

bool is_prime(int liczba)
{
    bool prime = true;
    int i = 3;

    if (liczba % 2 == 0)
    {
        prime = false;
    }

    while (i < sqrt(liczba) + 1 && prime)
    {
        if (liczba % i == 0)
        {
            prime = false;
        }

        i += 2;
    }
    
    return prime;
}

int main()
{
    int punkty_x[LICZBA_WIERSZY], punkty_y[LICZBA_WIERSZY];
    int counter = 0;
    
    ifstream wejscie("punkty.txt");

    for (size_t i = 0; i < LICZBA_WIERSZY; i++)
    {
        wejscie >> punkty_x[i] >> punkty_y[i];
    }

    for (size_t i = 0; i < LICZBA_WIERSZY; i++)
    {
        if (is_prime(punkty_x[i]) && is_prime(punkty_y[i]))
        {
            counter++;
        }
    }

    cout << counter << endl;

    wejscie.close();

    return 0;
}