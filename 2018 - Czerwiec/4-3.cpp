#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ofstream wyj("wynik4_3.txt");
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

        int counter1 = 0, counter2 = 0;
        for(int j=0; j<10; j++)
        {
            for(int h=0; h<10; h++){
                if(dane1[j] == dane2[h])
                    counter1++;
            }
        }
        for(int j=0; j<10; j++)
        {
            for(int h=0; h<10; h++){
                if(dane2[j] == dane1[h])
                    counter2++;
            }
        }

        if( counter1>=10 && counter2>=10 ){
            counter++;
            wyj << i+1 << " ";
        }
    }

    wyj << endl << counter;
    
    return 0;
}