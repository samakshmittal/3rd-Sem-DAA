#include <stdio.h>
int main(){
    int i, n, data;
    printf("Enter size of array");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter data to be searched");
    scanf("%d", &data);
    i=0;
    while(i!=n){
        if(arr[i]==data){
            printf("Found at index number %d and location %d", i, i+1);
            break;
        }
        else{
            i++;
        }
    }
    if (i==n){
        printf("Element not found");
    }
    return 0;
}