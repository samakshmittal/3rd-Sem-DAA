#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int V;
int minkey(int key[], bool mstset[]){
    int min=INT_MAX, min_index;
    for(int v=0; v<V; v++){
        if(mstset[V] == false && key[v] < min){       // Checking whether the vertex is not included and then from them minimum key vertex
            min=key[v], min_index=v;
        }
    }
    return min_index;
}
int printmst(int parent[], int **graph){
    printf("Edge \tWeight\n");
    for(int i=1; i<V; i++){
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}
void prims(int **graph){
    int parent[V];
    int key[V];
    bool mstset[V];
    for (int i=1; i<V; i++){
        key[i]=INT_MAX;
        mstset[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0; count<V; count++){
        int u=minkey(key, mstset);
        mstset[u]=true;
        for(int v=0; v<V; v++){
            if(graph[u][v] && mstset[v]==false && graph[u][v]<key[v]){
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    printmst(parent, graph);
}
int main() {
    int **graph=NULL;
    char choice='y', choice1='y';
    int i, j, start=0, end=0;
    unsigned dist;
    V=0;
    while(choice=='y' || choice=='Y'){
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
        printf("Number of vertices available till now are %d\n", V+1);
        V++;
        for(i=0; i<V; i++){
            temp_graph[V-1][i]=0;
            temp_graph[i][V-1]=0;
        }
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++){
                printf("%d ", temp_graph[i][j]);
            }
            printf("\n");
        }
        choice1='y';
        while((choice1=='y' || choice1=='Y') && V!=1){
            do{
                printf("Enter the starting vertex index : ");
                scanf("%d", &start);
            }while(start>V);
            do{
                printf("Enter the ending vertex index : ");
                scanf("%d", &end);
            }while(end>V);
            printf("Enter distance between them : ");
            scanf("%u", &dist);
            temp_graph[start][end]=dist;
            printf("Do you want to enter new distance with current vertices (Y/N) : ");
            scanf("%s", &choice1);
        }
        graph = temp_graph;
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++){
                printf("%d ", graph[i][j]);
            }
            printf("\n");
        }
        printf("Do you want to enter new vertex (Y/N) : ");
        scanf("%s", &choice);
    }
    // int graph[V][V] = {
    //     {0, 4, 0, 0, 0, 0},
    //     {4, 0, 8, 0, 0, 0},
    //     {0, 8, 0, 7, 0, 4},
    //     {0, 0, 7, 0, 9, 14},
    //     {0, 0, 0, 9, 0, 10},
    //     {0, 0, 4, 14, 10, 0}
    // };
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    prims(graph);
    return 0;
}