#include <stdio.h>
int main(){
    int i, n, data, beg=0;
    printf("Enter size of array");
    scanf("%d", &n);
    int arr[n], end=n-1, mid;
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter data to be searched");
    scanf("%d", &data);
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==data){
            printf("Found at index number %d and location %d", mid, mid+1);
            break;
        }
        else if(arr[mid]>data){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
    if(end<beg){
        printf("Element not found");
    }
    return 0;
}