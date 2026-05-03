#include <stdio.h>
#include <limits.h>

#define INF 1000000000

typedef struct {
    int u, v, w;
} Edge;

void bellman_ford(int V, int E, Edge edges[], int src) {

    int dist[V];

    for(int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 1; i <= V - 1; i++) {
        for(int j = 0; j < E; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative cycle
    for(int j = 0; j < E; j++) {

        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    printf("Vertex \t Distance\n");

    for(int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {

    int V = 5;
    int E = 10;

    Edge edges[] = {
        {0,1,6},{0,2,7},
        {1,2,8},{1,3,5},{1,4,-4},
        {2,3,-3},{2,4,9},
        {3,1,-2},
        {4,0,2},{4,3,7}
    };

    bellman_ford(V, E, edges, 0);

    return 0;
}
