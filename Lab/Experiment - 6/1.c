#include <stdio.h>
#include <stdlib.h>
struct object{
    int number;                                              // Object number
    int weight;                                              // Weight
    float profit;                                            // Profit
};
int n;                                                       // Initialization
struct object *old=NULL;                                     // Initialization
int max(int a, int b){                                       // Function for finding maximum
    return (a>b) ? a : b;
}
int knapsack(int n, int m){
    if(n==0 || m==0){                                        // Returning 0 if no more element left or bag is full
        return 0;
    }
    else if(old[n-1].weight>m){                              // Returning the last maximum profit
        return knapsack(n-1, m);
    }
    else{                                                    // Checking for maximum in dynamic table
        return max(old[n-1].profit + knapsack(n-1, m-old[n-1].weight), knapsack(n-1, m));
    }
}
int main(){
    int i, j, temp, max_size, size=0, max;                   // Initialization
    printf("Enter max size of bag : ");
    scanf("%d", &max_size);                                  // Input max size of the bag
    struct object *new, *tem, t;                             // Initialization
    char choice='y';                                         // Initialization
    while(choice=='y' || choice=='Y'){
        n++;
        tem=malloc(sizeof(struct object));                   // Allocating memory to temp
        tem->number=size;                                    // Entering object number by series automatically
        printf("Enter weight of object %d : ", size);
        scanf("%d", &tem->weight);                           // Input weight of the object
        printf("Enter profit of object %d : ", size);
        scanf("%f", &tem->profit);                           // Input profit of the object
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
        size++;                                              // Incrementing size
        free(old);                                           // Free memory from old
        old=new;                                             // Making old as new
        printf("Do you want to enter new object (Y/N) : ");
        scanf("%s", &choice);                                // Asking for entering new activity
    }
    printf("  Object number\t\tWeight\t\t  Profit\n");
    for(i=0; i<size; i++){
        printf("\t%d\t\t   %d\t\t%f\n", old[i].number, old[i].weight, old[i].profit);
    }
    printf("%d", knapsack(n, max_size));
    return 0;
}