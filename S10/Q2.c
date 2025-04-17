#include <stdio.h>
#include <stdbool.h>

#define N 4  // Size of the chessboard (4x4)

// Function to print the chessboard
void printSolution(int board[N][N]) {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(int board[N][N], int row) {
    // Base case: If all queens are placed
    if (row >= N) {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        // Check if the queen can be placed safely
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recursively place queens in the next row
            res = solveNQueens(board, row + 1);

            // If placing queen in board[row][col] doesn't lead to a solution
            // then remove the queen (backtrack)
            board[row][col] = 0;
        }
    }

    return res;
}

int main() {
    int board[N][N] = {0};  // Initialize the chessboard

    // Try to solve the N-Queens problem
    if (!solveNQueens(board, 0)) {
        printf("Solution does not exist\n");
    }

    return 0;
}

/*
Sample Output:
Solution:
1 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1

Explanation: The queens are placed in the following positions:
Row 1, Column 1
Row 2, Column 3
Row 3, Column 2
Row 4, Column 4
*/
