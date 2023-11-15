#include <stdio.h>
int main(){
    int n;
    printf("Enter max size of array");
    scanf("%d", &n);
    int arr[n], i, j, temp, min;
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}