#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to print the subset that sums to the target
void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Backtracking function to find the subsets
void sumOfSubset(int set[], int n, int target, int index, int subset[], int subsetSize) {
    // If the target is reached, print the subset
    if (target == 0) {
        printSubset(subset, subsetSize);
        return;
    }
    // If we have no more elements to consider, return
    if (index == n) {
        return;
    }

    // Include the current element in the subset and explore further
    subset[subsetSize] = set[index];
    sumOfSubset(set, n, target - set[index], index + 1, subset, subsetSize + 1);

    // Exclude the current element from the subset and explore further
    sumOfSubset(set, n, target, index + 1, subset, subsetSize);
}

int main() {
    int n, target;
    int set[MAX], subset[MAX];

    // Input the number of elements in the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    // Input the elements of the set
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Call the function to find the subsets
    printf("Subsets with the given sum are:\n");
    sumOfSubset(set, n, target, 0, subset, 0);

    return 0;
}

/*
Sample Input:
Enter the number of elements in the set: 5
Enter the elements of the set:
3 34 4 12 5
Enter the target sum: 9

Sample Output:
Subsets with the given sum are:
{ 3 4 5 }
{ 4 5 }
*/
