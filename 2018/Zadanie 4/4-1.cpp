#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream f_wej("sygnaly.txt");
    ofstream f_wyj("4-1.txt");

    string temp, wyjscie = "";
    
    for(int i = 1; i <= 1000; i++)
    {
        f_wej >> temp;
        if(i%40 == 0)
        {
            wyjscie += temp[9];
        }
    }

    f_wyj << wyjscie;

    return 0;
}