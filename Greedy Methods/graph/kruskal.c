#include <stdio.h>
#include <stdlib.h>
typedef struct edge{
    int u, v, w;
}edge;
typedef struct edge_list{
    edge data[30];
    int n;
}edge_list;
edge_list elist;
int graph[30][30], n;
edge_list spanlist;
void kruskal(){
    int belongs[30], i, j, cno1, cno2;
    elist.n=0;
    for(i=1; i<n; i++){
        for(j=0; j<n; j++){
            if(graph[i][j]!=0){
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=graph[i][j];
                elist.n++;
            }
        }
        sort();
        for(i=0; i<n; i++){
            belongs[i]=i;
        }
        spanlist.n=0;
        for(i=0; i<elist.n; i++){
            cno1=find(belongs, elist.data[i].u);
        }
    }
}