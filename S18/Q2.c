#include <stdio.h>

#define MAX_VERTICES 100

// Function to classify nodes in the graph
void classifyNodes(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int liveNodes = 0, deadNodes = 0, eNodes = 0;

    // Iterate over all vertices to classify them
    for (int i = 0; i < V; i++) {
        int hasOutgoing = 0, hasIncoming = 0;
        
        // Check for outgoing edges (Live node check)
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                hasOutgoing = 1;  // Found an outgoing edge
                break;
            }
        }
        
        // Check for incoming edges (Dead node check)
        for (int j = 0; j < V; j++) {
            if (graph[j][i] == 1) {
                hasIncoming = 1;  // Found an incoming edge
                break;
            }
        }

        // Classify the node
        if (hasOutgoing && hasIncoming) {
            liveNodes++;  // Node has both incoming and outgoing edges
        } else if (hasOutgoing == 0 && hasIncoming == 0) {
            eNodes++;  // Node has no incoming or outgoing edges
        } else {
            deadNodes++;  // Node has no outgoing edges
        }
    }

    printf("Live Nodes: %d\n", liveNodes);
    printf("Dead Nodes: %d\n", deadNodes);
    printf("E Nodes: %d\n", eNodes);
}

int main() {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix of the graph (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Call the function to classify the nodes
    classifyNodes(graph, V);

    return 0;
}

/*
Sample Input:
Enter the number of vertices: 4
Enter the adjacency matrix of the graph (1 for edge, 0 for no edge):
0 1 1 0
0 0 0 1
0 0 0 0
1 0 1 0

Sample Output:
Live Nodes: 3
Dead Nodes: 1
E Nodes: 0
*/

