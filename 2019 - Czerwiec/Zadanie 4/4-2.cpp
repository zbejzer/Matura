#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool isPrime(int liczba)
{
    bool warunek = true;

    for(int i=2; i<liczba; i++)
    {
        if(liczba % i == 0)
        {
            warunek = false;
            break;
        }
    }

    return warunek;
}

int main()
{
    ifstream f_wej("pierwsze.txt");
    ofstream f_wyj("wyniki4_2.txt");

    for(int i=0; i<200; i++)
    {
        int liczba, liczba_reverse;
        string s_liczba;
        f_wej >> liczba;

        s_liczba = to_string(liczba);
        reverse(s_liczba.begin(), s_liczba.end());

        liczba_reverse = stoi(s_liczba);

        if(isPrime(liczba) && isPrime(liczba_reverse))
        {
            f_wyj << liczba << endl;
        }
    }

    return 0;
}
