#include <iostream>
#include <fstream>
#include <array>

#define DATA_FILE "dane.txt" // "dane.txt" "przyklad.txt" 

using namespace std;

int main()
{
    ifstream data(DATA_FILE);
    int rows_count = 0;

    for(int i=0; i<200; i++)
    {
        array<int, 320> temp_row;
        bool is_unsymmetrical = false;

        for(int j=0; j<320; j++)
            data >> temp_row[j];

        for(int j=0; j<160; j++)
            if( temp_row[j] != temp_row[temp_row.size() - 1 - j] )
                is_unsymmetrical = true;

        if(is_unsymmetrical)
            rows_count++;
    }

    cout << "Ilosc wierszy: " << rows_count << endl;

    return 0;
}