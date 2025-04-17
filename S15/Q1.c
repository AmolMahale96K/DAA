#include <stdio.h>
#include <stdlib.h>

// Structure to store an item
struct Item {
    int weight;
    int value;
};

// Structure to represent the node in the search tree
struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

// Function to calculate the bound for the node
float bound(struct Node u, int n, int W, struct Item items[]) {
    if (u.weight >= W) return 0;  // If weight exceeds capacity, no need to check

    float profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    // Include items as long as they fit in the knapsack
    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        profitBound += items[j].value;
        j++;
    }

    // If there are still items left, include part of the next item
    if (j < n) {
        profitBound += (W - totalWeight) * items[j].value / (float)items[j].weight;
    }

    return profitBound;
}

// Function to implement 0/1 Knapsack using LCBB
void knapsack(int n, int W, struct Item items[]) {
    // Sorting items by value/weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float ratio1 = (float)items[j].value / items[j].weight;
            float ratio2 = (float)items[j + 1].value / items[j + 1].weight;
            if (ratio1 < ratio2) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Initialize the root node
    struct Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = bound(u, n, W, items);

    // Priority queue to hold nodes to be explored (using simple array for simplicity)
    struct Node queue[100];
    int front = 0, rear = 0;

    // Enqueue root node
    queue[rear++] = u;

    int maxProfit = 0;
    while (front != rear) {
        u = queue[front++];
        
        // If we can achieve a better profit, update maxProfit
        if (u.level == n - 1) continue;  // Reached last level

        // Consider next item in the level
        v.level = u.level + 1;
        
        // Include the current item in the knapsack
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;

        // Check if it is promising and its weight doesn't exceed W
        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
        }

        // Calculate the bound of the next node
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit) {
            queue[rear++] = v;
        }

        // Exclude the current item from the knapsack (only update bound)
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit) {
            queue[rear++] = v;
        }
    }

    printf("Maximum profit in the knapsack: %d\n", maxProfit);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input the items' weights and values
    printf("Enter the weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Call the knapsack function
    knapsack(n, W, items);

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
