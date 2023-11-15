#include <stdio.h>
int main(){
    int n;
    printf("Enter max size of array");
    scanf("%d", &n);
    int arr[n], i, j, t;
    for(i=0; i<n; i++){
        printf("Enter number");
        scanf("%d", &arr[i]);
    }
    for(i=1; i<n; i++){
        t=arr[i];
        j=i-1;
        while(t<=arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=t;
    }
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}