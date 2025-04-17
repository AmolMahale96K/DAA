#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10  // Maximum size of the board (N x N)

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N) {
    // Check the column for conflicts
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper-left diagonal for conflicts
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper-right diagonal for conflicts
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(int board[MAX_N][MAX_N], int row, int N) {
    // If all queens are placed, return true
    if (row == N) {
        return true;
    }

    // Try placing the queen in all columns for the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the next queen
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }

            // If placing queen in this column doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column, return false
    return false;
}

// Function to print the board
void printBoard(int board[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    int board[MAX_N][MAX_N] = {0};  // Initialize the board with 0 (no queen placed)

    // Call the function to solve the N-Queens problem
    if (solveNQueens(board, 0, N)) {
        printf("Solution for N-Queens Problem:\n");
        printBoard(board, N);
    } else {
        printf("Solution does not exist for N = %d\n", N);
    }

    return 0;
}

/*
Sample Input:
Enter the value of N: 4

Sample Output:
Solution for N-Queens Problem:
Q . . .
. . Q .
. Q . .
. . . Q
*/

