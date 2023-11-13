#include <stdio.h>                                        // Time Complexity
int main(){
    int n, i, j, k, t, count;                                       // Constant                Initialization
    printf("Enter max size of array ");                   // Constant
    scanf("%d", &n);                                      // Constant                Entering max size of array
    int arr[n];                                           // Constant
    printf("Enter array ");                               // Constant
    for(i=0; i<n; i++){                                   // n+1 times               Entering values in array
        scanf("%d", &arr[i]);                             // n times
    }
    for(i=1; i<n; i++){                                   // n times                 Insertion sort
        t=arr[i];                                         // n-1 times               Temporary variable
        j=i-1;                                            // n-1 times
        printf("Pass %d : ", i);
        for(k=0; k<n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
        count=0;
        while(t<=arr[j] && j>=0){                         // Max n-1 times in worst case
            arr[j+1]=arr[j];                              // Max n-1 times in worst case     Inserting element at right position
            count++;
            printf("Insertion %d : ", count);
            for(k=0; k<n; k++){
                printf("%d ", arr[k]);
            }
            printf("\n");
            j--;                                          // Max n-1 times in worst case
        }
        arr[j+1]=t;                                       // n-1 times
    }
    printf("Sorted array : ");
    for(i=0; i<n; i++){                                   // n+1 times                 Printing sorted array
        printf("%d ", arr[i]);                            // n times
    }
    return 0;                                             // Constant
}