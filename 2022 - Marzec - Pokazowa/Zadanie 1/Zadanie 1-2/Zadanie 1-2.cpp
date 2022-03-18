#include <iostream>
#include <array>
#include <fstream>
#include <map>

using namespace std;

#define DATA_FILE "szachy.txt" // "szachy_przyklad.txt" "szachy.txt" 
#define DATA_SIZE 125 // 9 125

const int capitalLetterOffset = 'a' - 'A';

enum class Color
{
    white,
    black
};

class Board
{
public:
    array<array<char, 8>, 8> arrangement;

    map<char, int> getPieces(Color color);
    int getPiecesCount();
};

map<char, int> Board::getPieces(Color color) {
    map<char, int> counter;
    int char_offset = 0;

    if (color == Color::black) {
        char_offset = capitalLetterOffset;
    }

    for (int row = 0; row < 8; row++) {
        for (int column = 0; column < 8; column++) {
            if (arrangement.at(row).at(column) >= 'A' + char_offset && arrangement.at(row).at(column) <= 'X' + char_offset) {
                counter[char(arrangement.at(row).at(column) - char_offset)]++;
            }
        }
    }

    return counter;
}

int Board::getPiecesCount()
{
    int counter = 0;

    for (int row = 0; row < 8; row++) {
        for (int column = 0; column < 8; column++) {
            if (arrangement.at(row).at(column) != '.') {
                counter++;
            }
        }
    }

    return counter;
}

int main()
{
    array<Board, DATA_SIZE> boards;
    ifstream data(DATA_FILE);
    int equal_counter = 0, minimal_count = 64, minimal_id = 0;

    for (int i = 0; i < DATA_SIZE; i++)
    {
        string trash;
        for (int j = 0; j < 8; j++) {
            string temp;
            data >> temp;
            for (int k = 0; k < temp.size(); k++)
            {
                boards.at(i).arrangement.at(j).at(k) = temp.at(k);
            }
        }
    }

    for (int i = 0; i < boards.size(); i++)
    {
        if (boards.at(i).getPieces(Color::black) == boards.at(i).getPieces(Color::white) && boards.at(i).getPieces(Color::white).size() > 0) {
            equal_counter++;

            if (minimal_count > boards.at(i).getPiecesCount()) {
                minimal_count = boards.at(i).getPiecesCount();
                minimal_id = i;
            }
        }
    }

    cout << equal_counter << " " << boards.at(minimal_id).getPiecesCount();

    return 0;
}