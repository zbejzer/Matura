#include <iostream>
#include <string>
#include <fstream>

#define DATA_FILE "napisy.txt" // napisy przyklad

using namespace std;

int main()
{
    ifstream data(DATA_FILE);
    int counter = 0;

    for (int i = 0; i < 1000; i++)
    {
        string line;
        data >> line;

        for (int j = 0; j < line.size(); j++)
            if (line.at(j) < 'A')
                counter++;
    }

    cout << counter << endl;

    return 0;
}