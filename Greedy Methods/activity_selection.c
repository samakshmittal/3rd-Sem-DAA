#include <stdio.h>
#include <stdlib.h>
struct activity{
    int number;        // Number of activity
    int start;         // Start time of activity
    int finish;        // Finish time of activity
};
int main(){
    struct activity *old=NULL;
    int flag=0, size=0, i;
    while(flag==0){
        struct activity *new=malloc((size+1)*sizeof(struct activity));
        if(new==NULL){
            exit(1);
        }
        for(i=0; i<size; i++){
            new[i]=old[i];
        }
        printf("Enter the number of activity : ");
        scanf("%d", &old->number);
        printf("Enter the start time of activity : ");
        scanf("%d", &old->start);
        printf("Enter the finish time of activity : ");
        scanf("%d", &old->finish);
        
    }
}