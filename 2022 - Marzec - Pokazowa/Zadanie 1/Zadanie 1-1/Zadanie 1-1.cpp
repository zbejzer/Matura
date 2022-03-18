#include <iostream>
#include <array>
#include <fstream>

using namespace std;

#define DATA_FILE "szachy.txt" // "szachy_przyklad.txt" "szachy.txt" 
#define DATA_SIZE 125 // 9 125

class Board
{
public:
    array<array<char, 8>, 8> arrangement;

    int getEmptyColumns();
};

int Board::getEmptyColumns() {
    int empty_counter = 0;

    for (int column = 0; column < 8; column++) {
        bool is_empty = true;

        for (int row = 0; row < 8; row++) {
            if (arrangement.at(row).at(column) != '.') {
                is_empty = false;
            }
        }

        empty_counter += is_empty;
    }

    return empty_counter;
}

int main()
{
    array<Board, DATA_SIZE> plansze;
    ifstream data(DATA_FILE);
    int empty_counter = 0, max_empty_columns = 0;

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
        if (plansze.at(i).getEmptyColumns() > 0) {
            empty_counter++;
        }
        if (plansze.at(i).getEmptyColumns() > max_empty_columns) {
            max_empty_columns = plansze.at(i).getEmptyColumns();
        }
    }

    cout << empty_counter << " " << max_empty_columns;

    return 0;
}