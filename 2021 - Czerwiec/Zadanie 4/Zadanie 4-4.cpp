#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>

#define PILK_WEJ "napisy.txt" // napisy przyklad

using namespace std;

int main()
{
    ifstream dane_wej(PILK_WEJ);
    string resoult = "";

    for (int i = 0; i < 1000; i++)
    {
        string wiersz;
        vector<char> cyfry;
        dane_wej >> wiersz;

        for (int j = 0; j < wiersz.size(); j++)
        {
            if (wiersz[j] < 'A')
            {
                cyfry.push_back(wiersz.at(j));
            }
        }

        for (int j = 0; j < (cyfry.size() / 2) * 2; j = j + 2)
        {
            string suma_dwoch = "";
            suma_dwoch += cyfry.at(j);
            suma_dwoch += cyfry.at(j + 1);

            int suma_dwoch_int = stoi(suma_dwoch);

            //cout << suma_dwoch << endl;

            if (suma_dwoch_int >= 65 && suma_dwoch_int <= 90)
            {
                resoult += char(suma_dwoch_int);
            }
        }

        if (resoult.size() >= 3)
        {
            if (resoult.at(resoult.size() - 1) == 'X' && resoult.at(resoult.size() - 2) == 'X' && resoult.at(resoult.size() - 3) == 'X')
            {
                break;
            }
        }
    }

    cout << resoult << endl;
}