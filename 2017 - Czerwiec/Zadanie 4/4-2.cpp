#include <iostream>
#include <fstream>
#include <set>
#include <string>

#define LICZBA_WIERSZY 1000

using namespace std;

bool is_cyfropodobna(int liczba_1, int liczba_2)
{
    set<int> cyfry_1;
    set<int> cyfry_2;
    string liczba_1_s = to_string(liczba_1), liczba_2_s = to_string(liczba_2);

    for (size_t i = 0; i < liczba_1_s.size(); i++)
    {
        cyfry_1.insert(liczba_1_s[i]);
    }

    for (size_t i = 0; i < liczba_2_s.size(); i++)
    {
        cyfry_2.insert(liczba_2_s[i]);
    }
    
    return cyfry_1 == cyfry_2;
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
        if (is_cyfropodobna(punkty_x[i], punkty_y[i]))
        {
            counter++;
        }
    }

    cout << counter << endl;

    wejscie.close();

    return 0;
}