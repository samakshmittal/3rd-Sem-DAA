#include <stdio.h>                               // Time Complexity
int main(){
    int n, i, j, k, min, t;                         // Constant
    printf("Enter max size of array ");          // Constant
    scanf("%d", &n);                             // Constant
    int arr[n];                                  // Constant
    printf("Enter array ");                      // Constant
    for(i=0; i<n; i++){                          // n+1 times                       entering data
        scanf("%d", &arr[i]);                    // n times                         scan statement
    }
    printf("Entered array before sorting : ");
    for(i=0; i<n; i++){                          // n+1 times                       printing array before sorting
        printf("%d ", arr[i]);                   // n times                         print statement 
    }
    printf("\n");
    for (i=0; i<n; i++){                         // n+1 times                       n times loop will maintain
        printf("Pass %d : ", i+1);
        for(k=0; k<n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
        min=i;                                   // n times
        printf("Initial min : %d\n", arr[min]);
        for(j=i+1; j<n; j++){                    // n(n+1)/2 times                  number of times the loop will maintain itself
            if(arr[j]<arr[min]){                 // n times                         n comparisons
                min=j;                           // Constant
            }
            for(k=0; k<n; k++){
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
        t=arr[i];                                // n times                         swapping
        arr[i]=arr[min];                         // n times                         swapping
        arr[min]=t;                              // n times                         swapping
        printf("After swapping : ");
        for(k=0; k<n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    printf("Array after sorting : ");
    for(i=0; i<n; i++){                          // n+1 times                       printing sorted array
        printf("%d ", arr[i]);                   // n times                         print statement 
    }
    return 0;                                    // Constant
}