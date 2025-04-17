#include <stdio.h>
#include <time.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];  // The element to be inserted in the sorted portion
        j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Insert the key at the correct position
        arr[j + 1] = key;
    }
}

int main() {
    int n;

    // Taking input for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    
    // Taking input for the elements of the array
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Record the start time
    clock_t start_time = clock();

    // Call the insertionSort function to sort the array
    insertionSort(arr, n);

    // Record the end time
    clock_t end_time = clock();
    
    // Calculate the time taken for sorting
    double time_taken = ((double)end_time - start_time) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the time taken to sort the elements
    printf("Time taken to sort the array: %f seconds\n", time_taken);

    return 0;
}

/*
Sample Input:
Enter the number of elements: 5
Enter the elements:
12 11 13 5 6

Sample Output:
Sorted array: 5 6 11 12 13
Time taken to sort the array: 0.000032 seconds
*/
