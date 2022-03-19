#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <set>

#define DATA_FILE_1 "dane1.txt" // dane1 przyklad1
#define DATA_FILE_2 "dane2.txt" // dane2 przyklad2
#define DATA_SIZE 1000          // 1000 5

using namespace std;

int main()
{
    ifstream data_1(DATA_FILE_1), data_2(DATA_FILE_2);
    int counter = 0;
    vector<int> lines_numbers;

    for (int i = 0; i < DATA_SIZE; i++)
    {
        set<int> numbers_1, numbers_2;

        for (int j = 0; j < 10; j++)
        {
            int number;

            data_1 >> number;
            numbers_1.insert(number);
            data_2 >> number;
            numbers_2.insert(number);
        }

        if (numbers_1 == numbers_2) {
            lines_numbers.push_back(i + 1);
            counter++;
        }
    }

    cout << counter << endl;

    for (size_t i = 0; i < lines_numbers.size(); i++)
    {
        cout << lines_numbers.at(i) << " ";
    }

    return 0;
}