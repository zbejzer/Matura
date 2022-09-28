#include <iostream>
#include <fstream>
#include <array>

#define DATA_FILE "dane.txt" // "dane.txt" "przyklad.txt" 

using namespace std;

int main()
{
    ifstream data(DATA_FILE);

    array<array<int, 320>, 200> picture;
    int longest_line = 1;

    for(int i=0; i<200; i++)
        for(int j=0; j<320; j++)
            data >> picture[i][j];

    for(int i=0; i<320; i++)
    {
        int line_lenght = 1;

        for(int j=0; j<199; j++)
        {
            if( picture[j][i] == picture[j+1][i] )
                line_lenght++;

            if( picture[j][i] != picture[j+1][i] || j >= 198 )
            {
                if(line_lenght > longest_line)
                    longest_line = line_lenght;

                line_lenght = 1;
            }
        }
    }

    cout << "Dlugosc lini: " << longest_line << endl;

    return 0;
}