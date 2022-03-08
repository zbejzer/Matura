#include <iostream>
#include <string>
#include <fstream>

#define PILK_WEJ "napisy.txt" // napisy przyklad

using namespace std;

bool czyPalindrom(string a)
{
    for (int i = 0; i < (a.size() - 1) / 2; i++)
    {
        if (a.at(i) != a.at(a.size() - 1 - i))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ifstream dane_wej(PILK_WEJ);
    int k = 0;
    string resoult = "";

    for (int i = 1; i <= 1000; i++)
    {
        string wiersz;
        dane_wej >> wiersz;

        //cout << wiersz.substr(1, wiersz.size() - 1) << endl;

        if (czyPalindrom(wiersz.substr(0, wiersz.size() - 1)))
        {
            resoult += wiersz.substr(0, wiersz.size() - 1).at(wiersz.size() / 2 - 1);
        }

        if (czyPalindrom(wiersz.substr(1, wiersz.size() - 1)))
        {
            resoult += wiersz.substr(1, wiersz.size() - 1).at(wiersz.size() / 2 - 1);
        }
    }

    cout << resoult << endl;
}