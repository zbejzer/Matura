#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <cmath>

#define DATA_FILE "pary.txt" // przyklad pary 
#define DATA_SIZE 100

using namespace std;

bool isSmaller(string a, string b) {
    for (size_t i = 0; i < min(a.size(), b.size()); i++)
    {
        if (a.at(i) < b.at(i)) {
            return true;
        }
    }

    return false;
}

int main()
{
    ifstream data(DATA_FILE);
    string smallest_word = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    for (size_t i = 0; i < DATA_SIZE; i++)
    {
        int number;
        string text;

        data >> number >> text;

        if (number == text.size()) {
            if (isSmaller(text, smallest_word) || text.size() < smallest_word.size()) {
                smallest_word = text;
            }
        }
    }

    cout << smallest_word.size() << " " << smallest_word << endl;

    return 0;
}