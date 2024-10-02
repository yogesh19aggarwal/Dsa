#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <random>
#include <time.h>
#include <thread>
#include <windows.h>
// #include <vector>

using namespace std;

const int PUZZLE_SIZE = 9;
const int EMPTY_VAl = 0;
array<int, 9> values{1, 2, 3, 4, 5, 6, 7, 8, 9};
int numberOfSOlution = 0;

void setCursorPosition(int x, int y){
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cout.flush();
    COORD coord = {(SHORT)x , (SHORT)y}; 
    SetConsoleCursorPosition(hOut , coord);
}
void sleep(int miliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(miliseconds));
}

void printPuzzle(int puzzle[PUZZLE_SIZE][PUZZLE_SIZE] , bool clear = true)
{
    if(clear){
        setCursorPosition(0,0);
    }


    string text = "", separator = "", padding = "";
    for (int i = 0; i < PUZZLE_SIZE; i++)
    {
        text = "|";
        separator = " -";
        padding = "|";
        for (int j = 0; j < PUZZLE_SIZE; j++)
        {
            string value = puzzle[i][j] == EMPTY_VAl ? " " : to_string(puzzle[i][j]);
            text += "  " + value + "  |";
            separator += "------";
            padding += "     |";

            if (j % 3 == 2 && j != PUZZLE_SIZE - 1)
            {

                padding += "|";
                text += "|";
            }
        }

        if (i % 3 == 0 && i != 0)
        {
            replace(separator.begin(), separator.end(), '-', '=');
        }
        cout << separator << endl;
        cout << padding << endl;
        cout << text << endl;
        cout << padding << endl;
    }
    cout << separator << endl;
}

bool isValid(int (&puzzle)[PUZZLE_SIZE][PUZZLE_SIZE], int row, int col, int value)
{
    // check if in this row already has this value
    for (int c = 0; c < PUZZLE_SIZE; c++)
    {
        if (puzzle[row][c] == value)
        {
            return false;
        }
    }
    // check if in this col already has this value
    for (int r = 0; r < PUZZLE_SIZE; r++)
    {
        if (puzzle[r][col] == value)
        {
            return false;
        }
    }

    // check if this current grid already has this value
    int startRow = floor(row / 3) * 3, startCol = floor(col / 3) * 3;
    for (int r = startRow; r < startRow + 3; r++)
    {
        for (int c = startCol; c < startCol + 3; c++)
        {
            if (puzzle[r][c] == value)
            {
                return false;
            }
        }
    }

    return true;
}

bool hasEmptyCell(int (&puzzle)[PUZZLE_SIZE][PUZZLE_SIZE])
{

    for (int i = 0; i < PUZZLE_SIZE; i++)
    {
        for (int j = 0; j < PUZZLE_SIZE; j++)
        {
            if (puzzle[i][j] == EMPTY_VAl)
            {
                return true;
            }
        }
    }

    return false;
}

bool fillPuzzle(int (&puzzle)[PUZZLE_SIZE][PUZZLE_SIZE])
{

    int row, col;

    for (int i = 0; i < PUZZLE_SIZE * PUZZLE_SIZE; i++)
    {
        row = floor(i / PUZZLE_SIZE);
        col = i % PUZZLE_SIZE;

        if (puzzle[row][col] == EMPTY_VAl)
        {
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            shuffle(values.begin(), values.end(), default_random_engine(seed));

            for (int j = 0; j < PUZZLE_SIZE; j++)
            {
                if (isValid(puzzle, row, col, values[j]))
                {
                    puzzle[row][col] = values[j];

                    if (!hasEmptyCell(puzzle) || fillPuzzle(puzzle))
                    {
                        return true;
                    }
                }
            }

            break;
        }
    }

    puzzle[row][col] = EMPTY_VAl;

    return false;
}

bool solveSudoku(int (&puzzle)[PUZZLE_SIZE][PUZZLE_SIZE], bool visualize = false)
{
    int row, col;

    for (int i = 0; i < PUZZLE_SIZE * PUZZLE_SIZE; i++)
    {
        row = floor(i / PUZZLE_SIZE);
        col = i % PUZZLE_SIZE;

        if (puzzle[row][col] == EMPTY_VAl)
        {
            for (int value = 1; value <= PUZZLE_SIZE; value++)
            {
                if (isValid(puzzle, row, col, value))
                {
                    puzzle[row][col] = value;

                    if (visualize)
                    {
                        sleep(100);
                        printPuzzle(puzzle);
                    }

                    if (!hasEmptyCell(puzzle))
                    {
                        numberOfSOlution++;
                        if (visualize)
                        {
                            sleep(100);
                            printPuzzle(puzzle);
                            return true;
                        }
                        break;
                    }
                    else if (solveSudoku(puzzle , visualize))
                    {
                        return true;
                    }
                }
            }
            break;
        }
    }

    puzzle[row][col] = EMPTY_VAl;

    if (visualize)
    {
        sleep(100);
        printPuzzle(puzzle);
    }

    return false;
}

void generatePuzzle(int (&puzzle)[PUZZLE_SIZE][PUZZLE_SIZE], int difficulty = 6)
{

    for (int i = 0; i < PUZZLE_SIZE; i++)
    {
        for (int j = 0; j < PUZZLE_SIZE; j++)
        {
            puzzle[i][j] = EMPTY_VAl;
        }
    }
    fillPuzzle(puzzle);

    // start removing cells from a fullfilled sudoku

    int attempt = difficulty;
    srand((unsigned)time(0));
    while (attempt > 0)
    {
        // generate random value between 0 - 8
        int row = floor(rand() % PUZZLE_SIZE);
        int col = floor(rand() % PUZZLE_SIZE);

        while (puzzle[row][col] == EMPTY_VAl)
        {
            row = floor(rand() % PUZZLE_SIZE);
            col = floor(rand() % PUZZLE_SIZE);
        }
        int oldValue = puzzle[row][col];
        puzzle[row][col] = EMPTY_VAl;

        numberOfSOlution = 0;
        solveSudoku(puzzle);

        // by set this cell to empty, the sudoku puzzle will not have only one solution then
        // we're not going to remove this cell
        if (numberOfSOlution != 1)
        {
            puzzle[row][col] = oldValue;
            attempt--;
        }
    }
}

int main()
{

    int puzzle[PUZZLE_SIZE][PUZZLE_SIZE];

    generatePuzzle(puzzle);
    printPuzzle(puzzle , true);

    char solve;
    cout << "Do you want to run algorithm for solve this puzzle. (y/n) : ";
    cin >> solve;

    if (solve == 'n' || solve == 'N')
    {
        cout.flush();
        return 0;
    }

    solveSudoku(puzzle , true);
    cout.flush();
    // printPuzzle(puzzle);
    return 0;
}