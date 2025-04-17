#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to check if it's safe to add vertex v to the Hamiltonian cycle
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos, int v, int V) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    // Check if this vertex has already been included in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

// Function to solve the Hamiltonian Cycle problem using backtracking
bool hamCycleUtil(int graph[MAX_VERTICES][MAX_VERTICES], int path[], int V, int pos) {
    // If all vertices are included in the cycle, check if there is an edge from
    // the last vertex to the first vertex
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        }
        return false;
    }

    // Try different vertices as the next candidate in the cycle
    for (int v = 1; v < V; v++) {
        if (isSafe(graph, path, pos, v, V)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, V, pos + 1)) {
                return true;
            }

            // Backtrack if adding vertex v doesn't lead to a solution
            path[pos] = -1;
        }
    }

    return false;
}

// Function to check if there is a Hamiltonian Cycle in the graph
bool hamCycle(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }

    // Starting point of the cycle
    path[0] = 0;

    // Try to find the Hamiltonian cycle
    if (hamCycleUtil(graph, path, V, 1)) {
        // Print the Hamiltonian cycle
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < V; i++) {
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]);
        return true;
    }

    printf("No Hamiltonian Cycle found.\n");
    return false;
}

int main() {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix of the graph (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Check if a Hamiltonian Cycle exists
    hamCycle(graph, V);

    return 0;
}

/*
Sample Input:
Enter the number of vertices: 5
Enter the adjacency matrix of the graph (1 for edge, 0 for no edge):
0 1 0 1 0
1 0 1 1 0
0 1 0 1 1
1 1 1 0 1
0 0 1 1 0

Sample Output:
Hamiltonian Cycle: 0 1 2 4 3 0
*/
