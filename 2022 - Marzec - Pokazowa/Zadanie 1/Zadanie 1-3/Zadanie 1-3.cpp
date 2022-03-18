#include <iostream>
#include <array>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

#define DATA_FILE "szachy.txt" // "szachy_przyklad.txt" "szachy.txt" 
#define DATA_SIZE 125 // 9 125

const int capitalLetterOffset = 'a' - 'A';

enum class Color
{
    white,
    black
};

string to_string(array<char, 8> input) {
    string result = "";

    for (int i = 0; i < 8; i++) {
        result += input.at(i);
    }

    return result;
}

class Board
{
public:
    array<array<char, 8>, 8> arrangement;

    bool hasCheck(Color color);
};

bool Board::hasCheck(Color color) {
    bool check = false;
    int char_offset = 0;

    if (color == Color::black) {
        char_offset = capitalLetterOffset;
    }

    char king_letter = char('k' - char_offset), rook_letter = char('W' + char_offset);

    for (int row = 0; row < 8; row++) {
        if (to_string(arrangement.at(row)).find(king_letter) != string::npos) {
            int black_king = to_string(arrangement.at(row)).find(king_letter);
            int white_rook = 0;

            while (to_string(arrangement.at(row)).find(rook_letter, white_rook) != string::npos)
            {
                white_rook = to_string(arrangement.at(row)).find(rook_letter, white_rook);
                bool isSomethingBetween = false;

                for (int i = min(black_king, white_rook) + 1; i < max(black_king, white_rook); i++) {
                    if (arrangement.at(row).at(i) != '.') {
                        isSomethingBetween = true;
                    }
                }

                if (!isSomethingBetween) {
                    check = true;
                }

                white_rook++;
            }
        }
    }

    for (int column = 0; column < 8; column++) {
        string column_arrangement;

        for (int i = 0; i < 8; i++) {
            column_arrangement += arrangement.at(i).at(column);
        }

        if (column_arrangement.find(king_letter) != string::npos) {
            int black_king = column_arrangement.find(king_letter);
            int white_rook = 0;

            while (column_arrangement.find(rook_letter, white_rook) != string::npos)
            {
                white_rook = column_arrangement.find(rook_letter, white_rook);
                bool isSomethingBetween = false;

                for (int i = min(black_king, white_rook) + 1; i < max(black_king, white_rook); i++) {
                    if (column_arrangement.at(i) != '.') {
                        isSomethingBetween = true;
                    }
                }

                if (!isSomethingBetween) {
                    check = true;
                }

                white_rook++;
            }
        }
    }

    return check;
}

int main()
{
    array<Board, DATA_SIZE> boards;
    ifstream data(DATA_FILE);
    int white_counter = 0, black_counter = 0;

    for (int i = 0; i < DATA_SIZE; i++)
    {
        for (int j = 0; j < 8; j++) {
            string temp = "";

            data >> temp;
            for (int k = 0; k < 8; k++)
            {
                boards.at(i).arrangement.at(j).at(k) = temp.at(k);
            }
        }
    }

    for (int i = 0; i < boards.size(); i++)
    {
        white_counter += boards.at(i).hasCheck(Color::white);
        black_counter += boards.at(i).hasCheck(Color::black);
    }

    cout << white_counter << " " << black_counter;

    return 0;
}