#include <stdio.h>
#include <stdlib.h>
struct node {        // Define a structure for a node in a binary tree
    char data;            // Character data of the node
    unsigned freq;        // Integer frequency of the character
    struct node *left, *right;  // Pointers pointing to left and right children nodes
};
// Define a structure for a minimum heap
struct minheap {
    unsigned size;        // Current size of the heap
    unsigned capacity;    // Capacity of the heap
    struct node **array;  // Array of pointers pointing towards nodes
};
struct node *newnode(char data, unsigned freq) {       // Create and return a new node with the given character and frequency
    struct node *temp = malloc(sizeof(struct node));   // Allocating memory to a node temp of size of structure node
    temp->left = temp->right = NULL;   // Initializing left node address and right node address of the temp node as null
    temp->data = data;   // Inserting data in the node
    temp->freq = freq;   // Inserting frequency in the node
    return temp;
}
struct minheap *createheap(unsigned capacity) {        // Create and return a new minimum heap with the given capacity
    struct minheap *min = malloc(sizeof(struct minheap));   // Allocating memory to min of size of structure minheap
    min->size = 0;   // Make size of min as 0
    min->capacity = capacity;   // Inserting capacity as capacity of min
    min->array = malloc((min->capacity) * sizeof(struct node));   // Allocating memory to array of nodes in min of size of structure node multiply by capacity of min
    return min;
}
void swapnode(struct node **a, struct node **b) {   // Swap two node pointers
    struct node *temp = *a;
    *a = *b;
    *b = temp;
}
void minheapify(struct minheap *min, int idx) {   // Maintain the min-heap property by recursively fixing the heap starting from the given index
    int minimum = idx, left = 2 * idx + 1, right = 2 * idx + 2;   // Initialize variables for the current node, left child, and right child indices
    if (left < min->size && min->array[left]->freq < min->array[minimum]->freq) {    // If the left child exists and has a smaller frequency than the current minimum node
        minimum = left;   // Update the minimum index as left
    }
    if (right < min->size && min->array[right]->freq < min->array[minimum]->freq) {   // If the right child exists and has a smaller frequency than the current minimum node
        minimum = right;   // Update the minimum index as right
    }
    if (minimum != idx) {   // If the minimum index is not the current index, swap nodes to maintain the min-heap property
        swapnode(&min->array[minimum], &min->array[idx]);
        minheapify(min, minimum);   // Recursively call minheapify on the swapped index
    }
}
struct node *extractmin(struct minheap *min) {   // Extract the minimum node from the heap
    struct node *temp = min->array[0];   // Store the node at the root (minimum) of the heap in temp
    min->array[0] = min->array[min->size - 1];   // Replace the root with the last node in the heap
    min->size--;   // Decrement the size of the heap
    minheapify(min, 0);   // Restore the min-heap property starting from the root
    return temp;   // Return the extracted minimum node, stored in temp
}
void insertheap(struct minheap *min, struct node *minnode) {   // Insert a node into the heap and maintain the min heap property
    min->size++;   // Increment the size of the heap
    int i = min->size - 1;   // Set i to the index of the new node
    while (i && minnode->freq < min->array[(i - 1) / 2]->freq) {   // While the new node has a smaller frequency than its parent
        min->array[i] = min->array[(i - 1) / 2];   // Move the parent down or copy it to the last array
        i = (i - 1) / 2;   // Move to the parent's index
    }
    min->array[i] = minnode;   // Place the new node in the correct position after applying the loop
}
// Build a heap from the given minheap
void buildheap(struct minheap *min) {
    int n = min->size - 1, i;
    for (i = (n - 1) / 2; i >= 0; i--) {
        minheapify(min, i);
    }
}

// Print the array of codes
void printarr(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// Create a heap from given character and frequency arrays, and build the heap
struct minheap *createbuildheap(char data[], int freq[], int size) {
    struct minheap *min = createheap(size);
    int i;
    for (i = 0; i < size; i++) {
        min->array[i] = newnode(data[i], freq[i]);
    }
    min->size = size;
    buildheap(min);
    return min;
}

// Build the Huffman tree and return the root node
struct node *huffman(char data[], int freq[], int size) {
    struct node *left, *top, *right;
    struct minheap *min = createbuildheap(data, freq, size);
    while (min->size != 1) {
        left = extractmin(min);
        right = extractmin(min);
        top = newnode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertheap(min, top);
    }
    return extractmin(min);
}

// Recursively print the Huffman codes
void printcodes(struct node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printcodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printcodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c ", root->data);
        printarr(arr, top);
    }
}

// Generate and print Huffman codes for the given character and frequency arrays
void huffmancodes(char data[], int freq[], int size) {
    struct node *root = huffman(data, freq, size);
    int arr[size], top = 0;
    printcodes(root, arr, top);
}

// Main function
int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    huffmancodes(arr, freq, size);
    return 0;
}
