#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/*
Sample Input:
Enter number of vertices: 5
Enter the adjacency matrix:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Output:
Edge  Weight
0 - 1     2
1 - 2     3
0 - 3     6
1 - 4     5
Minimum cost = 16
*/

// Find the vertex with minimum key value from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Print the constructed MST stored in parent[]
void printMST(int parent[], int graph[10][10], int V) {
    int totalCost = 0;
    printf("Edge  Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d     %d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Minimum cost = %d\n", totalCost);
}

// Function to construct MST using Prim's algorithm
void primMST(int graph[10][10], int V) {
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values to pick minimum weight edge
    bool mstSet[V];  // To represent set of vertices included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;      // Start from the first vertex
    parent[0] = -1;  // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V); // Pick the min key vertex
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int graph[10][10], V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, V);

    return 0;
}
