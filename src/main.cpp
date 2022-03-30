#include <iostream>
using namespace std;

int const SIZE = 8;
enum BOARD_STATUS
{
    QUEEN = -1,
    EMPTY,
    BITTEN
};

int board_v[SIZE][SIZE] {EMPTY};

void prit_board_f()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            printf("%3d", board_v[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid_coord(int row, int col)
{
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

void set_queen_f(int row, int col)
{
    if (!is_valid_coord(row, col))
    {
        return;
    }
    int b1 = row - col;
    int b2 = row + col;
    cout << "b1 " << b1 << "\tb2 " << b2 << endl;
    int x1 = 0;
    int x2 = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        board_v[row][i] = BITTEN;
        board_v[i][col] = BITTEN;
        x1 = i - b1;
        x2 = b2 - i;
        if (is_valid_coord(i, x1))
        {
            board_v[i][x1] = BITTEN;
        }
        if (is_valid_coord(i, x2))
        {
            board_v[i][x2] = BITTEN;
        }

    }
    board_v[row][col] = QUEEN;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        return -1;
    }
    int row = stoi(argv[1]);
    int col = stoi(argv[2]);
    //prit_board_f();
    set_queen_f(row, col);
    prit_board_f();
    return 0;
}