#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int r_znakow(string wyraz)
{
    int counter = 0;
    for(int i = 'A'; i <= 'Z'; i++){
        if( count(wyraz.begin(), wyraz.end(), (char)i) > 0 )
            counter++;
    }

    return counter;
}

int main()
{
    ifstream f_wej("sygnaly.txt");
    ofstream f_wyj("4-2.txt");

    string wyjscie = "", max_s;
    int max = 0;
    
    for(int i = 1; i <= 1000; i++)
    {
        string temp;
        f_wej >> temp;
        if(r_znakow(temp) > max)
        {
            max_s = temp;
            max = r_znakow(temp);
        }
    }

    f_wyj << max_s << " " << max << endl;
   
    return 0;
}