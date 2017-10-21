#include <stdio.h>
#include <stdlib.h>

/*
** We are given a N*N matrix input with N as our first argument. Our goal is to
** calculate the difference of the matrix's diagonals.
*/

int diagonal_diff(int n, int **matrix)
{
    int diag1 = 0;
    int diag1_x = 0;
    int diag1_y = 0;
    int diag2 = 0;
    int diag2_x = n-1;
    int diag2_y = 0;
    for (int y = 0; y < n; y++) // The row we are on
    {
        for (int x = 0; x < n; x++) // The col we are on
        {
            if (x == diag1_x && y == diag1_y)
            {
                diag1 += matrix[y][x];
                diag1_x++;
                diag1_y++;
            }
            if (x == diag2_x && y == diag2_y)
            {
                diag2 += matrix[y][x];
                diag2_x--;
                diag2_y++;
            }
        }
    }
    return (abs(diag1-diag2));
}

int main(){
    int n; 
    scanf("%d",&n);
    int **matrix = (int **)malloc(sizeof(int *) * n);
    int a[n][n];
    for(int i = 0; i < n; i++){
       int *col = (int *)malloc(sizeof(int) * n);
       for(int j = 0; j < n; j++){
          scanf("%d",&col[j]);
       }
        matrix[i] = col;
    }
    printf("%d",diagonal_diff(n, matrix));
    return 0;
}
