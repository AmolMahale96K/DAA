#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX], n;

// Queue implementation for BFS
int queue[MAX], front = -1, rear = -1;

// Enqueue operation
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("\nQueue is Full\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = vertex;
    }
}

// Dequeue operation
int dequeue() {
    if (front == -1) {
        printf("\nQueue is Empty\n");
        return -1;
    } else {
        int element = queue[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return element;
    }
}

// Function to perform BFS traversal
void BFS(int start) {
    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        int vertex = dequeue();
        printf("%d ", vertex);

        // Visit all unvisited adjacent vertices
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, x, y;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the number of edges and the edges themselves
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (x, y) format (0-based index):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1; // For undirected graph
    }

    // Perform BFS starting from vertex 0
    printf("BFS Traversal starting from vertex 0:\n");
    BFS(0);

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
BFS Traversal starting from vertex 0:
0 1 2 3 4
*/
