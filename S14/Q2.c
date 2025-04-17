#include <stdio.h>
#include <stdlib.h>

// Structure for a graph node
struct Node {
    int data;
    struct Node* next;
};

// Structure for a graph
struct Graph {
    int vertices;
    struct Node** adjLists;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    
    // Initialize adjacency lists
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS recursive function
void DFS(struct Graph* graph, int vertex, int visited[]) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;
    while (temp != NULL) {
        int connectedVertex = temp->data;
        if (!visited[connectedVertex]) {
            DFS(graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

// BFS function
void BFS(struct Graph* graph, int startVertex) {
    int visited[graph->vertices];
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = 0;
    }
    
    int queue[graph->vertices];
    int front = -1, rear = -1;
    
    // Enqueue the start vertex
    queue[++rear] = startVertex;
    visited[startVertex] = 1;
    
    while (front != rear) {
        // Dequeue
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);
        
        // Visit all neighbors
        struct Node* adjList = graph->adjLists[currentVertex];
        struct Node* temp = adjList;
        while (temp != NULL) {
            int connectedVertex = temp->data;
            if (!visited[connectedVertex]) {
                queue[++rear] = connectedVertex;
                visited[connectedVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    
    // DFS
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    
    printf("DFS starting from vertex 0: ");
    DFS(graph, 0, visited);
    printf("\n");
    
    // BFS
    printf("BFS starting from vertex 0: ");
    BFS(graph, 0);
    printf("\n");
    
    return 0;
}

/*
Sample Input/Output:

DFS starting from vertex 0: 0 1 2 3 4
BFS starting from vertex 0: 0 1 4 2 3
*/
