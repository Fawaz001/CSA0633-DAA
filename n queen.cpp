#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 8

int count = 0;

void printSolution(int board[N][N]) {
    printf("Solution %d:\n", ++count);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
 
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false; 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false; 
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col, int desiredSolutions) {
    if (col >= N) {
        if (count >= desiredSolutions)
            return true;
        printSolution(board);
        return false;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1, desiredSolutions) || res;
            board[i][col] = 0; 
        }
    }
    return res;
}

void solveNQ(int desiredSolutions) {
    int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0} };

    if (!solveNQUtil(board, 0, desiredSolutions))
        printf("No solution exists.\n");
}

int main() {
    int desiredSolutions;
    printf("Enter the number of solutions desired: ");
    scanf("%d", &desiredSolutions);
    solveNQ(desiredSolutions);
    return 0;
}
