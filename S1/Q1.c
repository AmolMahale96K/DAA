#include <stdio.h>
#include <time.h>

/*
Sample Input/Output:

Input:
Enter the number of elements: 6
Enter 6 integers:
45 12 89 3 67 21

Output:
Sorted array in ascending order:
3 12 21 45 67 89
Time taken to sort: 0.000002 seconds
*/

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;
    clock_t start, end;
    double cpu_time_used;

    // Input: number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input: elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Start measuring time
    start = clock();

    // Perform sorting
    selectionSort(arr, n);

    // End measuring time
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output: sorted array
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Output: time taken
    printf("\nTime taken to sort: %f seconds\n", cpu_time_used);

    return 0;
}
