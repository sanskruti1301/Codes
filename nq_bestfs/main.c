#include <stdio.h>
#include <stdbool.h>

#define N 20  // Maximum board size
int solutions = 0;

// Function to print the board
void printBoard(int board[N][N], int n) {
    printf("Solution %d:\n", solutions);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col, int n) {
    int i, j;

    // Check the row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to find all solutions
void solveNQueens(int board[N][N], int col, int n) {
    if (col == n) {
        printBoard(board, n);
        solutions++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            solveNQueens(board, col + 1, n);
            board[i][col] = 0;
        }
    }
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid input. N should be between 1 and %d.\n", N);
        return 1;
    }

    int board[N][N];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    solveNQueens(board, 0, n);

    if (solutions == 0) {
        printf("No solutions found for N = %d.\n", n);
    } else {
        printf("Total solutions found: %d\n", solutions);
    }

    return 0;
}
