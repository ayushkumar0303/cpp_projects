#include <iostream>
using namespace std;

void print_sudoku();
bool valid_number(int, int, int);
int sudoku_solver(int, int);

int sudoku_matrix[][9] = {{0, 0, 0, 8, 0, 0, 0, 0, 9},
                          {0, 1, 9, 0, 0, 5, 8, 3, 0},
                          {0, 4, 3, 0, 1, 0, 0, 0, 7},
                          {4, 0, 0, 1, 5, 0, 0, 0, 3},
                          {0, 0, 2, 7, 0, 4, 0, 1, 0},
                          {0, 8, 0, 0, 9, 0, 6, 0, 0},
                          {0, 7, 0, 0, 0, 6, 3, 0, 0},
                          {0, 3, 0, 0, 7, 0, 0, 8, 0},
                          {9, 0, 4, 5, 0, 0, 0, 0, 1}};
int main()
{
    cout << "\n***Sudoku Solver***" << endl;
    cout << "\nOriginal puzzle" << endl;
    print_sudoku();
    if(sudoku_solver(0, 0)==1){
        cout<<"Puzzle solved. "<<endl;
        print_sudoku();
    }else{

    cout << "\nPuzzle can not be solved." << endl;
    }

    return 0;
}

int sudoku_solver(int r, int c)
{
    if (c == 9)
    {
        if (r == 8)
        {
            return 1;
        }
        r++;
        c = 0;
    }
    if (sudoku_matrix[r][c] > 0)
    {
        return sudoku_solver(r, c + 1);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (valid_number(r, c, i))
        {
            sudoku_matrix[r][c] = i;
            if (sudoku_solver(r, c + 1))
            {
                return 1;
            }
            sudoku_matrix[r][c] = 0;
        }
    }
    return 0;
}
bool valid_number(int r, int c, int n)
{

    for (int col=0; col < 9; col++)
    {
        if (sudoku_matrix[r][col] == n)
        {
            return false;
        }
    }
    for (int row=0; row < 9; row++)
    {
        if (sudoku_matrix[row][c] == n)
        {
            return false;
        }
    }

    int row = r - r % 3;
    int col = c - c % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku_matrix[i + row][j + col] == n)
            {
                return false;
            }
        }
    }

    return true;
}
void print_sudoku()
{
    for (int row = 0; row < 9; row++)
    {
        if (row % 3 == 0)
        {
            cout << "+ - - - + - - - + - - - +" << endl;
        }
        for (int col = 0; col < 9; col++)
        {
            if (col % 3 == 0)
            {
                cout << "| ";
            }
            if (sudoku_matrix[row][col] == 0)
            {
                cout << "  ";
            }
            else
            {
                cout << sudoku_matrix[row][col] << " ";
            }
        }
        cout << "|" << endl;
    }

    cout << "+ - - - + - - - + - - - +" << endl;
}