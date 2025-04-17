#include <stdio.h>
#include <stdbool.h>

#define N 4

// Function to print the solution board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the column for any other queens
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the N Queens problem using backtracking
bool solveNQueens(int board[N][N], int row) {
    // If all queens are placed, return true
    if (row >= N) {
        return true;
    }

    // Try placing the queen in all columns one by one
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // Place queen

            // Recur to place the rest of the queens
            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // If placing queen doesn't lead to a solution, backtrack
            board[row][col] = 0;  // Remove queen
        }
    }

    return false;
}

int main() {
    int board[N][N] = {0};  // Initialize the board with all 0s (no queens placed)

    // Try to solve the N-Queens problem
    if (solveNQueens(board, 0)) {
        // Print the solution
        printf("Solution to the N Queens Problem:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}

/*
Sample Output:
Solution to the N Queens Problem:
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 
*/
