#include <stdio.h>
#include <stdlib.h>
struct activity{
    int number;        // Number of activity
    int start;         // Start time of activity
    int finish;        // Finish time of activity
};
int main(){
    struct activity *old=NULL, *new, *temp;
    int size=0, i;
    char choice='y';
    while(choice=='y' || choice=='Y'){
        temp=malloc(sizeof(struct activity));
        printf("Enter the number of activity : ");
        scanf("%d", &temp->number);
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
    printf("Activity number\t Activity start time\tActivity finish time\n");
    for(i=0; i<size; i++){
        printf("\t%d\t\t%d\t\t\t%d\n", old[i].number, old[i].start, old[i].finish);
    }
        
    return 0;
}