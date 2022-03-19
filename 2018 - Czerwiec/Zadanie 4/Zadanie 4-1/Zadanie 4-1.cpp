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
        array<int, 10> line_1, line_2;

        for (int j = 0; j < 10; j++)
        {
            data_1 >> line_1.at(j);
            data_2 >> line_2.at(j);
        }

        counter += line_1.at(9) == line_2.at(9);
    }

    cout << counter << endl;

    return 0;
}