#include<stdio.h>
void NQueen(int);
int isSafe(int, int);
void printSolution();
int n;
int totalsets = 0;
int board[20][20];

void main() {
    printf("Enter the number of Queens : ");
    scanf("%d", &n);
    board[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    NQueen(0);
    printf("Total solutions: %d\n", totalsets);
}

void NQueen(int row) {
    if (row == n) {
        totalsets++;
        printSolution();
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            NQueen(row + 1);
            board[row][col] = 0;
        }
    }
}

int isSafe(int row, int col) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return 0;
    }

    // Check the upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    // Check the upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

void printSolution() {
    printf("Solution %d:\n", totalsets);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if( board[i][j]==0){
                printf(" . ");
            }else{
                printf(" Q ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

