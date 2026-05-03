#include <stdio.h>
#include <limits.h>

#define V 5


int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for(int v = 0; v < V; v++) {
        if(mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    int total = 0;

    printf("Edge \tWeight\n");

    for(int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total weight: %d\n", total);
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for(int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for(int v = 0; v < V; v++) {
            if(graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}



typedef struct {
    int u, v, w;
} Edge;

int find(int parent[], int i) {
    if(parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    parent[x] = y;
}

void kruskalMST(Edge edges[], int E) {
    int parent[V];

    for(int i = 0; i < V; i++)
        parent[i] = i;

    // sort edges
    for(int i = 0; i < E - 1; i++) {
        for(int j = 0; j < E - i - 1; j++) {
            if(edges[j].w > edges[j+1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

    int total = 0;

    printf("\nKruskal MST:\nEdge \tWeight\n");

    for(int i = 0; i < E; i++) {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);

        if(x != y) {
            printf("%d - %d \t%d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            unionSet(parent, x, y);
        }
    }

    printf("Total weight: %d\n", total);
}

int main() {

    int graph[V][V] = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    primMST(graph);

    Edge edges[] = {
        {0,1,2},{0,3,6},{1,2,3},{1,3,8},
        {1,4,5},{2,4,7},{3,4,9}
    };

    kruskalMST(edges, 7);

    return 0;
}
