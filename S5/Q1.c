#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/*
Sample Input:
Enter number of vertices: 4
Enter number of edges: 5
Enter edges (format: vertex1 vertex2 weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Output:
Edge   Weight
0 - 3   5
2 - 3   4
0 - 1   10
Minimum cost = 19
*/

// Structure for an edge
struct Edge {
    int u, v, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges (used for sorting)
int compareEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Find function for union-find with path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union function for union-find (union by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Kruskal's algorithm to find MST
void kruskal(struct Edge edges[], int V, int E) {
    struct Subset subsets[V];
    struct Edge mst[MAX];
    int mstIndex = 0;
    int totalWeight = 0;

    // Initialize subsets for union-find
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Iterate through sorted edges and add them to the MST
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // Find the roots of the sets u and v belong to
        int rootU = find(subsets, u);
        int rootV = find(subsets, v);

        // If they are in different sets, include this edge in the MST
        if (rootU != rootV) {
            mst[mstIndex++] = edges[i];
            totalWeight += edges[i].weight;
            unionSets(subsets, rootU, rootV);
        }
    }

    // Print the MST and its total weight
    printf("Edge   Weight\n");
    for (int i = 0; i < mstIndex; i++) {
        printf("%d - %d   %d\n", mst[i].u, mst[i].v, mst[i].weight);
    }
    printf("Minimum cost = %d\n", totalWeight);
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter edges (format: vertex1 vertex2 weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(edges, V, E);

    return 0;
}
