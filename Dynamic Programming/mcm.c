#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int mcm(int d[], int i, int j){
    if(i==j){                                                // If last size is equal to 1st size return
        return 0;
    }
    int k, min=INT_MAX, count;                               // Initialization
    for(k=i; k<j; k++){
        count=mcm(d, i, k)+mcm(d, k+1, j)+d[i-1]*d[k]*d[j];  // Apply mcm formula
        if(count<min){                                       // Finding number of minimum multiplications required
            min=count;
        }
    }
    return min;
}
int main(){
    int *num_array = NULL;                                   // Declare a pointer to int
    int num, size = 0;                                       // Initialization
    char choice='y';                                         // Initialization
    while(choice=='y' || choice=='Y'){
        printf("Enter dimension : ");
        scanf("%d", &num);                                   // Enter dimension
        int *new_array = (int *)malloc((size + 1) * sizeof(int));   // Allocate memory for a new array with increased size
        if (new_array == NULL) {
            exit(1);
        }
        for (int i = 0; i < size; i++) {                     // Copy elements from the old array to the new one
            new_array[i] = num_array[i];
        }
        new_array[size] = num;                               // Add the new element
        size++;
        free(num_array);                                     // Free the old array (if it exists)
        num_array = new_array;                               // Update the array pointer to point to the new array
        printf("Do you want to enter new dimension (Y/N) : ");
        scanf("%s", &choice);                                // Asking for entering new activity
    }
    printf("Minimum number of multiplications required %d", mcm(num_array, 1, size-1));
    return 0;
}