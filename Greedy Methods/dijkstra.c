#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int V;
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int dist[]) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
void dijkstra(int **graph, int src) {
    int dist[V];     
    int sptSet[V];   
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1; 
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}
int main() {
    int **graph=NULL;
    char choice='y', choice1='y';
    int i, j, start=0, end=0;
    unsigned dist;
    V=0;
    while(choice=='y' || choice=='Y'){
        int **temp_graph = malloc((V + 1) * (V + 1) * sizeof(int));
        if (temp_graph == NULL) {
            exit(1);
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
        while(choice1=='y' || choice1=='Y'){
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
        free(graph);
        graph = temp_graph;
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
    dijkstra(graph, 0);
    return 0;
}