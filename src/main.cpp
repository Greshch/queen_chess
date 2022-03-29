#include <iostream>
using namespace std;

const int SIZE = 8;
const int ROWS = SIZE;
const int COLS = SIZE;

bool board[ROWS][COLS] {};


void print_board()
{
    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLS; ++col)
        {
            printf("%3d", board[row][col]);
        }
        printf("\n");
    }
}

int main()
{
    print_board();
    return 0;
}
