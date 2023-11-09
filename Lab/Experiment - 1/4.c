//Code by kavya
#include <stdio.h> 
#include <string.h>//becz strlen func is used
int main() {
    int n,m,i,j;
    char text[100]; //defining array name text with size 100
    char pattern[100];//similar as abv
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern to search for: ");
    scanf("%s", pattern);
     n = strlen(text); //finding length of text and pttrn
     m = strlen(pattern); 
    int result = -1;//defining a variable result as index 0
    for ( i = 0; i <= n - m; i++) {//for loop from 0 to n-m bcoz m is less than equal to n which can simply give 0 at worst case that time to code will run
        for (j = 0; j < m; j++) {//for loop from 0 to m-1 ,comparing letters of pttrn with the letters of text
            if (text[i + j] != pattern[j]) {//if letters in the pttrn doesnt match with txt break 
                break;
            }
        }
        if (j == m) {//if j becomes equal to m which is length of pattrn then there exists the pttrn in the txt
            result = i; //result will be equal to index of pattrn found in text 
            break;
        }
    }
    if (result !=-1 ) {//if result is not 0 then found otherwise not found
        printf("Pattern found at position %d in the text.\n", result+1);
    } else {
        printf("Pattern not found in the text.\n");
    }
    return 0;
}
