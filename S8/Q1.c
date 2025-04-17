#include <stdio.h>

// Structure to store item data (weight and value)
struct Item {
    int weight;
    int value;
    float ratio;  // Value-to-weight ratio
};

// Function to compare two items based on value-to-weight ratio
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item*)a;
    struct Item *item2 = (struct Item*)b;
    
    if (item1->ratio < item2->ratio) return 1;
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}

// Function to solve the Fractional Knapsack problem using Greedy method
float fractionalKnapsack(int W, struct Item items[], int n) {
    // Sort items based on value-to-weight ratio in decreasing order
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    
    qsort(items, n, sizeof(items[0]), compare);  // Sort items by ratio
    
    float totalValue = 0.0;  // Total value of knapsack
    int remainingWeight = W; // Remaining capacity of knapsack
    
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingWeight) {
            // Take the whole item
            remainingWeight -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fraction of the item
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;  // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int W, n;
    
    // Input the number of items and the capacity of the knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    struct Item items[n];

    // Input the weight and value for each item
    printf("Enter the weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    // Call the function to solve the fractional knapsack problem
    float maxValue = fractionalKnapsack(W, items, n);

    // Output the maximum value that can be obtained
    printf("The maximum value that can be obtained is: %.2f\n", maxValue);

    return 0;
}

/*
Sample Input:
Enter the number of items: 4
Enter the capacity of the knapsack: 50
Enter the weight and value for each item:
Item 1: 10 60
Item 2: 20 100
Item 3: 30 120
Item 4: 40 200

Sample Output:
The maximum value that can be obtained is: 240.00
*/
