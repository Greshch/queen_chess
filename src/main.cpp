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
            printf("%3s", board_v[i][j] == QUEEN ? "@" : ".");
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid_coord(int row, int col)
{
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

bool is_queen_f(int row, int col)
{
    return board_v[row][col] == QUEEN;
}

bool is_empty_f(int row, int col)
{
    return board_v[row][col] == EMPTY;
}

void set_queen_f(int row, int col)
{
    if (!is_valid_coord(row, col) && is_empty_f(row, col))
    {
        return;
    }
    int b1 = row - col;
    int b2 = row + col;
    int x1 = 0;
    int x2 = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        board_v[row][i]++;
        board_v[i][col]++;
        x1 = i - b1;
        x2 = b2 - i;
        if (is_valid_coord(i, x1))
        {
            board_v[i][x1]++;
        }
        if (is_valid_coord(i, x2))
        {
            board_v[i][x2]++;
        }

    }
    board_v[row][col] = QUEEN;
}

void reset_board(int row, int col)
{
    int b1 = row - col;
    int b2 = row + col;
    int x1 = 0;
    int x2 = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        board_v[row][i]--;
        board_v[i][col]--;
        x1 = i - b1;
        x2 = b2 - i;
        if (is_valid_coord(i, x1))
        {
            board_v[i][x1]--;
        }
        if (is_valid_coord(i, x2))
        {
            board_v[i][x2]--;
        }
    }
    board_v[row][col] = EMPTY;
}

bool tryTurn(int n)
{
    bool result = false;
    for (int i = 0; i < SIZE; ++i)
    {
        if (is_empty_f(n, i))
        {
            set_queen_f(n, i);
            if (n == 7)
            {
                return true;
            }
            else
            {
                result = tryTurn(n + 1);
                if (!result)
                {
                    reset_board(n, i);
                }
            }
        }
        if (result)
            break;
    }
    return result;
}

int main(int argc, char** argv)
{
    /*if (argc < 3)
    {
        return -1;
    }
    int row = stoi(argv[1]);
    int col = stoi(argv[2]);*/
    prit_board_f();
    tryTurn(0);
    prit_board_f();

    return 0;
}