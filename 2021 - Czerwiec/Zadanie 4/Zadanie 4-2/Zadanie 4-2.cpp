#include <iostream>
#include <string>
#include <fstream>

#define DATA_FILE "napisy.txt" // napisy przyklad

using namespace std;

int main()
{
    ifstream data(DATA_FILE);
    int offset = 0;
    string result = "";

    for (int i = 1; i <= 1000; i++)
    {
        string line;
        data >> line;

        if (i % 20 == 0)
        {
            result += line.at(offset);
            offset++;
        }
    }

    cout << result << endl;

    return 0;
}