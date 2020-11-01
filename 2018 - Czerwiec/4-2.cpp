#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ofstream wyj("wynik4_2.txt");
    ifstream wej1("dane1.txt");
    ifstream wej2("dane2.txt");
    int counter = 0, parzyste1, parzyste2;
    int dane1[10], dane2[10];

    for(int i=0; i<1000; i++)
    {
        parzyste1 = 0;
        parzyste2 = 0;

        for(int j=0; j<10; j++)
        {
            int liczba;
            wej1 >> liczba;

            if(liczba%2 == 0)
                parzyste1++; 
        }
        for(int j=0; j<10; j++)
        {
            int liczba;
            wej2 >> liczba;

            if(liczba%2 == 0)
                parzyste2++; 
        }

        if(parzyste1 == 5 && parzyste2 == 5)
            counter++;
    }

    wyj << counter;
    
    return 0;
}