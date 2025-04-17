#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Declare the graph as an adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int topoOrder[MAX_VERTICES]; // To store the topological order
int index = 0; // Used to store the position in topoOrder

// Function to perform DFS and fill the topological order
void dfs(int vertex, int V) {
    visited[vertex] = 1;

    // Visit all the adjacent vertices of the current vertex
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i, V);
        }
    }

    // Push the vertex to the topological order after exploring all its neighbors
    topoOrder[index++] = vertex;
}

// Function to perform topological sorting
void topologicalSort(int V) {
    // Initialize the visited array
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Perform DFS on all unvisited vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V);
        }
    }

    // Print the topological order in reverse order (since DFS finishes nodes last)
    printf("Topological Sort: ");
    for (int i = V - 1; i >= 0; i--) {
        printf("%d ", topoOrder[i]);
    }
    printf("\n");
}

int main() {
    int V, E;
    
    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    // Input the adjacency matrix
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Perform topological sorting
    topologicalSort(V);
    
    return 0;
}

/*
Sample Input:
Enter the number of vertices: 6
Enter the number of edges: 6
Enter the adjacency matrix (0 for no edge, 1 for edge):
0 1 0 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 0 0 1
0 0 0 0 0 0

Sample Output:
Topological Sort: 5 4 3 2 1 0 
*/
