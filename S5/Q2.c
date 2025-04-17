#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

/*
Sample Input:
Enter the number of characters: 4
Enter the characters and their frequencies:
A 5
B 9
C 12
D 13

Output:
Character: A, Code: 1100
Character: B, Code: 111
Character: C, Code: 10
Character: D, Code: 0
*/

// Structure for a node in the Huffman tree
struct MinHeapNode {
    char data;        // Character
    int freq;         // Frequency of the character
    struct MinHeapNode *left, *right;
};

// Structure for the Min Heap
struct MinHeap {
    int size;           // Current size of the heap
    int capacity;       // Maximum possible size of the heap
    struct MinHeapNode **array;
};

// Create a new node
struct MinHeapNode* newNode(char data, int freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Create a Min Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heapify: Ensure the heap property is maintained
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the size of the heap is one
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract the node with the minimum frequency
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node to the Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Build the Min Heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Print the Huffman codes
void printCodes(struct MinHeapNode* root, int arr[], int top) {
    // If the current node is a leaf node, print the data and the code
    if (root->left == NULL && root->right == NULL) {
        printf("Character: %c, Code: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
        return;
    }

    // Traverse the left and right subtrees and assign 0 or 1 to the current bit
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);

    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
}

// Build the Huffman Tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);

    // Insert all characters and frequencies into the min heap
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);

    // Build the Huffman Tree
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

int main() {
    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);

    char data[n];
    int freq[n];

    printf("Enter the characters and their frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &data[i]);
        scanf("%d", &freq[i]);
    }

    struct MinHeapNode* root = buildHuffmanTree(data, freq, n);

    // Array to store Huffman codes
    int arr[MAX_TREE_HT], top = 0;

    printf("\nHuffman Codes for the characters are:\n");
    printCodes(root, arr, top);

    return 0;
}
