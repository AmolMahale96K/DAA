#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Function to check if the current vertex can be added to the Hamiltonian cycle
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos, int v) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos-1]][v] == 0) return false;

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }

    return true;
}

// Function to solve the Hamiltonian cycle problem using backtracking
bool hamiltonianCycleUtil(int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos, int n) {
    // If all vertices are included in the cycle
    if (pos == n) {
        // Check if the last vertex is connected to the first vertex
        if (graph[path[pos-1]][path[0]] == 1) {
            return true;
        }
        return false;
    }

    // Try different vertices as the next candidate in the Hamiltonian cycle
    for (int v = 1; v < n; v++) {
        if (isSafe(graph, path, pos, v)) {
            path[pos] = v;

            // Recur to check if this leads to a solution
            if (hamiltonianCycleUtil(graph, path, pos+1, n)) {
                return true;
            }

            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }

    return false;
}

// Function to solve the Hamiltonian cycle problem
bool hamiltonianCycle(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int path[n];

    // Initialize the path as -1, meaning no vertices are included in the path yet
    for (int i = 0; i < n; i++) {
        path[i] = -1;
    }

    // Start with the first vertex in the path
    path[0] = 0;

    // Call the utility function to check if a Hamiltonian cycle exists
    if (hamiltonianCycleUtil(graph, path, 1, n) == false) {
        return false;
    }

    // Print the Hamiltonian cycle
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return true;
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0}
    };
    
    int n = 4;  // Number of vertices

    // Call the function to check if the graph has a Hamiltonian cycle
    if (hamiltonianCycle(graph, n) == false) {
        printf("No Hamiltonian Cycle exists.\n");
    }

    return 0;
}

/*
Sample Input:
Graph adjacency matrix:
0 1 0 1
1 0 1 1
0 1 0 1
1 1 1 0

Sample Output:
Hamiltonian Cycle: 0 1 2 3
*/

