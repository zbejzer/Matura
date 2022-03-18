#include <iostream>
#include <array>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

#define DATA_FILE "szachy.txt" // "szachy_przyklad.txt" "szachy.txt" 
#define DATA_SIZE 125

class Board
{
public:
    array<string, 8> arrangement;

    bool hasWhiteCheck();
    bool hasBlackCheck();
};

bool Board::hasWhiteCheck() {
    bool check = false;

    for (int row = 0; row < 8; row++) {
        if (arrangement.at(row).find('k') != string::npos) {
            int black_king = arrangement.at(row).find('k');
            int white_rook = 0;

            while (arrangement.at(row).find('W', white_rook) != string::npos)
            {
                white_rook = arrangement.at(row).find('W', white_rook);
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

        if (column_arrangement.find('k') != string::npos) {
            int black_king = column_arrangement.find('k');
            int white_rook = 0;

            while (column_arrangement.find('W', white_rook) != string::npos)
            {
                white_rook = column_arrangement.find('W', white_rook);
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

bool Board::hasBlackCheck() {
    bool check = false;

    for (int row = 0; row < 8; row++) {
        if (arrangement.at(row).find('K') != string::npos) {
            int black_king = arrangement.at(row).find('K');
            int white_rook = 0;

            while (arrangement.at(row).find('w', white_rook) != string::npos)
            {
                white_rook = arrangement.at(row).find('w', white_rook);
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


        if (column_arrangement.find('K') != string::npos) {
            int black_king = column_arrangement.find('K');
            int white_rook = 0;

            while (column_arrangement.find('w', white_rook) != string::npos)
            {
                white_rook = column_arrangement.find('w', white_rook);
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
            data >> boards.at(i).arrangement.at(j);
        }
    }

    for (int i = 0; i < boards.size(); i++)
    {
        white_counter += boards.at(i).hasWhiteCheck();
        black_counter += boards.at(i).hasBlackCheck();
    }

    cout << white_counter << " " << black_counter;

    return 0;
}