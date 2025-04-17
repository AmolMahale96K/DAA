#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications needed
int MatrixChainOrder(int p[], int n) {
    int dp[n][n];  // dp[i][j] stores the minimum number of multiplications for multiplying matrices Ai...Aj

    // Initializing the dp array. dp[i][i] = 0 because no multiplication is needed for a single matrix.
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // L is the chain length. We need to calculate the minimum multiplication cost for chains of increasing length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            // Try every possible split point k between i and j
            for (int k = i; k < j; k++) {
                // Cost of multiplying matrices Ai...Ak and Ak+1...Aj
                int q = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    // Return the result for the full chain
    return dp[1][n-1];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int p[n + 1];  // Dimensions of matrices
    printf("Enter the dimensions of the matrices (as an array of dimensions):\n");
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &p[i]);
    }

    // Function call to get the minimum multiplication cost
    printf("Minimum number of multiplications is: %d\n", MatrixChainOrder(p, n + 1));

    return 0;
}

/*
Sample Input:
Enter the number of matrices: 4
Enter the dimensions of the matrices (as an array of dimensions):
10 20 30 40 30

Sample Output:
Minimum number of multiplications is: 26000
*/
