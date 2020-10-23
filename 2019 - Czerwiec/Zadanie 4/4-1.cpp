#include <iostream>
#include <fstream>

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
    ifstream f_wej("liczby.txt");
    ofstream f_wyj("wyniki4_1.txt");

    for(int i=0; i<300; i++)
    {
        int liczba;
        f_wej >> liczba;

        if(liczba>=100 && liczba<=5000 && isPrime(liczba))
        {
            f_wyj << liczba << endl;
        }
    }

    return 0;
}
