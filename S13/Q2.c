#include <stdio.h>
#include <limits.h>

// Function to calculate optimal binary search tree cost
void optimalBST(int keys[], int freq[], int n) {
    int e[n+1][n+1], w[n+1][n+1], root[n+1][n+1];

    // Initialize the e and w tables
    for (int i = 0; i <= n; i++) {
        e[i][i] = 0;
        w[i][i] = 0;
    }

    // Fill tables for length of chain 1 to n
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j-1] + freq[j-1];
            
            // Try all possible roots
            for (int r = i; r <= j; r++) {
                int cost = e[i][r-1] + e[r+1][j] + w[i][j];
                if (cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    // Output the minimum search cost
    printf("Minimum cost of constructing optimal BST: %d\n", e[1][n]);
}

// Driver program
int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }
    
    printf("Enter the frequency of each key:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }
    
    optimalBST(keys, freq, n);
    
    return 0;
}

/*
Sample Input:
Enter the number of keys: 4
Enter the keys:
10 12 20 30
Enter the frequency of each key:
34 8 50 2

Sample Output:
Minimum cost of constructing optimal BST: 208
*/
