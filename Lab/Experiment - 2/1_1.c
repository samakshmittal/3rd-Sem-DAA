#include <stdio.h>
int search(int arr[], int data, int i, int n) {  // Recursive relation for linear search
    if (i == n) {                                // Element not found
        return -1;
    }
    if (arr[i] == data) {                        // Element found
        return i;
    }
    return search(arr, data, i + 1, n);          // Check for next element
}
int main(){
    int n, i, data, result;                      // Initialization
    printf("Enter max size of array ");          // Array size input
    scanf("%d", &n);
    int arr[n];                                  // Creating array
    printf("Enter array ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);                    // Entering data in array
    }
    printf("Enter data to be searched ");        // Entering element to search
    scanf("%d", &data);
    result = search(arr, data, 0, n);            // Apply recursive function
    if (result == -1) {
        printf("%d not found\n", data);          // If -1 is returned element not found
        printf("Number of times searching done is %d", n);
    }
    else {                                       // Element found at index result
        printf("%d found at location %d\n", data, result);
        printf("Number of times searching done is %d", result+1);
    }
    return 0;
}