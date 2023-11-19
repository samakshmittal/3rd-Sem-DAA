#include <stdio.h>
#include <stdlib.h>
struct node {                                                       // Define a structure for a node in a binary tree
    char data;                                                      // Character data of the node
    unsigned freq;                                                  // Integer frequency of the character
    struct node *left, *right;                                      // Pointers pointing to left and right children nodes
};
struct minheap {                                                    // Define a structure for a minimum heap
    unsigned size;                                                  // Current size of the heap
    unsigned capacity;                                              // Capacity of the heap
    struct node **array;                                            // Array of pointers pointing towards nodes
};
struct node *newnode(char data, unsigned freq) {                    // Create and return a new node with the given character and frequency
    struct node *temp = malloc(sizeof(struct node));                // Allocating memory to a node temp of size of structure node
    temp->left = temp->right = NULL;                                // Initializing left node address and right node address of the temp node as null
    temp->data = data;                                              // Inserting data in the node
    temp->freq = freq;                                              // Inserting frequency in the node
    return temp;
}
struct minheap *createheap(unsigned capacity) {                     // Create and return a new minimum heap with the given capacity
    struct minheap *min = malloc(sizeof(struct minheap));           // Allocating memory to min of size of structure minheap
    min->size = 0;                                                  // Make size of min as 0
    min->capacity = capacity;                                       // Inserting capacity as capacity of min
    min->array = malloc((min->capacity) * sizeof(struct node));     // Allocating memory to array of nodes in min of size of structure node multiply by capacity of min
    return min;
}
void swapnode(struct node **a, struct node **b) {                   // Swap two node pointers
    struct node *temp = *a;
    *a = *b;
    *b = temp;
}
void minheapify(struct minheap *min, int idx) {                     // Maintain the min-heap property by recursively fixing the heap starting from the given index
    int minimum = idx, left = 2 * idx + 1, right = 2 * idx + 2;     // Initialize variables for the current node, left child, and right child indices
    if (left < min->size && min->array[left]->freq < min->array[minimum]->freq) {    // If the left child exists and has a smaller frequency than the current minimum node
        minimum = left;                                             // Update the minimum index as left
    }
    if (right < min->size && min->array[right]->freq < min->array[minimum]->freq) {   // If the right child exists and has a smaller frequency than the current minimum node
        minimum = right;                                            // Update the minimum index as right
    }
    if (minimum != idx) {                                           // If the minimum index is not the current index, swap nodes to maintain the min-heap property
        swapnode(&min->array[minimum], &min->array[idx]);
        minheapify(min, minimum);                                   // Recursively call minheapify on the swapped index
    }
}
struct node *extractmin(struct minheap *min) {                      // Extract the minimum node from the heap
    struct node *temp = min->array[0];                              // Store the node at the root (minimum) of the heap in temp
    min->array[0] = min->array[min->size - 1];                      // Replace the root with the last node in the heap
    min->size--;                                                    // Decrement the size of the heap
    minheapify(min, 0);                                             // Restore the min-heap property starting from the root
    return temp;                                                    // Return the extracted minimum node, stored in temp
}
void insertheap(struct minheap *min, struct node *minnode) {        // Insert a node into the heap and maintain the min heap property
    min->size++;                                                    // Increment the size of the heap
    int i = min->size - 1;                                          // Set i to the index of the new node
    while (i && minnode->freq < min->array[(i - 1) / 2]->freq) {    // While the new node has a smaller frequency than its parent
        min->array[i] = min->array[(i - 1) / 2];                    // Move the parent down or copy it to the last array
        i = (i - 1) / 2;                                            // Move to the parent's index
    }
    min->array[i] = minnode;                                        // Place the new node in the correct position after applying the loop
}
void buildheap(struct minheap *min) {                               // Build a heap from the given minheap
    int n = min->size - 1, i;                                       // Set n to the last index of the heap
    for (i = (n - 1) / 2; i >= 0; i--) {                            // Maintain loop from the last non-leaf node to the root
        minheapify(min, i);                                         // Call minheapify to maintain the min-heap property
    }
}
void printarr(int arr[], int n) {                                   // Print the array of codes
    int i;                                                          // Initialization
    for (i = 0; i < n; i++) {                                       // Maintaining loop for printing the array
        printf("%d", arr[i]);                                       // Printing array
    }
    printf("\n");
}
struct minheap *createbuildheap(char data[], int freq[], int size) {// Create a heap from given character and frequency arrays, and build the heap
    struct minheap *min = createheap(size);                         // Create a new heap with the given size
    int i;                                                          // Initialization
    for (i = 0; i < size; i++) {                                    // Maintain loop through array
        min->array[i] = newnode(data[i], freq[i]);                  // Create a new node and assign it to the heap array
    }
    min->size = size;                                               // Set the size of the heap
    buildheap(min);                                                 // Build the heap using the created array of nodes
    return min;                                                     // Return the created and built heap
}
struct node *huffman(char data[], int freq[], int size) {           // Build the Huffman tree and return the root node
    struct node *left, *top, *right;                                // Declare pointers for left, right, and top nodes
    struct minheap *min = createbuildheap(data, freq, size);        // Create and build a heap from the given data and frequency arrays
    while (min->size != 1) {                                        // Maintain loop until there is only one node in the heap
        left = extractmin(min);                                     // Extract the minimum node from the heap
        right = extractmin(min);                                    // Extract the second minimum node from the heap
        top = newnode('$', left->freq + right->freq);               // Create a new node with the combined frequency and '$' as data
        top->left = left;                                           // Assign the left node as the left child of the new node
        top->right = right;                                         // Assign the right node as the right child of the new node
        insertheap(min, top);                                       // Insert the new node back into the heap
    }
    return extractmin(min);                                         // Return the root of the Huffman tree
}
void printcodes(struct node *root, int arr[], int top) {            // Recursively print the Huffman codes
    if (root->left) {
        arr[top] = 0;                                               // If there is a left child, set the code at the current index to 0
        printcodes(root->left, arr, top + 1);                       // Recursively call the function
    }
    if (root->right) {
        arr[top] = 1;                                               // If there is a right child, set the code at the current index to 1
        printcodes(root->right, arr, top + 1);                      // Recursively call the function
    }
    if (!(root->left) && !(root->right)) {
        printf("    %c\t\t    ", root->data);                       // If the node is a leaf node (no left or right child), print the character and its code
        printarr(arr, top);                                         // Print the array representing the code
    }
}
void huffmancodes(char data[], int freq[], int size) {              // Generate and print Huffman codes for the given character and frequency arrays
    struct node *root = huffman(data, freq, size);                  // Build the Huffman tree and get the root node
    int arr[size], top = 0;                                         // Initialize an array to store the codes and a variable for the current index in the array
    printcodes(root, arr, top);                                     // Print the Huffman codes using the root of the Huffman tree
}
int main() {
    char *arr=NULL, st, choice='y';                                 // Initialization
    int *freq=NULL, sizearr=0, sizefreq=0, num, i;                  // Initialization
    while(choice=='y' || choice=='Y'){
        printf("Enter the character : ");                           // Taking input of character
        scanf("%s", &st);
        printf("Enter the character's frequency : ");               // Taking input of character's frequency
        scanf("%d", &num);
        int *newfreq = malloc((sizefreq + 1) * sizeof(int));        // Allocating memory to newfreq according to array
        if (newfreq == NULL) {                                      // Checking overflow condition
            exit(1);
        }
        char *newarr = malloc((sizearr + 1) * sizeof(int));         // Allocating memory to newarr according to array
        if (newarr == NULL) {                                       // Checking overflow condition
            exit(1);
        }
        for (i = 0; i < sizefreq; i++) {                            // Copy frequencies from freq to newfreq
            newfreq[i] = freq[i];
        }
        for (i = 0; i < sizearr; i++) {                             // Copy characters from arr to newarr
            newarr[i] = arr[i];
        }
        newfreq[sizefreq] = num;                                    // Enter new frequency num to newfreq
        sizefreq++;                                                 // Increment sizefreq
        newarr[sizearr] = st;                                       // Enter new character st to newarr
        sizearr++;                                                  // Increment sizearr
        free(freq);                                                 // Free memory from freq
        free(arr);                                                  // Free memory from arr
        freq = newfreq;                                             // Making newfreq as freq
        arr = newarr;                                               // Making newarr as arr
        printf("Do you want to enter new activity (Y/N) : ");
        scanf("%s", &choice);                                       // Asking for entering new activity
    }
    int size = sizearr / sizeof(arr[0]);                            // Calculate the size of the arrays
    printf("Character\tFrequency\n");
    for(i=0; i<size; i++){
        printf("    %c\t\t    %d\n", arr[i], freq[i]);
    }
    printf("Character\tHUffman code\n");
    huffmancodes(arr, freq, size);                                  // Generate and print Huffman codes for the given arrays
    return 0;
}