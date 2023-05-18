#include <iostream>
#include <fstream>
#include <math.h>

#define LICZBA_WIERSZY 1000

using namespace std;

long int distance(int punkt_1_x, int punkt_1_y, int punkt_2_x, int punkt_2_y)
{
    return pow(punkt_2_x - punkt_1_x, 2) + pow(punkt_2_y - punkt_1_y, 2);
}

int main()
{
    int punkty_x[LICZBA_WIERSZY], punkty_y[LICZBA_WIERSZY];
    long int max_distance = 0;
    int final_point_1_x = 0, final_point_1_y = 0,
        final_point_2_x = 0, final_point_2_y = 0;
    
    ifstream wejscie("punkty.txt");

    for (size_t i = 0; i < LICZBA_WIERSZY; i++)
    {
        wejscie >> punkty_x[i] >> punkty_y[i];
    }

    for (size_t p = 0; p < LICZBA_WIERSZY; p++)
    {
        for (size_t q = p + 1; q < LICZBA_WIERSZY; q++)
        {
            long int new_distance = distance(punkty_x[p], punkty_y[p], punkty_x[q], punkty_y[q]);
            if (new_distance > max_distance)
            {
                final_point_1_x = punkty_x[p];
                final_point_1_y = punkty_y[p];
                final_point_2_x = punkty_x[q];
                final_point_2_y = punkty_y[q];
                max_distance = new_distance;
            }
        }
    }

    cout << sqrt(max_distance) << '\t' << final_point_1_x << ' ' << final_point_1_y << '\t' << final_point_2_x << ' ' << final_point_2_y << endl;

    wejscie.close();

    return 0;
}