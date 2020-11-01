#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ofstream wyj("wynik4_4.txt");
    ifstream wej1("dane1.txt");
    ifstream wej2("dane2.txt");

    for(int i=0; i<1000; i++)
    {
        int element_a = 0, element_b = 0, dane1[10], dane2[10], out[20];

        for(int j=0; j<10; j++)
        {
            wej1 >> dane1[j];
            wej2 >> dane2[j];
        }

        while(element_a<=9 && element_b<=9){
            if(dane1[element_a] <= dane2[element_b]){
                out[element_a + element_b] = dane1[element_a];
                element_a++;
            }else{
                out[element_a + element_b] = dane2[element_b];
                element_b++;
            }
        } 

        int j = element_a+element_b;
        if(element_a != 10){
            while(element_a <= 9){
                out[j] = dane1[element_a];
                element_a++;
                j++;
            }
        }
        if(element_b != 10){
            while(element_b <= 9){
                out[j] = dane2[element_b];
                element_b++;
                j++;
            }
        }

        for(int j=0; j<20; j++)
            wyj << out[j] << " ";
        wyj << endl;
    }

    return 0;
}