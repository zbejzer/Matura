#include <iostream>
#include <array>
#include <fstream>
#include <map>

using namespace std;

#define DATA_FILE "szachy_przyklad.txt" // "szachy_przyklad.txt" "szachy.txt" 
#define DATA_SIZE 125

class Board
{
public:
    array<array<char, 8>, 8> arrangement;

    map<char, int> getBlackCount();
    map<char, int> getWhiteCount();
};

map<char, int> Board::getBlackCount() {
    map<char, int> counter;

    for (int row = 0; row < 8; row++) {
        for (int column = 0; column < 8; column++) {
            if (arrangement.at(row).at(column) >= 'a' && arrangement.at(row).at(column) <= 'x') {
                counter[arrangement.at(row).at(column)]++;
            }
        }
    }

    return counter;
}

map<char, int> Board::getWhiteCount() {
    map<char, int> counter;

    for (int row = 0; row < 8; row++) {
        for (int column = 0; column < 8; column++) {
            if (arrangement.at(row).at(column) >= 'A' && arrangement.at(row).at(column) <= 'X') {
                counter[char(arrangement.at(row).at(column) - 'A' + 'a')]++;
            }
        }
    }

    return counter;
}

int main()
{
    array<Board, DATA_SIZE> plansze;
    ifstream data(DATA_FILE);
    int equal_counter = 0, minimal_count = INT32_MAX;

    for (int i = 0; i < DATA_SIZE; i++)
    {
        string trash;
        for (int j = 0; j < 8; j++) {
            string temp;
            data >> temp;
            for (int k = 0; k < temp.size(); k++)
            {
                plansze.at(i).arrangement.at(j).at(k) = temp.at(k);
            }
        }
    }

    for (int i = 0; i < plansze.size(); i++)
    {
        if (plansze.at(i).getBlackCount() == plansze.at(i).getWhiteCount() && plansze.at(i).getWhiteCount().size() > 0) {
            equal_counter++;

            if (minimal_count > plansze.at(i).getWhiteCount().size()) {
                minimal_count = plansze.at(i).getWhiteCount().size();
            }
        }
    }

    cout << equal_counter << " " << minimal_count;

    return 0;
}