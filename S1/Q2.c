#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Sample Input/Output:

Input:
Enter number of elements: 5

Generated Array:
78 12 45 23 9

Sorted Array:
9 12 23 45 78

Time taken to sort: 0.000002 seconds
*/

// Function to swap two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    srand(time(NULL));

    printf("Generated Array:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");

    clock_t start = clock();
    quickSort(a, 0, n - 1);
    clock_t end = clock();

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to sort: %f seconds\n", time_taken);

    return 0;
}
