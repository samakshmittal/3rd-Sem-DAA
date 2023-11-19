#include <stdio.h>
struct object{
    int weight;                                         //Introduce weight
    float profit;                                       //Introduce profit
    float ppw;                                          //Introduce profit per weight = profit/weight
};
int main(){
    int n, i, j, temp, max_size, max;
    float max_profit=0.0;                               //Initializing maximum or overall profit as 0
    printf("Enter number of objects");
    scanf("%d", &n);                                    //Input number of objects
    printf("Enter max size of bag");
    scanf("%d", &max_size);                             //Input max size of the bag
    struct object O[n], t;                              //Initializing array of structure object
    for(i=0; i<n; i++){
        printf("Enter weight of object %d ", i+1);
        scanf("%d", &O[i].weight);                      //Input weight of each object
        printf("Enter profit of object %d ", i+1);
        scanf("%f", &O[i].profit);                      //Input profit of each object
        O[i].ppw=O[i].profit/O[i].weight;               //Calculate profit per weight of each object
    }
    for(i=0; i<n; i++){                                 //Iterate over each object
        max=O[i].ppw;                                   //Let variable max as the profit per weight of the current object iterating over
        temp=i;
        for(j=i+1; j<n; j++){                           //Iterate for finding maximum profit per weight
            if(max<O[j].ppw){
                max=O[j].ppw;
                temp=j;                                 //Suppose temp be the index of the maximum value of profit per weight if no two or maxmimum value collides
            }
            else if(max==O[j].ppw){
                if(O[temp].weight < O[j].weight){
                    temp=j;                             //Suppose temp be the index of the maximum value of profit per weight and also quantity if two or maxmimum value collides
                }
            }
        }
        if(max_size >= O[temp].weight){                 //Checking if maximum size of bag is more than or equal to the quantity of the current maximum ppw
            max_profit += (float)(O[temp].profit);      //Directly adding profit to maximum or overall profit
            max_size-=O[temp].weight;                   //Deducing weight from maximum size that is occupied by the current object
        }
        else{                                           //Checking if maximum size of bag is less than the quantity of the current maximum ppw
            max_profit += (float)(O[temp].profit*max_size/O[temp].weight);  //Calculate the profit of the partial quantity putting in the bag and adding it to maximum or overall profit
            max_size=0;                                 //Mark max size as 0 as bag is full now
            break;                                      //Breaking the loop as the bag is full so there is no use of iterating over it
        }
        t=O[temp];                                      //Swapping the maximum to the current index so that the loop never iterate over it again
        O[temp]=O[i];
        O[i]=t;
    }
    printf("%f", max_profit);                           //Printing the maximum or overall profit
    return 0;
}