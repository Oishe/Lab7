/* 
 * File:   Lab7.c
 * Author: farhanmd
 * Created on October 30, 2014, 4:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void emptyBoard(char board[21][21], int n)
{
    for(int i= 0; i<n; i++)
        for(int j=0; j<n;j++)
            board[i][j] = 'U';
}

void printBoard(char board[21][21], int n)
{
    for(int i= 0; i<n; i++)
    {
        for(int j=0; j<n;j++)
        printf("%c", board[i][j]);
        printf("\n");
    }    
}

void blockBoard(char board[21][21], int n)
{
    int row, col;
    bool inRange = true, open;
    while(inRange)
    {
        printf("Enter position (ROW COL) of blocked square;"
        " (-1 -1) to finish: ");
        scanf("%d%d", &row, &col);
        inRange = (row>=0)&&(col>=0);
        open = board[row][col] == 'U';
        if (!open & inRange) printf("Position already occupied, try again\n");
        else if (open & inRange )
        {
            board[row][col] = 'R';
            printBoard(board, n);
        }
    }
}

void playBoard(char board[21][21], int n)
{
    int turn = 1;
    int row, col;
    bool inRange = true, open, black;
    while(inRange)
    {
        black = turn % 2;
        if(black)printf("Enter Black");
        else printf("Enter White");
        printf(" Move (ROW COL); (-1 -1) to finish: ");
        scanf("%d%d", &row, &col);
        inRange = (row>=0)&&(col>=0);
        open = board[row][col] == 'U';
        if (!open & inRange)
            printf("That square is already occupied or blocked\n");
        else if (open & inRange)
        {
            if(black) board[row][col] = 'B';
            else board[row][col] = 'W';
            printBoard(board, n);
            turn++;
        }
    }
}

void checkWinner(char board[21][21], int n)
{
    int countSix = 0;
    char winner = 'U';
    for(int i =0; i<n; i++)
        for(int j =0; j<n; j++)
        {
            countSix = findLongest(board[21][21], n, i, j)
            if (countSix >= 6)
            winner = board[i][j];
        }
    if (winner == 'U')
    printf("No winner so far");
    else if (winner == 'B')
    printf("Black wins")
    else if(winner == 'W')
    printf("White wins")
}
void askLongest (char board[21][21], int n, int row, int col)
{
    bool inRange = (row>=0)||(col>=0);
    while (inRange)
    {
        
    }
}

int findLongest (char board[21][21], int n, int row, int col)
{
    char target = board[row][col];
    if (target == 'U') return 0;
    else
    {
        int longest;
        int count = 1;
        //West
        for(int j = col-1; j >= 0; j--)
            if(target == board[row][j]) count++;
            else break;
        //East
        for(int j = col+1; j<n; j++)
            if(target == board[row][j]) count++;
            else break;
        longest = count;
        count = 1;
        //North
        for(int i= row-1; i >= 0; i--)
            if(target == board[i][col]) count++;
            else break;
        //South
        for(int i = row+1; i<n; i++)
            if(target == board[i][col]) count++;
            else break;
        if(count > longest)
            longest = count;
        count = 1;
        //North West
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
            if(target == board[i][j]) count++;
                else break;
        //South East
        for (int i=row+1, j=col+1; i<n && j<n; i++, j++)
            if(target == board[i][j]) count++;
                else break;
        if(count > longest)
            longest = count;
        count = 1;
        //North East
        for (int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
            if(target == board[i][j]) count++;
                else break;
        //South West
        for (int i=row+1, j=col-1; i<n && j>=0; i++, j--)
            if(target == board[i][j]) count++;
                else break;
        if(count > longest)
            longest = count;
                        
        return longest;
    }
    
}



int main()
{
    int size;
    char board [21][21];
    printf("Enter board dimensions (n), n>=6 and n<=21: ");
    scanf("%d", &size);
    emptyBoard(board, size);
    printBoard(board, size);
    blockBoard(board, size);
    playBoard(board, size);
    checkWinner(board, size);
    printf("\n%d", findLongest(board, size, 0, 0));
    
    
    return (EXIT_SUCCESS);
}

int Main ()
{
    int size = 6;
    char board [21][21];
    emptyBoard(board, size);
    printBoard(board, size);
    for (int i=0; i<5; i++){
        board [0][i] = 'B';
        board [1][i] = 'B';
        board [2][i] = 'B';
    }
    printf("\n");
    printBoard(board, size);
    
    printf("\n%d", findLongest(board, size, 0, 0));
    printf("\n%d", findLongest(board, size, 0, 1));
    printf("\n%d", findLongest(board, size, 0, 2));
    printf("\n%d", findLongest(board, size, 0, 3));
    printf("\n%d", findLongest(board, size, 0, 4));
    printf("\n%d", findLongest(board, size, 0, 5));
    printf("\n%d", findLongest(board, size, 1, 0));
    printf("\n%d", findLongest(board, size, 1, 1));
    printf("\n%d", findLongest(board, size, 1, 2));
    printf("\n%d", findLongest(board, size, 1, 3));
    printf("\n%d", findLongest(board, size, 1, 4));
    printf("\n%d", findLongest(board, size, 1, 5));
    return (EXIT_SUCCESS);
}
