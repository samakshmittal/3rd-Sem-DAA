#include <stdio.h>
#include <stdlib.h>
int size=0;
struct activity{
    int number;        // Number of activity
    int start;         // Start time of activity
    int finish;        // Finish time of activity
};
int partition(struct activity arr[], int beg, int end);                // Declare function partition
void quicksort(struct activity arr[], int beg, int end);               // Declare function quicksort
int main(){
    struct activity *old=NULL, *new, *temp;
    int i;
    char choice='y';
    while(choice=='y' || choice=='Y'){
        temp=malloc(sizeof(struct activity));
        temp->number=size;
        printf("Enter the start time of activity : ");
        scanf("%d", &temp->start);
        printf("Enter the finish time of activity : ");
        scanf("%d", &temp->finish);
        new=malloc((size+1)*sizeof(struct activity));
        if(new==NULL){
            exit(1);
        }
        for(i=0; i<size; i++){
            new[i]=old[i];
        }
        new[size].number=temp->number;
        new[size].start=temp->start;
        new[size].finish=temp->finish;
        size++;
        free(old);
        old=new;
        printf("Do you want to enter new activity (Y/N) : ");
        scanf("%s", &choice);
    }
    printf("Actvities entered by user:\nActivity number\t Activity start time\tActivity finish time\n");
    for(i=0; i<size; i++){
        printf("\t%d\t\t%d\t\t\t%d\n", old[i].number, old[i].start, old[i].finish);
    }
    quicksort(old, 0, size-1);
    printf("Actvities after sorting according to finish time:\nActivity number\t Activity start time\tActivity finish time\n");
    for(i=0; i<size; i++){
        printf("\t%d\t\t%d\t\t\t%d\n", old[i].number, old[i].start, old[i].finish);
    }
    return 0;
}
int partition(struct activity arr[], int beg, int end){                // Defining partition function
    int pivot=arr[beg].finish, p=beg, q=end;                   // Initialization
    struct activity t;
    while(p<q){                                            // Maintaining loop for p<q
        while(arr[q].finish>pivot && q>beg){                      // Finding q
            q--;
        }
        while(arr[p].finish<=pivot && p<end){                     // Finding p
            p++;
        }
        if(p<q){                                           // Swapping p and q
            t=arr[p];
            arr[p]=arr[q];
            arr[q]=t;
        }
    }
    t=arr[beg];
    arr[beg]=arr[q];                                       // Swapping pivot and q
    arr[q]=t;
    return q;
}
void quicksort(struct activity arr[], int beg, int end){               // Defining quicksort function
    int loc;
    if(beg<end){
        loc=partition(arr, beg, end);                      // Calling partition function
        quicksort(arr, beg, loc-1);                        // Calling recursive quicksort function
        quicksort(arr, loc+1, end);                        // Calling recursive quicksort function
    }
}