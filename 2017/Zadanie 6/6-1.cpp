#include <iostream>
#include <fstream>

#define DATA_FILE "dane.txt" // "dane.txt" "przyklad.txt" 

using namespace std;

int main()
{
    ifstream data(DATA_FILE);
    int lightest = 0, darkest = 255;

    for(int i=0; i<320*200; i++)
    {
        int temp;
        data >> temp;

        if(temp > lightest)
            lightest = temp;
        if(temp < darkest)
            darkest = temp; 
    }

    cout << "Najwieksza, najmniejsza: " << lightest << " " << darkest << endl;

    return 0;
}