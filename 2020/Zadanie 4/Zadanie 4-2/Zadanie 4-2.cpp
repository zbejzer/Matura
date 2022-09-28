#include <iostream>
#include <fstream>
#include <array>
#include <string>

#define DATA_FILE "pary.txt" // przyklad pary 
#define DATA_SIZE 100

using namespace std;

string longestConsistent(string word) {
    string longest_consist = "";
    int p = 0, q = 0;

    while (q < word.size()) {
        if (word.at(p) != word.at(q)) {
            p = q;
        }
        else {
            if (word.substr(p, q - p + 1).size() > longest_consist.size()) {
                longest_consist = word.substr(p, q - p + 1);
            }
        }
        q++;
    }

    return longest_consist;
}

int main()
{
    ifstream data(DATA_FILE);

    for (size_t i = 0; i < DATA_SIZE; i++)
    {
        int number;
        string text;

        data >> number >> text;

        cout << longestConsistent(text) << " " << longestConsistent(text).size() << endl;
    }

    return 0;
}