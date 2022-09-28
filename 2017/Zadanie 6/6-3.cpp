#include <iostream>
#include <fstream>
#include <array>
#include <math.h>

#define DATA_FILE "dane.txt" // "dane.txt" "przyklad.txt" 

using namespace std;

int main()
{
    ifstream data(DATA_FILE);

    array<array<int, 320>, 200> picture;
    int contrast_counter = 0;

    for(int i=0; i<200; i++)
        for(int j=0; j<320; j++)
            data >> picture[i][j];

    for(int y=0; y<200; y++)
        for(int x=0; x<320; x++)
        {
            bool is_contrasting = false;

            if(y > 0)
                if( abs(picture[y][x] - picture[y-1][x]) > 128 ) 
                    is_contrasting = true;

            if(y < 199)
                if( abs(picture[y][x] - picture[y+1][x]) > 128 ) 
                        is_contrasting = true;

            if(x > 0)
                if( abs(picture[y][x] - picture[y][x-1]) > 128 ) 
                        is_contrasting = true;    

            if(x < 319)
                if( abs(picture[y][x] - picture[y][x+1]) > 128 ) 
                        is_contrasting = true;

            if(is_contrasting) contrast_counter ++;
        }

    cout << "Ilosc kontrastujacych: " << contrast_counter << endl;

    return 0;
}