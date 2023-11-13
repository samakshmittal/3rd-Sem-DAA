#include <stdio.h>
int partition(int arr[], int beg, int end);                // Declare function partition
void quicksort(int arr[], int beg, int end);               // Declare function quicksort
int n;
int main(){
    int i, j, t;                                        // Initialization
    printf("Enter max size of array ");
    scanf("%d", &n);                                       // Entering max size of array
    int arr[n];
    printf("Enter array ");
    for(i=0; i<n; i++){                                    // Entering unsorted data in array
        scanf("%d", &arr[i]);
    }
    printf("Given array ");
    for(i=0; i<n; i++){                                    // Printing given array
        printf("%d ", arr[i]);
    }
    quicksort(arr, 0, n-1);                                // Calling quick sort
    printf("\n");
    printf("Sorted array ");
    for(i=0; i<n; i++){                                    // Printing sorted array
        printf("%d ", arr[i]);
    }
    return 0;
}
int partition(int arr[], int beg, int end){                // Defining partition function
    int pivot=arr[beg], p=beg, q=end, t;                   // Initialization
    printf("\npivot=%d", pivot);
    printf("\nStart p=%d", arr[p]);
    printf("\nStart q=%d", arr[q]);
    while(p<q){                                            // Maintaining loop for p<q
        while(arr[q]>pivot && q>beg){                      // Finding q
            q--;
        }
        printf("\nq=%d", arr[q]);
        while(arr[p]<=pivot && p<end){                     // Finding p
            p++;
        }
        printf("\np=%d", arr[p]);
        if(p<q){                                           // Swapping p and q
            t=arr[p];
            arr[p]=arr[q];
            arr[q]=t;
        }
        printf("\nArray after swapping p and q : ");
        for(int i=0; i<n; i++){
            printf("%d ", arr[i]);
        }
    }
    arr[beg]=arr[q];                                       // Swapping pivot and q
    arr[q]=pivot;
    printf("\nArray after swapping pivot and q : ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return q;
}
void quicksort(int arr[], int beg, int end){               // Defining quicksort function
    int loc;
    if(beg<end){
        loc=partition(arr, beg, end);                      // Calling partition function
        quicksort(arr, beg, loc-1);                        // Calling recursive quicksort function
        quicksort(arr, loc+1, end);                        // Calling recursive quicksort function
    }
}