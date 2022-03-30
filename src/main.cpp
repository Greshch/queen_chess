#include <iostream>
#include <GL/freeglut.h>
using namespace std;

int const SIZE = 8;
enum BOARD_STATUS
{
    QUEEN = -1,
    EMPTY,
    BITTEN
};

int board_v[SIZE][SIZE] {EMPTY};

void print_board_f()
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

void power_off_board_f()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            board_v[i][j] = 0;
        }
    }
}

bool is_intersect_f(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8) // rude show!!
{
    return x1 == x2 || x1 == x3 || x1 == x4 || x1 == x5 || x1 == x6 || x1 == x7 || x1 == x8
           ||
           x2 == x3 || x2 == x4 || x2 == x5 || x2 == x6 || x2 == x7 || x2 == x8
           ||
           x3 == x4 || x3 == x5 || x3 == x6 || x3 == x7 || x3 == x8
           ||
           x4 == x5 || x4 == x6 || x4 == x7 || x4 == x8
           ||
           x5 == x6 || x5 == x7 || x5 == x8
           ||
           x6 == x7 || x6 == x8
           ||
           x7 == x8
           ||
           abs(x1 - x2) == 1 || abs(x1 - x3) == 2 || abs(x1 - x4) == 3 || abs(x1 - x5) == 4 || abs(x1 - x6) == 5 || abs(x1 - x7) == 6 || abs(x1 - x8) == 7
           ||
           abs(x2 - x3) == 1 || abs(x2 - x4) == 2 || abs(x2 - x5) == 3 || abs(x2 - x6) == 4 || abs(x2 - x7) == 5 || abs(x2 - x8) == 6
           ||
           abs(x3 - x4) == 1 || abs(x3 - x5) == 2 || abs(x3 - x6) == 3 || abs(x3 - x7) == 4 || abs(x3 - x8) == 5
           ||
           abs(x4 - x5) == 1 || abs(x4 - x6) == 2 || abs(x5 - x7) == 3 || abs(x5 - x8) == 4
           ||
           abs(x5 - x6) == 1 || abs(x5- x7) == 2 || abs(x5 - x8) == 3
           ||
           abs(x6 - x7) == 1 || abs(x6- x8) == 2
           ||
           abs(x7- x8) == 1;
}

void rude_iterations_solution_f()
{
    int solutions = 0;
    for (int i1 = 0; i1 < SIZE; ++i1)
    {
        for (int i2 = 0; i2 < SIZE; ++i2)
        {
            for (int i3 = 0; i3 < SIZE; ++i3)
            {
                for (int i4 = 0; i4 < SIZE; ++i4)
                {
                    for (int i5 = 0; i5 < SIZE; ++i5)
                    {
                        for (int i6 = 0; i6 < SIZE; ++i6)
                        {
                            for (int i7 = 0; i7 < SIZE; ++i7)
                            {
                                for (int i8 = 0; i8 < SIZE; ++i8)
                                {
                                    if (!is_intersect_f(i1, i2, i3, i4, i5, i6, i7, i8))
                                    {
                                        board_v[0][i1] = -1;
                                        board_v[1][i2] = -1;
                                        board_v[2][i3] = -1;
                                        board_v[3][i4] = -1;
                                        board_v[4][i5] = -1;
                                        board_v[5][i6] = -1;
                                        board_v[6][i7] = -1;
                                        board_v[7][i8] = -1;
                                        cout << "\n\t" << solutions++ << endl;
                                        print_board_f();
                                        power_off_board_f();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////    OpenGL     //////////////////////////////////////////////////////
int const pixel = 32;
int const WIDTH = 10 * pixel;
int const HEIGHT = 10 * pixel;



int main(int argc, char** argv)
{
    rude_iterations_solution_f();
    glutInit(&argc, argv);

    glutMainLoop();
    return 0;
}