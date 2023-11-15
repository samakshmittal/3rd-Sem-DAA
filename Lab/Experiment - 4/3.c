#include <stdio.h>
struct object{
    int weight;
    float profit;
    float ppw;          // Profit/weight
};
int main(){
    int n, i, j, temp, max_size, max;
    float max_profit=0.0;       // Initializing max or overall profit as 0
    printf("Enter number of objects : ");
    scanf("%d", &n);   // Input number of objects
    printf("Enter max size of bag : ");
    scanf("%d", &max_size);      // Input max size of the bag
    struct object O[n], t;       // Initializing array of structure
    for(i=0; i<n; i++){
        printf("Enter weight of object %d : ", i+1);
        scanf("%d", &O[i].weight);                      
        printf("Enter profit of object %d : ", i+1);
        scanf("%f", &O[i].profit);                      
        O[i].ppw=O[i].profit/O[i].weight;    // Calculating profit per weight for each object and saving
    }
    for(i=0; i<n; i++){    // Maintaining loop
        max=O[i].ppw;      // Letting variable max as the profit per weight of the current object
        temp=0;
        for(j=i+1; j<n; j++){  
            if(max<O[j].ppw){       // Finding maximum profit/weight
                max=O[j].ppw;
                temp=j;      // Storing the index of the maximum value of profit per weight 
            }
            else if(max==O[j].ppw){
                if(O[temp].weight < O[j].weight){
                    temp=j;  // Storing the index of the maximum value of profit per weight and also maximum quantity if two of them has same max value
                }
            }
        }
        if(max_size >= O[temp].weight){    // Checking if maximum size of bag is more than or equal to the quantity of the current maximum ppw
            max_profit += (float)(O[temp].profit);     // Directly adding profit to maximum or overall profit
            max_size-=O[temp].weight;   // Subtracting weight from maximum size that is occupied by the current object
        }
        else{     // Checking if maximum size of bag is less than the quantity of the current maximum ppw
            max_profit += (float)(O[temp].profit*max_size/O[temp].weight);  // Calculate the profit of the partial quantity putting in the bag and adding it to maximum or overall profit
            max_size=0;  // Make max size as 0 as bag is full now
            break;  // Breaking the loop as the bag is full so there is no need to maintain loop
        }
        t=O[temp];   // Swapping the maximum to the current index so that the loop never maintain over it again
        O[temp]=O[i];
        O[i]=t;
    }
    printf("%f", max_profit);  // Printing the maximum or overall profit
    return 0;
}
