#include <stdio.h>
int rb(int arr[], int beg, int end, int data){
    int mid;
    while(beg<=end){
        if(beg==end){
            if(arr[beg]==data){
                return beg;
            }
            else{
                return -1;
            }
        }
        else{
            mid=(beg+end)/2;
            if(arr[mid]==data){
                return mid;
            }
            else if(arr[mid]>data){
                rb(arr, beg, mid-1, data);
            }
            else{
                rb(arr, mid+1, end, data);
            }
        }
    }
    if(end<beg){
        printf("Element not found");
    }
}
int main(){
    int i, n, data, beg=0;
    printf("Enter size of array");
    scanf("%d", &n);
    int arr[n], end=n-1;
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter data to be searched");
    scanf("%d", &data);
    printf("%d", rb(arr, beg, end, data));
    return 0;
}