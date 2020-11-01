#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ofstream wyj("wynik4_1.txt");
    ifstream wej1("dane1.txt");
    ifstream wej2("dane2.txt");
    int counter = 0;

    int dane1[10], dane2[10];

    for(int i=0; i<1000; i++)
    {
        for(int j=0; j<10; j++)
        {
            wej1 >> dane1[j];
        }
        for(int j=0; j<10; j++)
        {
            wej2 >> dane2[j];
        }

        if(dane1[9] == dane2[9])
            counter++;
    }

    wyj << counter;
    
    return 0;
}