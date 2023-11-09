#include <stdio.h>                               // Time Complexity
int main(){
    int n, i, j, k, swap;                           // Constant
    printf("Enter max size of array ");           // Constant
    scanf("%d", &n);                             // Constant
    int arr[n];                                  // Constant
    printf("Enter array ");                       // Constant
    for(i=0; i<n; i++){                          // n+1 times                       entering data             
        scanf("%d", &arr[i]);                    // n times                         scan statement
    }
    printf("Entered array before sorting : ");
    for(i=0; i<n; i++){                          // n+1 times                       printing array before sorting
        printf("%d ", arr[i]);                   // n times                         print statement 
    }
    printf("\n");
    for (i=0; i<n-1; i++){                       // Max n times                         outer loop iteration for sorting or number of passes
        for(j=0; j<n-1-i; j++){                  // Max n(n+1)/2 times                  outer loop iteration for sorting or number of bubbles made in each sort
            swap=0;
            if(arr[j]>arr[j+1]){                 // Max n(n+1)/2 - 1 times              number of comparisons made
                int t=arr[j];                    // Constant
                arr[j]=arr[j+1];                 // Constant
                arr[j+1]=t;                      // Constant
                swap++;
            }
            printf("Pass %d, Bubble %d : ", i+1, j+1);
            for(k=0; k<n; k++){
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
        if(swap==0){
            printf("Stopped at pass %d\n", i+1);
            break;
        }
    }
    printf("Array after sorting : ");
    for(i=0; i<n; i++){                          // n+1 times                       printing array before sorting
        printf("%d ", arr[i]);                   // n times                         print statement 
    }
    return 0;                                    // Constant
}