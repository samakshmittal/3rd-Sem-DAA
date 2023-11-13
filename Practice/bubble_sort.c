#include <stdio.h>                               // Time Complexity
int main(){
    int n, i, j;                                 // Constant
    printf("Enter max size of array");           // Constant
    scanf("%d", &n);                             // Constant
    int arr[n];                                  // Constant
    for(i=0; i<n; i++){                          // n+1 times                       entering data
        printf("Enter data");                    // n times                         print statement             
        scanf("%d", &arr[i]);                    // n times                         scan statement
    }
    for (i=0; i<n-1; i++){                       // n times                         outer loop iteration for sorting or number of passes
        for(j=0; j<n-1-i; j++){                  // n(n+1)/2 times                  outer loop iteration for sorting or number of bubbles made in each sort
            if(arr[j]>arr[j+1]){                 // n(n+1)/2 - 1 times              number of comparisons made
                int t=arr[j];                    // Constant
                arr[j]=arr[j+1];                 // Constant
                arr[j+1]=t;                      // Constant
            }
        }
    }
    for(i=0; i<n; i++){                          // n+1 times                       printing sorted array
        printf("%d ", arr[i]);                   // n times                         print statement 
    }
    return 0;                                    // Constant
}