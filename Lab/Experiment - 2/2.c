#include <stdio.h>
int count=0;                                               // Declare variable count
int rb(int arr[], int beg, int end, int data){             // Function for binary search through recursion
    int mid;                                               // Declare variable mid
    while(beg<=end){                                       // Maintaining loop
        count++;                                           // Increment count
        if(beg==end){                                      // If only 1 element is there
            if(arr[beg]==data){
                return beg;
            }
            else{
                return -1;
            }
        }
        else{                                              // More than 1 elements
            mid=(beg+end)/2;                               // Defining mid
            printf("Mid index : %d\n", mid);
            if(arr[mid]==data){                            // Checking whether mid and data are equal or not
                return mid;
            }
            else if(arr[mid]>data){                        // If data is less than mid then make end = mid - 1 and call same function
                return rb(arr, beg, mid-1, data);
            }
            else{                                          // If data is more than mid then make beg = mid + 1 and call same function
                return rb(arr, mid+1, end, data);
            }
        }
    }
    if(end<beg){
        printf("Element not found");
    }
}
int main(){
    int i, n, data, beg=0;                                 // Initialization
    printf("Enter size of array ");
    scanf("%d", &n);                                       // Entering size of array
    int arr[n], end=n-1;
    printf("Enter array ");
    for(i=0; i<n; i++){                                    // Entering data in array
        scanf("%d", &arr[i]);
    }
    printf("Enter data to be searched ");                   // Enter data to be searched
    scanf("%d", &data);
    printf("%d found at location %d", data, rb(arr, beg, end, data));  // Calling function for binary searching through recursion
    printf("\nNumber of times searching done is %d", count);  // Printing number of times search happened
    return 0;
}