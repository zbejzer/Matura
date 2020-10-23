#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int sumaCyfr(int liczba)
{
    string s_liczba;
    int suma = 0;
    s_liczba = to_string(liczba);

    for(int i = 0; i < s_liczba.size(); i++)
    {
        suma += (int)s_liczba[i] - 48;
    }

    return suma;
}

int wagaLiczby(int liczba)
{
    while(liczba/10 != 0)
    {
        liczba = sumaCyfr(liczba);
    }

    return liczba;
}

int main()
{
    ifstream f_wej("pierwsze.txt");
    ofstream f_wyj("wyniki4_3.txt");

    int counter = 0;

    for(int i=0; i<200; i++)
    {
        int liczba;
        f_wej >> liczba;

        if(wagaLiczby(liczba) == 1)
        {
            counter++;
        }
    }

    f_wyj << counter;

    return 0;
}