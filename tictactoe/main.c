#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

char board[3][3];
const char PLAYER = 'X';
const char PLAYER_TWO = 'O';
const char BOT = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void playerTwoMove();
void botMove();
char checkWinner();
void printWinner(char);

int main()
{
    char winner = ' ';
    char response;

    printf("\nWELCOME TO TIC TAC TOE\n");

    do
    {
        winner = ' '; // reset winner
        response = ' '; // reset user's choice to play again
        resetBoard();

        while(winner == ' ' && checkFreeSpaces() != 0) // check if there is a winner & available free spaces
        {
            printBoard();

            playerMove(); // the player's turn to make a move
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0) // check if there is a winner or no more free spaces
            {
                break; // break out of this while loop
            }

            // printBoard();

            // playerTwoMove(); // player 2's turn to make a move
            // winner = checkWinner();
            // if(winner != ' ' || checkFreeSpaces() == 0) // check if there is a winner or no more free spaces
            // {
            //     break; // break out of this while loop
            // }
            
            botMove(); // the bot's turn to make a move
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0) // check if there is a winner or no more free spaces
            {
                break; // break out of this while loop
            }
        }

        printBoard();
        printWinner(winner);

        printf("\n");
        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response); // add space before %c to avoid scanf to take in \n character
        response = toupper(response);
    } while (response == 'Y');

    printf("Thanks for playing, the program will exit now...");
    Sleep(3000);

    return 0;
}

void resetBoard() 
{
    for(int i = 0; i < 3; i++) // loop through each row
    {
        for(int j = 0; j < 3; j++) // loop through each column
        {
            board[i][j] = ' '; // fill the board with empty spaces
        }
    }
}

void printBoard() 
{
    printf("\n");
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");
}

int checkFreeSpaces() 
{
    int freeSpaces = 9;

    for(int i = 0; i < 3; i++) // loop through each row
    {
        for(int j = 0; j < 3; j++) // loop through each column
        {
            if(board[i][j] != ' ') // check if a space is not filled
            {
                freeSpaces--; // decrement by 1
            }
        }
    }
    return freeSpaces; // return the amount of free spaces
}

void playerMove() 
{
    int x, y;

    do // this do-while loop keeps going until a move is valid
    {
        printf("PLAYER 1's MOVE\n");
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--; // user input 1-3 becomes 0-2 because indexes go from 0-2
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--; // user input 1-3 becomes 0-2 because indexes go from 0-2

        if(board[x][y] != ' ') // check if the user's inputted space is filled
        {
            printf("Invalid move!\n");
        }
        else // if the space is open
        {
            board[x][y] = PLAYER; // set the player character in this slot
            break; // break out of this while loop
        }
    } while (board[x][y] != ' '); // if space is occupied, keep asking user for a different coordinate
}

void playerTwoMove()
{
    int x, y;

    do // this do-while loop keeps going until a move is valid
    {
        printf("PLAYER 2's MOVE\n");
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--; // user input 1-3 becomes 0-2 because indexes go from 0-2
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--; // user input 1-3 becomes 0-2 because indexes go from 0-2

        if(board[x][y] != ' ') // check if the user's inputted space is filled
        {
            printf("Invalid move!\n");
        }
        else // if the space is open
        {
            board[x][y] = PLAYER_TWO; // set the player character in this slot
            break; // break out of this while loop
        }
    } while (board[x][y] != ' '); // if space is occupied, keep asking user for a different coordinate
}

void botMove() 
{
    // bot move will be randomly generated 
    // creates a seed based on curent time
    srand(time(0));
    int x, y;

    if(checkFreeSpaces() > 0) // check if there are unoccupied spaces
    {
        printf("\nBOT MADE A MOVE\n");
        do
        {
            x = rand() % 3; // generate random number 1-3 for rows
            y = rand() % 3; // generate random number 1-3 for columns
        } while(board[x][y] != ' '); // keep generating random numbers until there is an open space

        board[x][y] = BOT; // set bot character in this slot
    }
    else // if no more spaces available
    {
        printWinner(' '); // there is no winner, it's a draw
    }
}

char checkWinner() 
{
    /*
        top left: board[0][0]
        top middle: board[0][1]
        top right: board[0][2]

        middle left: board[1][0]
        middle middle: board[1][1]
        middle right: board[1][2]

        bottom left: board[2][0]
        bottom middle: board[2][1]
        bottom right: board[2][2]
    */

    for(int i = 0; i < 3; i++) // check rows
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) // check if a row is 3-in-a-row
        {
            return board[i][0];
        }
    }

    for(int i = 0; i < 3; i++) // check columns
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) // check if a column is 3-in-a-row
        {
            return board[0][i];
        }
    }

    // check if diagonals are 3-in-a-row
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' '; // currently no winner so return empty character
}

void printWinner(char winner) 
{
    if(winner == PLAYER)
    {
        printf("PLAYER 1 WINS!");
    }
    else if(winner == PLAYER_TWO)
    {
        printf("PLAYER 2 WINS");
    }
    else if(winner == BOT)
    {
        printf("BOT WINS!");
    }
    else
    {
        printf("DRAW");
    }
}