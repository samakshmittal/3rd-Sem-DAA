//CODE BY KAVYA
#include <stdio.h>
#include<limits.h>//as we are using int_max so as to check condition
#include <stdbool.h>
//#define V 59
int minDistance(int dist[], bool Visited[], int V) {//func to find min value
    int max = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!Visited[v] && max>=dist[v]) {//checking cndtion
            max = dist[v];//defoinning max to dist
            min_index = v;
        }
    }
    return min_index;//returning minimum index
}
void printSolution(int dist[], int n) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; i++) {
         printf("%d \t%d\n", i, dist[i]);
    }
}
void dijkstra(int V, int graph[V][V], int src) {
    int dist[V];
    bool Visited[V];//to chck whether the vertex is vistired or not in true or false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        Visited[i] = false;
    }
    dist[src] = 0;//firstly defining it as 0
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, Visited, V);
        Visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!Visited[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];//formaulaa for dist
            }
        }
    }
    printSolution(dist, V);
}
int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter the graph as an adjacency matrix where self loop are not being counted toh it shld be 0:");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int source;
    printf("Enter the source node (0 to %d): ", V - 1);
    scanf("%d", &source);
    if (source < 0 ||   source >= V) {
        printf("Invalid source node. Please enter a valid source node (0 to %d).\n", V - 1);
        return 0;
    }
    dijkstra(V, graph, source);
    return 0;
}
