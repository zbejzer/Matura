#include <iostream>
#include <fstream>
#include <array>
#include <vector>

#define DATA_FILE_1 "dane1.txt" // dane1 przyklad1
#define DATA_FILE_2 "dane2.txt" // dane2 przyklad2
#define DATA_SIZE 1000          // 1000 5

using namespace std;

int main()
{
    ifstream data_1(DATA_FILE_1), data_2(DATA_FILE_2);

    for (int i = 0; i < DATA_SIZE; i++)
    {
        array<int, 10> numbers_1, numbers_2;
        vector<int> sum;
        int n_1 = 0, n_2 = 0;

        for (int j = 0; j < 10; j++)
        {
            data_1 >> numbers_1.at(j);
            data_2 >> numbers_2.at(j);
        }

        while (n_1 < 10 && n_2 < 10) {
            if (numbers_1.at(n_1) <= numbers_2.at(n_2)) {
                sum.push_back(numbers_1.at(n_1));
                n_1++;
            }
            else {
                sum.push_back(numbers_2.at(n_2));
                n_2++;
            }
        }

        while (n_1 < 10) {
            sum.push_back(numbers_1.at(n_1));
            n_1++;
        }

        while (n_2 < 10) {
            sum.push_back(numbers_2.at(n_2));
            n_2++;
        }

        for (int j = 0; j < sum.size(); j++) {
            cout << sum.at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}