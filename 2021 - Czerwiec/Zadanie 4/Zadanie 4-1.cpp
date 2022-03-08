#include <iostream>
#include <string>
#include <fstream>

#define PILK_WEJ "napisy.txt" // napisy przyklad

using namespace std;

int main()
{   
    ifstream dane_wej(PILK_WEJ);
    int counter = 0;

    for (int i = 0; i < 1000; i++)
    {
        string wiersz;
        dane_wej >> wiersz;

        for (int j = 0; j < wiersz.size(); j++)
            if (wiersz[j] < 'A')
                counter++;
    }

    cout << counter << endl;
}