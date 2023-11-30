#include <stdio.h>
#include <stdlib.h>
int max(int a, int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}
int lcs(char str1[], char str2[], int i, int j){
    if(str1[i]=='\0' || str2[j]=='\0'){
        return 0;
    }
    else if(str1[i]==str2[j]){
        return 1+lcs(str1, str2, i+1, j+1);
    }
    else{
        return max(lcs(str1, str2, i+1, j), lcs(str1, str2, i, j+1));
    }
}
int main(){
    int m, n;
    printf("Enter number of elements you want to enter in str1 : ");
    scanf("%d", &m);
    printf("Enter number of elements you want to enter in str2 : ");
    scanf("%d", &n);
    char str1[m], str2[n];
    printf("Enter str1 : ");
    scanf("%s", &str1);
    printf("Enter str2 : ");
    scanf("%s", &str2);
    printf("Str1 : %s\n", str1);
    printf("Str2 : %s\n", str2);
    printf("Longest common Sequence length is %d", lcs(str1, str2, 0, 0));
    return 0;
}