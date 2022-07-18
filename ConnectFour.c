/* ===========================================================================
Cameron Vandermeersch
Version 1.0
Date: April 27, 2022
=========================================================================== */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#define ROWS 6
#define COLS 7

bool make_move(char board[6][7], int column, char player);
bool check_win(char board[6][7], char player);

// Game Outline
int main(void)
{
    char board[ROWS][COLS];
    char bottomTab[] = "  0   1   2   3   4   5   6  ";
    char boardOutline[] = "|---|---|---|---|---|---|---|";
    char player = 'X';
    int column;
    int check;
    int game = 1;
    printf("-----------------------------\n");
    printf("  Welcome to Connect Four!\n");
    printf("-----------------------------\n");
    // Initialize the board to ensure empty spaces.
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = ' ';
        }
    }
    // Print the board and the scores according to current game:
    printf("%s\n", boardOutline);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("%s\n", boardOutline);
    }
    printf("-----------------------------");
    printf("\n%s\n\n", bottomTab);

    // Start the Game
    while (game != 0)
    {
        printf("Player %c, It Is Your Turn!\n", player);
        printf("Enter a Column Number To Drop Your Piece In: ");
        check = scanf("%d", &column);
        // Check if the column is valid
        if (check == 0)
        {
            printf("----------------------------\n");
            printf("Thanks For Playing, Goodbye!\n");
            break;
        }
        else if (column < 0 || column > 6)
        {
            printf("------------------------");
            printf("\nInvalid Column Number!\n");
            printf("------------------------\n");
            fflush(stdin);
            continue;
        }

        else if (make_move(board, column, player))
        {
            printf("\n\n");
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    printf("| %c ", board[i][j]);
                }
                printf("|\n");
                printf("%s\n", boardOutline);
            }
            printf("-----------------------------");
            printf("\n%s\n\n", bottomTab);

            if (check_win(board, player))
            {
                printf("------------------------------------------------\n");
                printf("Congratulations!!! Player %c Has Won The Game!\n", player);
                printf("------------------------------------------------\n");
                break;
            }
            else if (check_win(board, 'O'))
            {
                printf("\n\nPlayer O Wins!\n\n");
                break;
            }
            // Check for a tie
            else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[0][3] != ' ' && board[0][4] != ' ' && board[0][5] != ' ' && board[0][6] != ' ' && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' && board[1][3] != ' ' && board[1][4] != ' ' && board[1][5] != ' ' && board[1][6] != ' ' && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ' && board[2][3] != ' ' && board[2][4] != ' ' && board[2][5] != ' ' && board[2][6] != ' ' && board[3][0] != ' ' && board[3][1] != ' ' && board[3][2] != ' ' && board[3][3] != ' ' && board[3][4] != ' ' && board[3][5] != ' ' && board[3][6] != ' ' && board[4][0] != ' ' && board[4][1] != ' ' && board[4][2] != ' ' && board[4][3] != ' ' && board[4][4] != ' ' && board[4][5] != ' ' && board[4][6] != ' ' && board[5][0] != ' ' && board[5][1] != ' ' && board[5][2] != ' ' && board[5][3] != ' ' && board[5][4] != ' ' && board[5][5] != ' ' && board[5][6] != ' ')
            {
                printf("-------------------------------\n");
                printf("Oh Uh, Looks Like Its A Tie! :)\n");
                printf("-------------------------------\n");
                break;
            }
        }
        else
        {
            printf("------------------------------------------------\n");
            printf("Invalid! Sorry, Column %d is Full!\n", column);
            printf("------------------------------------------------\n");
            continue;
        }
        if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
    }
    return 0;
}

// make_move(board, column, player) updates the board following a move
// by the given player in the given column; returns false if the move
// was illegal because the column was full
// requires: 0 <= column < 7
// player is either 'X' or 'O'
bool make_move(char board[6][7], int column, char player)
{
    for (int c = ROWS - 1; c >= 0; c--)
    {
        if (board[c][column] == ' ')
        {
            board[c][column] = player;
            return true;
        }
    }
    return false;
}

// check_win(board) returns true if the given player has 4 connected
// pieces on the board.
bool check_win(char board[6][7], char player)
{
    // Check Columns (Vertical Win)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player)
            {
                return true;
            }
        }
    }

    // Check Rows (Horizontal Win)
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
            {
                return true;
            }
        }
    }

    // Check Diagonal Left
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
            {
                return true;
            }
        }
    }
    // Check Diagonal Right
    for (int i = 3; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player)
            {
                return true;
            }
        }
    }
    return false;
}
