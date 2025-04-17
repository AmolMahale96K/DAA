#include <stdio.h>

#define MAX_VERTICES 10

// Function to check if it is safe to color a vertex with a given color
int isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int vertex, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && color[i] == c) {
            return 0;  // Not safe if adjacent vertex has the same color
        }
    }
    return 1;
}

// Function to solve the graph coloring problem
int graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int vertex, int n) {
    // If all vertices are assigned a color, return true
    if (vertex == n) {
        return 1;
    }

    // Try different colors for the vertex
    for (int c = 1; c <= m; c++) {
        // Check if this color can be assigned to vertex
        if (isSafe(graph, color, vertex, c, n)) {
            color[vertex] = c;  // Assign color

            // Recur to assign colors to the rest of the vertices
            if (graphColoring(graph, m, color, vertex + 1, n)) {
                return 1;
            }

            // If assigning color c doesn't lead to a solution, backtrack
            color[vertex] = 0;
        }
    }

    return 0;
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int color[MAX_VERTICES] = {0};  // Array to store colors of vertices
    int n = 5;  // Number of vertices
    int m = 3;  // Number of colors

    if (graphColoring(graph, m, color, 0, n)) {
        printf("Graph coloring solution:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d: Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}

/*
Sample Input/Output:

Graph coloring solution:
Vertex 1: Color 1
Vertex 2: Color 2
Vertex 3: Color 3
Vertex 4: Color 2
Vertex 5: Color 3
*/
