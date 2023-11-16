#include <stdio.h>
#include <stdlib.h>
int size=0;                                                  // Initialization
struct activity{                                             // Declaring structure activity
    int number;                                              // Number of activity
    int start;                                               // Start time of activity
    int finish;                                              // Finish time of activity
};
int partition(struct activity arr[], int beg, int end);      // Declare function partition
void quicksort(struct activity arr[], int beg, int end);     // Declare function quicksort
int main(){
    struct activity *old=NULL, *new, *temp, t;               // Initialization
    int i, j;                                                // Initialization
    char choice='y';                                         // Initialization
    while(choice=='y' || choice=='Y'){
        temp=malloc(sizeof(struct activity));                // Allocating memory to temp
        temp->number=size;                                   // Entering activity number by series automatically
        printf("Enter the start time of activity : ");
        scanf("%d", &temp->start);                           // Taking input of start time of a activity
        printf("Enter the finish time of activity : ");
        scanf("%d", &temp->finish);                          // Taking input of finish time of a activity
        new=malloc((size+1)*sizeof(struct activity));        // Allocating memory to new according to array
        if(new==NULL){                                       // Checking overflow condition
            exit(1);
        }
        for(i=0; i<size; i++){                               // Copy activities from old to new
            new[i]=old[i];
        }
        new[size].number=temp->number;                       // Entering new activity number to new
        new[size].start=temp->start;                         // Entering new activity start time to new
        new[size].finish=temp->finish;                       // Entering new activity finish time to new
        size++;                                              // Incrementing size
        free(old);                                           // Free memory from old
        old=new;                                             // Making old as new
        printf("Do you want to enter new activity (Y/N) : ");
        scanf("%s", &choice);                                // Asking for entering new activity
    }
    printf("Actvities entered by user:\nActivity number\t Activity start time\tActivity finish time\n");
    for(i=0; i<size; i++){                                   // Printing activity entered by user
        printf("\t%d\t\t%d\t\t\t%d\n", old[i].number, old[i].start, old[i].finish);
    }
    quicksort(old, 0, size-1);                               // Applying quick sort on activity finish time
    for(i=0; i<size-1; i++){
        if(old[i].finish==old[i+1].finish){                  // If finish time is same of 2 activities then checking their start time and sort
            if(old[i+1].start>old[i].start){
                t=old[i];
                old[i]=old[i+1];
                old[i+1]=t;
            }
        }
    }
    printf("Actvities after sorting according to finish time:\nActivity number\t Activity start time\tActivity finish time\n");
    for(i=0; i<size; i++){                                  // Printing activities after sorting
        printf("\t%d\t\t%d\t\t\t%d\n", old[i].number, old[i].start, old[i].finish);
    }
    printf("Maximum actvities that can run are:\nActivity number\t Activity start time\tActivity finish time\n");
    i=0;                                                    // Printing maximum number of activities
    printf("\t%d\t\t%d\t\t\t%d\n", old[i].number, old[i].start, old[i].finish);  //First activity is always get selected
    for(j=1; j<size; j++){
        if(old[j].start>=old[i].finish){                    // If current activity has start time greater than or previous finish time then select it
            printf("\t%d\t\t%d\t\t\t%d\n", old[j].number, old[j].start, old[j].finish);
            i=j;                                            // Make current activity as previous for next activity
        }
    }
    return 0;
}
int partition(struct activity arr[], int beg, int end){     // Defining partition function
    int pivot=arr[beg].finish, p=beg, q=end;                // Initialization
    struct activity t;
    while(p<q){                                             // Maintaining loop for p<q
        while(arr[q].finish>pivot && q>beg){                // Finding q
            q--;
        }
        while(arr[p].finish<=pivot && p<end){               // Finding p
            p++;
        }
        if(p<q){                                            // Swapping p and q
            t=arr[p];
            arr[p]=arr[q];
            arr[q]=t;
        }
    }
    t=arr[beg];
    arr[beg]=arr[q];                                        // Swapping pivot and q
    arr[q]=t;
    return q;
}
void quicksort(struct activity arr[], int beg, int end){    // Defining quicksort function
    int loc;
    if(beg<end){
        loc=partition(arr, beg, end);                       // Calling partition function
        quicksort(arr, beg, loc-1);                         // Calling recursive quicksort function
        quicksort(arr, loc+1, end);                         // Calling recursive quicksort function
    }
}