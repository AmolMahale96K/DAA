#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of probabilities from i to j
int sum(int prob[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += prob[k];
    }
    return s;
}

// Function to construct the optimal binary search tree using dynamic programming
void optimalBST(int keys[], int prob[], int n) {
    int cost[n][n];  // Table to store the minimum cost
    int root[n][n];  // Table to store the root of the optimal subtree
    int i, j, k, l;

    // Initialize the diagonal (base case when there is only one key)
    for (i = 0; i < n; i++) {
        cost[i][i] = prob[i];
        root[i][i] = i;
    }

    // Fill the table for larger subproblems
    for (l = 2; l <= n; l++) {  // l is the length of the subproblem
        for (i = 0; i <= n - l; i++) {
            j = i + l - 1;  // j is the end of the subproblem
            cost[i][j] = INT_MAX;  // Initialize cost to a large value

            // Try all possible roots for the current subproblem
            for (k = i; k <= j; k++) {
                // Calculate the cost of the subproblem with root k
                int c = (k > i ? cost[i][k - 1] : 0) + 
                        (k < j ? cost[k + 1][j] : 0) + 
                        sum(prob, i, j);

                // Update the cost and root if we find a better solution
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = k;
                }
            }
        }
    }

    // Output the optimal cost
    printf("Optimal cost of the Binary Search Tree: %d\n", cost[0][n - 1]);

    // Print the root of the optimal BST
    printf("Root of the optimal binary search tree is at index %d\n", root[0][n - 1]);

    // Function to print the tree structure (optional for clarity)
    printf("\nOptimal Binary Search Tree Structure (recursive root construction):\n");
    printTree(root, 0, n - 1, keys);
}

// Recursive function to print the structure of the tree
void printTree(int root[][n], int i, int j, int keys[]) {
    if (i <= j) {
        int r = root[i][j];
        printf("Root: %d (Key: %d)\n", r, keys[r]);
        printTree(root, i, r - 1, keys);
        printTree(root, r + 1, j, keys);
    }
}

int main() {
    int n;

    // Input the number of keys
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], prob[n];

    // Input the keys and their probabilities
    printf("Enter the keys and their probabilities:\n");
    for (int i = 0; i < n; i++) {
        printf("Key %d: ", i + 1);
        scanf("%d", &keys[i]);
        printf("Probability of Key %d: ", i + 1);
        scanf("%d", &prob[i]);
    }

    // Call the optimalBST function to compute the optimal BST
    optimalBST(keys, prob, n);

    return 0;
}

/*
Sample Input:
Enter the number of keys: 3
Enter the keys and their probabilities:
Key 1: 10
Probability of Key 1: 30
Key 2: 20
Probability of Key 2: 40
Key 3: 30
Probability of Key 3: 30

Sample Output:
Optimal cost of the Binary Search Tree: 100
Root of the optimal binary search tree is at index 1
Optimal Binary Search Tree Structure (recursive root construction):
Root: 1 (Key: 20)
Root: 0 (Key: 10)
Root: 2 (Key: 30)
*/
