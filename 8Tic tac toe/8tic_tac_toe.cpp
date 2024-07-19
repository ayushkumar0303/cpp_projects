#include <iostream>
#include <cstdlib>

using namespace std;

bool is_valid_move(char[3][3]);
void print_matrix(char matrix[3][3]);
char turn_move();
bool match_win(char[3][3], char);
bool match_draw(char matrix[3][3]);
void play_game();
void computer_move(char[3][3]);
void player_move(char[3][3]);
int computer_win = 0, human_win = 0, draw = 0, choice;

char turn_move()
{
    srand(time(0));
    char chance;
    int random = rand() % 2;
    chance = random == 0 ? 'O' : 'X';
    return chance;
}
int main()
{
    int play_again;
    cout << "\n1. Human (Standard)" << endl;
    cout << "2. Computer (God Mode)" << endl;
    cout << "Select your difficuly level: ";
    cin >> choice;
    do
    {
        play_game();
        cout << "Enter 1 to play again else 0: ";
        cin >> play_again;

    } while (play_again == 1);

    return 0;
}

void play_game()
{
    char matrix[3][3] = {{' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '}};
    char chance = turn_move();

    while (1)
    {
        print_matrix(matrix);

        if (chance == 'X')
        {
            player_move(matrix);
            if (match_win(matrix, 'X'))
            {
                human_win++;
                print_matrix(matrix);
                cout << "\nCongratulations !, you won." << endl;
                return;
            }
            chance = 'O';
        }
        else
        {
            computer_move(matrix);
            if (match_win(matrix, 'O'))
            {
                computer_win++;
                print_matrix(matrix);
                cout << "\nI won, but you played will." << endl;
                return;
            }
            chance = 'X';
        }

        if (match_draw(matrix))
        {
            draw++;
            print_matrix(matrix);
            cout << "\nIt's draw" << endl;
            return;
        }
    }
}

void computer_move(char matrix[3][3])
{
    // 1 Immediate win
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == ' ')
            {

                matrix[i][j] = 'O';
                if (match_win(matrix, 'O'))
                {

                    return;
                }
                matrix[i][j] = ' ';
            }
        }
    }

    // 2 Immediate block
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == ' ')
            {
                matrix[i][j] = 'X';

                if (match_win(matrix, 'X'))
                {
                    matrix[i][j] = 'O';
                    return;
                }
                matrix[i][j] = ' ';
            }
        }
    }

    if (choice == 2)
    {
        if (matrix[1][1] == ' ')
        {
            matrix[1][1] = 'O';
            return;
        }
        char corner_move[4][2] = {{0, 0},
                                  {0, 2},
                                  {2, 0},
                                  {2, 2}};

        for (int i = 0; i < 4; i++)
        {

            if (matrix[corner_move[i][0]][corner_move[i][1]] == ' ')
            {
                matrix[corner_move[i][0]][corner_move[i][1]] = 'O';
                return;
            }
        }
    }

    // 5 play any move
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == ' ')
            {

                matrix[i][j] = 'O';
                return;
            }
        }
    }
}

void player_move(char matrix[3][3])
{

    int cnt = 0, x, y;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == ' ')
            {
                cnt++;
                x = i;
                y = j;
            }
        }
    }
    if (cnt == 1)
    {
        matrix[x][y] = 'X';
        return;
    }
    int row,col;
    cout << "\nPlayer's X move" << endl;
    do
    {
        cout << "Enter row and column (1-3): ";
        cin >> row >> col;
        row--;
        col--;

    } while (row < 0 || row > 2 || col < 0 || col > 2 || matrix[row][col] != ' ');

    matrix[row][col] = 'X';
}

bool match_win(char matrix[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == player and matrix[i][1] == player and matrix[i][2] == player)
        {
            return true;
        }

        if (matrix[0][i] == player and matrix[1][i] == player and matrix[2][i] == player)
        {
            return true;
        }
    }

    if ((matrix[0][0] == player and matrix[1][1] == player and matrix[2][2] == player) or (matrix[0][2] == player and matrix[1][1] == player and matrix[2][0] == player))
    {
        return true;
    }

    return false;
}

bool match_draw(char matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == ' ')
            {
                return false;
            }
        }
    }

    return true;
}

void print_matrix(char matrix[3][3])
{
    system("clear");
    cout << "\nComputer's Win: " << computer_win << ", Human's Win: " << human_win << ", Draw: " << draw << endl;
    cout << "\nTic Tac Toe\n"
         << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i % 3 != 0)
        {
            cout << "---+---+---" << endl;
        }
        for (int j = 0; j < 3; j++)
        {
            if (j % 3 != 0)
            {
                cout << "|";
            }
            cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
