#include <stdio.h>
#include <stdlib.h>
struct activity{
    int number;        // Number of activity
    int start;         // Start time of activity
    int finish;        // Finish time of activity
};
int main(){
    struct activity *old=NULL, *new;
    int flag=0;
    while(flag==0){
        printf("Enter the number of activity : ");
        scanf("%d", &old->number);
        printf("Enter the start time of activity : ");
        scanf("%d", &old->start);
        printf("Enter the finish time of activity : ");
        scanf("%d", &old->finish);
        new=malloc(sizeof(struct activity));
        if(new==NULL){
            exit(1);
        }
        
    }
}