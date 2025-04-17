#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to perform topological sorting
void topologicalSort(int graph[MAX][MAX], int V) {
    int inDegree[V];  // Array to store the in-degree of vertices
    for (int i = 0; i < V; i++) {
        inDegree[i] = 0;
    }

    // Calculate the in-degree (number of incoming edges) for each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0) {
                inDegree[j]++;
            }
        }
    }

    // Initialize a queue to store vertices with in-degree 0
    int queue[MAX], front = -1, rear = -1;
    
    // Add vertices with in-degree 0 to the queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    int count = 0;
    printf("Topological Sorting: ");
    
    // Process the vertices in the queue
    while (front < rear) {
        int u = queue[++front];
        printf("%d ", u);
        count++;

        // Decrease the in-degree of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queue[++rear] = v;
                }
            }
        }
    }

    // If count does not equal the number of vertices, there is a cycle in the graph
    if (count != V) {
        printf("\nThe graph contains a cycle, topological sorting is not possible.\n");
    } else {
        printf("\n");
    }
}

int main() {
    int V;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];

    // Input the adjacency matrix of the graph
    printf("Enter the adjacency matrix of the graph (0 for no path, non-zero for edge weight):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Call the topological sort function
    topologicalSort(graph, V);

    return 0;
}
