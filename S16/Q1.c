#include <stdio.h>

#define MAX_ITEMS 100

// Function to solve 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int n, int weight[], int value[]) {
    int dp[n+1][W+1];  // dp[i][j] will hold the maximum value for i items and j capacity

    // Initialize the dp table to 0
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // No items or zero capacity
            } else if (weight[i-1] <= w) {
                // Either take the current item or don't take it
                dp[i][w] = (dp[i-1][w] > dp[i-1][w - weight[i-1]] + value[i-1]) ?
                            dp[i-1][w] :
                            dp[i-1][w - weight[i-1]] + value[i-1];
            } else {
                dp[i][w] = dp[i-1][w];  // Can't take the item if it exceeds current capacity
            }
        }
    }

    // The last cell will contain the maximum value that can be obtained
    return dp[n][W];
}

int main() {
    int n, W;

    // Input the number of items and knapsack capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    // Input the weight and value for each item
    printf("Enter the weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i+1);
        scanf("%d", &weight[i]);
        printf("Item %d - Value: ", i+1);
        scanf("%d", &value[i]);
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Call the knapsack function
    int maxValue = knapsack(W, n, weight, value);

    printf("Maximum profit in the knapsack: %d\n", maxValue);

    return 0;
}

/*
Sample Input:
Enter the number of items: 3
Enter the weight and value for each item:
Item 1 - Weight: 2
Item 1 - Value: 3
Item 2 - Weight: 3
Item 2 - Value: 4
Item 3 - Weight: 4
Item 3 - Value: 5
Enter the capacity of the knapsack: 5

Sample Output:
Maximum profit in the knapsack: 7
*/

