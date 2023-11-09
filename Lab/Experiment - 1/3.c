#include <stdio.h>                               // Time Complexity
int main(){
    int n, m, i, j, k, count=0;                  // Constant
    printf("Enter size of string TEXT ");         // Constant
    scanf("%d", &n);                             // Constant
    do{
        printf("Enter size of string PATTERN ");  // Constant
        scanf("%d", &m);                         // Constant
    }while(n<m);
    char TEXT[n], PATTERN[m];                    // Constant
    printf("Enter TEXT ");                        // Constant
    scanf("%s", TEXT);                           // Constant
    printf("Enter PATTERN ");                     // Constant
    scanf("%s", PATTERN);                        // Constant
    for(i=0; i<n; i++){                          // n+1 times
        if (PATTERN[0]==TEXT[i]){                // Constant                 Check first letter of PATTERN in TEXT
            k=i+1;                               // Constant                 Temporary variable
            count=1;                             // Constant                 Used for printing at last
            for(j=1; j<m; j++){                  // m+1 times (m<=n)         Checking further characters both the strings
                if (PATTERN[j]==TEXT[k]){        // Constant
                    k++;                         // Constant
                    count++;                     // Constant
                }
                else{
                    break;                       // Constant
                }
            }
            if(count==m){                        // Constant
                printf("PATTERN found in TEXT at index %d", i);  // Constant
                break;                           // Constant
            }
        }
    }
    return 0;                                    // Constant
}