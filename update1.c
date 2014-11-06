int checkBothVector (char board[21][21], int n, int row, int col, int vecX, int vecY)
{
    char target = board[row][col];
    int count = 1;
    if (target == 'U' || target == 'R')
    {
       return 0;
    }
    else
    {
        for (int i = row + vecX , j = col + VecY;
             (i >= 0)&&(i < n)&&(j >= 0)&&(j < n);
               i+= vecX, j+= vecY)
        {
                 if (target == board[i][j])
                    count++;
                 else
                     break;
        }
        for (int i = row - vecX , j = col - VecY;
             (i >= 0)&&(i < n)&&(j >= 0)&&(j < n);
               i-= vecX, j-= vecY)
        {
                 if (target == board[i][j])
                    count++;
                 else
                     break;
        }
    }
    return count;        
}

int findLongest(char board[21][21], int n, int row, int col) 
{
    int longest, count = 0;
    for (int i = -1; i<=0; i++)
    {
        for(int j = -1; j<=1; j++)
        {
            if(i==0 && j==0) break;
            
            count = checkBothVector (board[21][21], n, row, col, i, j);
            if(count > longest)
            longest = count;
            
        }
    }

    return longest;
}
