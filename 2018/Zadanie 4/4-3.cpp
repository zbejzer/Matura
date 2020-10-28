#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    ifstream f_wej("sygnaly.txt");
    ofstream f_wyj("4-3.txt");
    
    for(int i = 1; i <= 1000; i++)
    {
        bool warunek = true;
        string temp;
        char obecna_litera, poprzednia_litera;
        f_wej >> temp;

        obecna_litera = temp[0];

        for(int i = 0; i < temp.size(); i++){
            poprzednia_litera = obecna_litera;
            obecna_litera = temp[i];
            if( abs((int)obecna_litera - (int)poprzednia_litera) > 10 )
                warunek = false;
        }

        if(warunek)
            f_wyj << temp << endl;
    }
    return 0;
}