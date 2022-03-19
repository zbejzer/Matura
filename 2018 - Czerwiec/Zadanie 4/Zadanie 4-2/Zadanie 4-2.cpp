#include <iostream>
#include <fstream>
#include <array>

#define DATA_FILE_1 "dane1.txt" // dane1 przyklad1
#define DATA_FILE_2 "dane2.txt" // dane2 przyklad2
#define DATA_SIZE 1000          // 1000 5

using namespace std;

int main()
{
    ifstream data_1(DATA_FILE_1), data_2(DATA_FILE_2);
    int counter = 0;

    for (int i = 0; i < DATA_SIZE; i++)
    {
        int even_count_1 = 0, even_count_2 = 0;

        for (int j = 0; j < 10; j++)
        {
            int number;

            data_1 >> number;
            even_count_1 += number % 2 == 0;
            data_2 >> number;
            even_count_2 += number % 2 == 0;
        }

        counter += even_count_1 == 5 && even_count_2 == 5;
    }

    cout << counter << endl;

    return 0;
}