#include <stdio.h>
#include <stdlib.h>
struct object{
    int number;                                              // Object number
    int weight;                                              // Weight
    float profit;                                            // Profit
    float ppw;                                               // Profit/weight
};
int main(){
    int i, j, temp, max_size, size=0, max;                   // Initialization
    float max_profit=0.0;                                    // Initializing max or overall profit as 0
    printf("Enter max size of bag : ");
    scanf("%d", &max_size);                                  // Input max size of the bag
    struct object *old=NULL, *new, *tem, t;                  // Initialization
    char choice='y';                                         // Initialization
    while(choice=='y' || choice=='Y'){
        tem=malloc(sizeof(struct object));                   // Allocating memory to temp
        tem->number=size;                                    // Entering object number by series automatically
        printf("Enter weight of object %d : ", size);
        scanf("%d", &tem->weight);                           // Input weight of the object
        printf("Enter profit of object %d : ", size);
        scanf("%f", &tem->profit);                           // Input profit of the object
        tem->ppw=tem->profit/tem->weight;                    // Calculating profit per weight for each object and saving
        new=malloc((size+1)*sizeof(struct object));          // Allocating memory to new according to array
        if(new==NULL){                                       // Checking overflow condition
            exit(1);
        }
        for(i=0; i<size; i++){                               // Copy activities from old to new
            new[i]=old[i];
        }
        new[size].number=tem->number;                        // Entering new object number to new
        new[size].weight=tem->weight;                        // Entering new object weight to new
        new[size].profit=tem->profit;                        // Entering new object profit to new
        new[size].ppw=tem->ppw;                              // Entering new object profit per weight to new
        size++;                                              // Incrementing size
        free(old);                                           // Free memory from old
        old=new;                                             // Making old as new
        printf("Do you want to enter new object (Y/N) : ");
        scanf("%s", &choice);                                // Asking for entering new activity
    }
    printf("  Object number\t\tWeight\t\t  Profit\t\tProfit per weight\n");
    for(i=0; i<size; i++){
        printf("\t%d\t\t   %d\t\t%f\t\t    %f\n", old[i].number, old[i].weight, old[i].profit, old[i].ppw);
    }
    for(i=0; i<size; i++){                                   // Maintaining loop
        max=old[i].ppw;                                      // Letting variable max as the profit per weight of the current object
        temp=i;
        for(j=i+1; j<size; j++){
            if(max<old[j].ppw){                              // Finding maximum profit/weight
                max=old[j].ppw;
                temp=j;                                      // Storing the index of the maximum value of profit per weight 
            }
            else if(max==old[j].ppw){
                if(old[temp].weight < old[j].weight){
                    temp=j;                                  // Storing the index of the maximum value of profit per weight and also maximum quantity if two of them has same max value
                }
            }
        }
        if(max_size >= old[temp].weight){                    // Checking if maximum size of bag is more than or equal to the quantity of the current maximum ppw
            printf("Object %d with weight %d and profit %f is added to bag.\n", old[temp].number, old[temp].weight, (float)(old[temp].profit));
            max_profit += (float)(old[temp].profit);         // Directly adding profit to maximum or overall profit
            max_size-=old[temp].weight;                      // Subtracting weight from maximum size that is occupied by the current object
        }
        // else{                                                // Checking if maximum size of bag is less than the quantity of the current maximum ppw
        //     printf("Object %d with weight %d and profit %f is added to bag.\n", old[temp].number, max_size, (float)(old[temp].profit*max_size/old[temp].weight));
        //     max_profit += (float)(old[temp].profit*max_size/old[temp].weight);   // Calculate the profit of the partial quantity putting in the bag and adding it to maximum or overall profit
        //     max_size=0;                                      // Make max size as 0 as bag is full now
        //     break;                                           // Breaking the loop as the bag is full so there is no need to maintain loop
        // }
        t=old[temp];                                         // Swapping the maximum to the current index so that the loop never maintain over it again
        old[temp]=old[i];
        old[i]=t;
    }
    printf("Overall maximum profit gained from the bag is %f.", max_profit);   // Printing the maximum or overall profit
    return 0;
}