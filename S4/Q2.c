#include <stdio.h>

/*
Sample Input:
Enter number of items: 3
Enter capacity of knapsack: 50
Enter weight and profit of each item:
10 60
20 100
30 120

Output:
Maximum profit: 240.000000
*/

// Structure to hold item data
struct Item {
    int weight;
    int profit;
};

// Function to sort items by profit/weight ratio in descending order
void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            float r1 = (float)items[i].profit / items[i].weight;
            float r2 = (float)items[j].profit / items[j].weight;
            if (r1 < r2) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
}

// Function to calculate maximum profit using Greedy method
float knapsack(struct Item items[], int n, int capacity) {
    float totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += ((float)capacity / items[i].weight) * items[i].profit;
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];
    printf("Enter weight and profit of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }

    sortItems(items, n);
    float maxProfit = knapsack(items, n, capacity);

    printf("Maximum profit: %f\n", maxProfit);

    return 0;
}
