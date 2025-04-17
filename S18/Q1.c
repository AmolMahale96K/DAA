#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to check if it's safe to assign color to vertex v
bool isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c, int V) {
    for (int i = 0; i < V; i++) {
        // If there is an edge and the adjacent vertex has the same color
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Function to solve the graph coloring problem using greedy method
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int V, int m, int v) {
    // If all vertices are assigned a color, return true
    if (v == V) {
        return true;
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if it's safe to assign color c to vertex v
        if (isSafe(graph, color, v, c, V)) {
            color[v] = c;  // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoring(graph, color, V, m, v + 1)) {
                return true;
            }

            // Backtrack if assigning color c doesn't lead to a solution
            color[v] = 0;
        }
    }

    return false;  // If no color can be assigned, return false
}

// Function to print the solution
void printSolution(int color[], int V) {
    printf("Solution: \n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d --> Color %d\n", i + 1, color[i]);
    }
}

int main() {
    int V, m;
    int graph[MAX_VERTICES][MAX_VERTICES], color[MAX_VERTICES] = {0};

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printf("Enter the adjacency matrix of the graph (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Try to color the graph with m colors
    if (graphColoring(graph, color, V, m, 0)) {
        printSolution(color, V);
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}

/*
Sample Input:
Enter the number of vertices: 4
Enter the number of colors: 3
Enter the adjacency matrix of the graph (1 for edge, 0 for no edge):
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0

Sample Output:
Solution:
Vertex 1 --> Color 1
Vertex 2 --> Color 2
Vertex 3 --> Color 3
Vertex 4 --> Color 2
*/

