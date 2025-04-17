#include <stdio.h>
#include <limits.h>

#define MAX 20

/*
Sample Input:
Enter number of vertices: 5
Enter the graph's adjacency matrix:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Output:
Edge   Weight
0 - 1   2
1 - 2   3
0 - 3   6
1 - 4   5
Minimum cost = 16
*/

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm
void primMST(int graph[MAX][MAX], int V) {
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Key values used to pick the minimum weight edge
    int mstSet[V];  // To represent the set of vertices included in MST

    // Initialize key values to infinity and mstSet[] to false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start with the first vertex
    key[0] = 0;  // Make key of the first vertex 0
    parent[0] = -1;  // First node is the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet processed
        int u = minKey(key, mstSet, V);
        
        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update the key values and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update key[v] only if graph[u][v] is smaller than key[v] and v is not in mstSet
            if (graph[u][v] != 0 && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    printf("Edge   Weight\n");
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d   %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }

    printf("Minimum cost = %d\n", totalWeight);
}

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];

    printf("Enter the graph's adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);

    return 0;
}
