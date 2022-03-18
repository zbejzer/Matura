#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>

#define DATA_FILE "napisy.txt" // napisy przyklad

using namespace std;

int main()
{
    ifstream data(DATA_FILE);
    string result = "";

    for (int i = 0; i < 1000; i++)
    {
        string line;
        vector<char> digits;
        data >> line;

        for (int j = 0; j < line.size(); j++)
        {
            if (line.at(j) < 'A')
            {
                digits.push_back(line.at(j));
            }
        }

        for (int j = 0; j < (digits.size() / 2) * 2; j = j + 2)
        {
            string pair = "";
            pair += digits.at(j);
            pair += digits.at(j + 1);

            int pair_number = stoi(pair);

            if (pair_number >= 65 && pair_number <= 90)
            {
                result += char(pair_number);
            }
        }

        if (result.size() >= 3)
        {
            if (result.substr(result.size()-3, 3) == "XXX")
            {
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}