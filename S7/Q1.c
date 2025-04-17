#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the vertex with the minimum distance which is not yet visited
int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm for shortest path
void dijkstra(int graph[MAX][MAX], int V, int source) {
    int dist[V];  // The output array dist[i] will hold the shortest distance from source to i
    int sptSet[V];  // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance to the source is 0
    dist[source] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the vertex with the minimum distance value
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update the dist value of the adjacent vertices
        for (int v = 0; v < V; v++) {
            // Update dist[v] if the current vertex u is not in sptSet, there is an edge from u to v,
            // and the total weight of the path from source to v through u is less than the current value of dist[v]
            if (graph[u][v] && sptSet[v] == 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the computed shortest distances
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int V, source;

    // Input
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];

    printf("Enter the adjacency matrix of the graph (0 for no path, non-zero for edge weight):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    // Call the Dijkstra function
    dijkstra(graph, V, source);

    return 0;
}
