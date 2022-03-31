#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <utility>
#include <GL/freeglut.h>
using namespace std;

int const SIZE = 8;
enum BOARD_STATUS
{
    QUEEN = -1,
    EMPTY,
    BITTEN
};

list<vector<pair<int, int>>> list_solutions;
vector<pair<int,int>> dota;

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
           abs(x4 - x5) == 1 || abs(x4 - x6) == 2 || abs(x4 - x7) == 3 || abs(x4 - x8) == 4
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
                                        vector<pair<int, int>> current;
                                        board_v[0][i1] = -1; current.push_back({0,i1});
                                        board_v[1][i2] = -1; current.push_back({1,i2});
                                        board_v[2][i3] = -1; current.push_back({2,i3});
                                        board_v[3][i4] = -1; current.push_back({3,i4});
                                        board_v[4][i5] = -1; current.push_back({4,i5});
                                        board_v[5][i6] = -1; current.push_back({5,i6});
                                        board_v[6][i7] = -1; current.push_back({6,i7});
                                        board_v[7][i8] = -1; current.push_back({7,i8});
                                        cout << "\n\t" << solutions++ << endl;
                                        print_board_f();
                                        power_off_board_f();
                                        list_solutions.push_back(current);
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
int const pixel = 64;
int const WIDTH = 10 * pixel;
int const HEIGHT = 10 * pixel;
int const FIELD_UP = 1 * pixel;
int const FIELD_DOWN = 9 * pixel;
int const FIELD_LEFT = 1 * pixel;
int const FIELD_RIGHT = 9 * pixel;

unsigned pause = 100;

void DisplayFunc();
void Timer(int);
void Keyboard(int key, int, int);

void draw_queen_gl(int row, int col);


int main(int argc, char** argv)
{
    rude_iterations_solution_f();
    dota = list_solutions.front();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(120, 20);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Queens_8");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WIDTH, HEIGHT, 0.0, -1.0, 1.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(DisplayFunc);
    glutTimerFunc(pause, Timer, 0);
    glutSpecialFunc(Keyboard);
    glutMainLoop();
    return 0;
}

void DisplayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glColor3f(0.0, 0.0, 1.0);
    // --- Draw Frame ---
    glBegin(GL_LINES);
    for (size_t y = FIELD_UP; y <= FIELD_DOWN; y += pixel)
    {
        glVertex2f(FIELD_LEFT, y);
        glVertex2f(FIELD_RIGHT, y);
    }

    for (size_t x = FIELD_LEFT; x <= FIELD_RIGHT; x += pixel)
    {
        glVertex2f(x, FIELD_UP);
        glVertex2f(x, FIELD_DOWN);
    }
    glEnd();


    for (int i = 0; i < dota.size(); ++i)
    {
        //printf("%3d%3d\n",dota[i].first, dota[i].second);
        //draw_queen_gl(dota[i].first, dota[i].second);
        float left = (dota[i].second + 1) *pixel ;
        float right = left + pixel;
        float top = (dota[i].first + 1) *pixel ;
        float down = top + pixel;
        glRectf(left, top, right, down);
    }
    glutSwapBuffers();
}

void Timer(int = 0)
{
    DisplayFunc();
    glutTimerFunc(pause, Timer, 0);
}

void Keyboard(int key, int, int)
{
    switch (key)
    {
        case GLUT_KEY_F12:
            printf("F12 exit\n");
            exit(0);
            break;

        case GLUT_KEY_LEFT:
            //printf("LEFT\n");
            break;

        case GLUT_KEY_UP:
            printf("UP\n");
            list_solutions.pop_back();
            if (!list_solutions.empty())
            {
                list_solutions.pop_front();
                dota = list_solutions.front();
            }

            //printf("\t#size = %3d\n", dota.size());

            break;

        case GLUT_KEY_RIGHT:
            //printf("RIGHT\n");
            break;

        case GLUT_KEY_DOWN:
            //printf("DOWN\n");

            break;

        default:
            break;
    }
}

void draw_queen_gl(int row, int col)
{
    static int const num_segments = 24;
    static float const r = pixel / 2.0 * 3.0 / 4.0;
    static float const cx = pixel * (1 + col + .5);
    static float const cy = pixel * (1 + row + .5);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
}