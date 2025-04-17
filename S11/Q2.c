#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

int graph[MAX][MAX], dist[MAX], prev[MAX], visited[MAX], n;

// Function to find the vertex with the smallest tentative distance
int minDistance() {
    int min = INF, min_index;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (visited[v] == 0 && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

// Function to print the shortest path from source to vertex
void printPath(int j) {
    if (prev[j] == -1) {
        return;
    }
    printPath(prev[j]);
    printf("%d ", j);
}

int main() {
    int edges, x, y, weight, start;

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize graph with 0s (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (x, y, weight) format (0-based index):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &x, &y, &weight);
        graph[x][y] = weight;
        graph[y][x] = weight; // For undirected graph
    }

    // Input the starting vertex
    printf("Enter the source vertex: ");
    scanf("%d", &start);

    // Run Dijkstra's algorithm
    dijkstra(start);

    // Output the shortest paths and distances
    printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < n; i++) {
        printf("Distance to vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}

/*
Sample Input:
Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges (x, y, weight) format (0-based index):
0 1 10
0 2 5
1 2 2
1 3 1
2 3 9
3 4 4
Enter the source vertex: 0

Sample Output:
Shortest distances from vertex 0:
Distance to vertex 0: 0
Distance to vertex 1: 8
Distance to vertex 2: 5
Distance to vertex 3: 9
Distance to vertex 4: 13
*/
