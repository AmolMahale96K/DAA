#include <stdio.h>
#include <stdbool.h>

#define MAX 10  // Maximum number of vertices

int graph[MAX][MAX], visited[MAX], n;

// Function to perform DFS traversal
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    // Recur for all adjacent vertices of the vertex
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, x, y;
    
    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the edges of the graph
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (x, y) format (0-based index):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;  // Since it's an undirected graph
    }

    // Perform DFS starting from vertex 0
    printf("DFS Traversal starting from vertex 0:\n");
    DFS(0);

    return 0;
}

/*
Sample Input:
Enter the number of vertices: 5
Enter the number of edges: 4
Enter the edges (x, y) format (0-based index):
0 1
0 2
1 3
1 4

Sample Output:
DFS Traversal starting from vertex 0:
0 1 3 4 2
*/
