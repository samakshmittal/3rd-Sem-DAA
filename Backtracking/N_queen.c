#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int n;
void printSolution(int **board){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]){
                printf("Q ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}
bool safe(int **board, int row, int col){
    int i, j;
    for(i=0; i<col; i++){
        if(board[row][i]){
            return false;
        }
    }
    for(i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j]){
            return false;
        }
    }
    for(i=row, j=col; j>=0 && i<n; i++, j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
bool nqueen(int **board, int col){
    if(col>=n){
        return true;
    }
    for(int i=0; i<n; i++){
        if(safe(board, i, col)){
            board[i][col]=1;
            if(nqueen(board, col+1)){
                return true;
            }
            board[i][col]=0;
        }
    }
    return false;
}
bool solve(){
    int **graph=NULL;
    int i, j, start;
    int V=0;
    n=0;
    printf("Enter power of 2 for N queen board : ");
    scanf("%d", &start);
    while(n<pow(2,start)){
        int **temp_graph = malloc((V + 1) * sizeof(int));
        if (temp_graph == NULL) {
            exit(1);
        }
        for (i = 0; i < V + 1; i++) {
            temp_graph[i] = malloc((V + 1) * sizeof(int));
            if (temp_graph[i] == NULL) {
                exit(1);
            }
        }
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++){
                temp_graph[i][j] = graph[i][j];
            }
        }
        V++;
        for(i=0; i<V; i++){
            temp_graph[V-1][i]=0;
            temp_graph[i][V-1]=0;
        }
        graph = temp_graph;
        n++;
    }
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    if(nqueen(graph, 0)==false){
        printf("Solution doesn't exist");
        return false;
    }
    printSolution(graph);
    return true;
}
int main(){
    solve();
    return 0;
}