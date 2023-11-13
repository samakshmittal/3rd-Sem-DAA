#include <stdio.h>                                                 // Time Complexity
#define max 10                                                     // Defining max elements as 10
void merge(int arr[], int beg, int mid, int end);                  // Declare Function merge
void sort(int arr[], int beg, int end);                            // Declare Function sort
int main(){
    int n, i;                                                      // Initialization
    printf("Enter max size of array ");                             // Enter size of array
    scanf("%d", &n);
    int arr[n];
    printf("Enter array ");
    for(i=0; i<n; i++){                                            // Enter data in the array
        scanf("%d", &arr[i]);
    }
    sort(arr, 0, n-1);                                             // Applying merge sorting function
    return 0;
}
void merge(int arr[], int beg, int mid, int end){
    int i=beg, j=mid+1, x=beg, temp[max], k;                       // Initialization
    printf("Left array : ");                                       // Printing array of left side after divide
    while(i<=mid){
        printf("%d ", arr[i]);
        i++;
    }
    printf("\tRight array : ");                                    // Printing array of right side after divide
    while(j<=end){
        printf("%d ", arr[j]);
        j++;
    }
    printf("\n");
    i=beg, j=mid+1;
    while((i<=mid) && (j<=end)){                                   // Maintaining loop
        if(arr[i]<arr[j]){                                         // Merging by checking first array is smaller or not
            temp[x]=arr[i];
            i++;
        }
        else{                                                      // Merging by checking second array is smaller or not automatically
            temp[x]=arr[j];
            j++;
        }
        x++;                                                       // Increment index by 1 of temporary array
    }
    if(i>mid){                                                     // Directly adding array 2 to temporary array after array 1 is empty
        while(j<=end){
            temp[x]=arr[j];
            j++;
            x++;
        }
    }
    else{                                                          // Directly adding array 1 to temporary array after array 2 is empty
        while(i<=mid){
            temp[x]=arr[i];
            i++;
            x++;
        }
    }
    printf("Merged array : ");
    for(k=beg; k<x; k++){                                          // Transferring temporary array to main array
        arr[k]=temp[k];
        printf("%d ", arr[k]);
    }
    printf("\n\n");
}
void sort(int arr[], int beg, int end){
    int mid, i;
    if(beg<end){
        mid=(beg+end)/2;
        printf("Mid index : %d\n", mid);
        sort(arr, beg, mid);                                       // Recursion of sorting funtion
        sort(arr, mid+1, end);                                     // Recursion of sorting funtion
        merge(arr, beg, mid, end);                                 // Recursion of merging funtion
    }
}