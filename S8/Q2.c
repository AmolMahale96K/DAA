#include <stdio.h>
#include <limits.h>

#define MAX 10

// Function to calculate the distance between two cities
int distance(int city1, int city2, int dist[MAX][MAX]) {
    return dist[city1][city2];
}

// Function to find the minimum cost of the tour using the nearest neighbor algorithm
void nearestNeighbor(int dist[MAX][MAX], int n) {
    int visited[MAX] = {0};  // Array to track visited cities
    int totalDistance = 0;   // To store total distance of the tour
    int currentCity = 0;     // Start from the first city
    visited[currentCity] = 1; // Mark the starting city as visited

    printf("Tour: %d ", currentCity); // Print the starting city

    // Loop through all the cities
    for (int i = 1; i < n; i++) {
        int nearestCity = -1;
        int minDist = INT_MAX;

        // Find the nearest unvisited city
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[currentCity][j] < minDist) {
                nearestCity = j;
                minDist = dist[currentCity][j];
            }
        }

        // Add the distance of the nearest city to the total distance
        totalDistance += minDist;

        // Mark the nearest city as visited and move to the city
        visited[nearestCity] = 1;
        currentCity = nearestCity;

        // Print the city visited
        printf("-> %d ", currentCity);
    }

    // Add the distance to return to the starting city
    totalDistance += dist[currentCity][0];
    printf("-> %d\n", 0); // Print the return to starting city
    printf("Total distance: %d\n", totalDistance); // Print the total distance
}

int main() {
    int dist[MAX][MAX], n;

    // Input the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input the distance matrix
    printf("Enter the distance matrix (distances between each pair of cities):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Call the nearest neighbor function to solve TSP
    nearestNeighbor(dist, n);

    return 0;
}

/*
Sample Input:
Enter the number of cities: 4
Enter the distance matrix (distances between each pair of cities):
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

Sample Output:
Tour: 0 -> 1 -> 3 -> 2 -> 0
Total distance: 80
*/
