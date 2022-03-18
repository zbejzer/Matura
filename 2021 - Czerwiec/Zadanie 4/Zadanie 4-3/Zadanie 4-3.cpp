#include <iostream>
#include <string>
#include <fstream>

#define DATA_FILE "napisy.txt" // napisy przyklad

using namespace std;

bool isPalindrome(string word)
{
    for (int i = 0; i < word.size() / 2; i++)
    {
        if (word.at(i) != word.at(word.size() - 1 - i))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ifstream data(DATA_FILE);
    string result = "";

    for (int i = 1; i <= 1000; i++)
    {
        string line;
        data >> line;

        if (isPalindrome(line.substr(0, line.size() - 1)))
        {
            result += line.substr(0, line.size() - 1).at(line.size() / 2 - 1);
        }

        if (isPalindrome(line.substr(1, line.size() - 1)))
        {
            result += line.substr(1, line.size() - 1).at(line.size() / 2 - 1);
        }
    }

    cout << result << endl;

    return 0;
}