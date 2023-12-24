#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int V;
// int minDistance(int dist[], int sptSet[]) {
//     int min = INT_MAX, min_index;
//     for (int v = 0; v < V; v++) {
//         if (!sptSet[v] && dist[v] < min) {
//             min = dist[v];
//             min_index = v;
//         }
//     }
//     return min_index;
// }
// void printSolution(int dist[]) {
//     printf("Vertex   Distance from Source\n");
//     for (int i = 0; i < V; i++) {
//         printf("%d \t\t %d\n", i, dist[i]);
//     }
// }
void bellman(int graph[][5], int src) {
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    int x=0;
    while(x!=V-1){
        for (int i = 0; i < V - 1; i++) {
            for (int j = 0; j < V-1; j++) {
                if (dist[i] != INT_MAX && dist[i] + graph[i][j] < dist[j]) {
                    dist[j] = dist[i] + graph[i][j];
                }
            }
        }
        x++;
    }
    for(int i=0; i<V; i++){
        int x=i;
        int y=j;
        int weight=graph[i][j];
        if(dist[x]!=INT_MAX && dist[x]+weight<dist[y]){
            printf("\nContains negative cycle\n");
        }
    }
    // printSolution(dist);
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
int main() {
    //int **graph=NULL;
    char choice='y', choice1='y';
    int i, j, start=0, end=0;
    unsigned dist;
    V=5;
    // while(choice=='y' || choice=='Y'){
    //     int **temp_graph = malloc((V + 1) * sizeof(int));
    //     if (temp_graph == NULL) {
    //         exit(1);
    //     }
    //     for (i = 0; i < V + 1; i++) {
    //         temp_graph[i] = malloc((V + 1) * sizeof(int));
    //         if (temp_graph[i] == NULL) {
    //             exit(1);
    //         }
    //     }
    //     for (i = 0; i < V; i++) {
    //         for (j = 0; j < V; j++){
    //             temp_graph[i][j] = graph[i][j];
    //         }
    //     }
    //     printf("Number of vertices available till now are %d\n", V+1);
    //     V++;
    //     for(i=0; i<V; i++){
    //         temp_graph[V-1][i]=0;
    //         temp_graph[i][V-1]=0;
    //     }
    //     for (i = 0; i < V; i++) {
    //         for (j = 0; j < V; j++){
    //             printf("%d ", temp_graph[i][j]);
    //         }
    //         printf("\n");
    //     }
    //     choice1='y';
    //     while((choice1=='y' || choice1=='Y') && V!=1){
    //         do{
    //             printf("Enter the starting vertex index : ");
    //             scanf("%d", &start);
    //         }while(start>V);
    //         do{
    //             printf("Enter the ending vertex index : ");
    //             scanf("%d", &end);
    //         }while(end>V);
    //         printf("Enter distance between them : ");
    //         scanf("%u", &dist);
    //         temp_graph[start][end]=dist;
    //         printf("Do you want to enter new distance with current vertices (Y/N) : ");
    //         scanf("%s", &choice1);
    //     }
    //     graph = temp_graph;
    //     for (i = 0; i < V; i++) {
    //         for (j = 0; j < V; j++){
    //             printf("%d ", graph[i][j]);
    //         }
    //         printf("\n");
    //     }
    //     printf("Do you want to enter new vertex (Y/N) : ");
    //     scanf("%s", &choice);
    // }
    int graph[][5] = {
        {0, -1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {0, 0, 0, 0, 0},
        {0, 1, 5, 0, 0},
        {0, 0, 0, -3, 0}
    };
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    int source;
    printf("Enter the source node (0 to %d): ", V - 1);
    scanf("%d", &source);
    if (source < 0 || source >= V) {
        printf("Invalid source node. Please enter a valid source node (0 to %d).\n", V - 1);
        return 0;
    }
    bellman(graph, source);
    return 0;
}