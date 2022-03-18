#include <iostream>
#include <string>
#include <fstream>

#define PILK_WEJ "napisy.txt" // napisy przyklad

using namespace std;

int main()
{
    ifstream dane_wej(PILK_WEJ);
    int k = 0;
    string resoult = "";

    for (int i = 1; i <= 1000; i++)
    {
        string wiersz;
        dane_wej >> wiersz;

        if (i % 20 == 0)
        {
            resoult += wiersz[k];
            k++;
        }
    }

    cout << resoult << endl;
}