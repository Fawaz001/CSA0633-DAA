#include <stdio.h>
#include <stdlib.h> 
struct Edge {
    int src, dest, weight;
}; 
struct Subset {
    int parent, rank;
}; 
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
} 
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
} 
int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
} 
void mstKruskal(struct Edge edges[], int V, int E) { 
    struct Edge* mst = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));
    if (mst == NULL) {
        printf("Memory allocation failed\n");
        return;
    } 
    qsort(edges, E, sizeof(struct Edge), compare);
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    if (subsets == NULL) {
        printf("Memory allocation failed\n");
        free(mst);
        return;
    } 
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    } 
    int mstIndex = 0;
    int edgeIndex = 0; 
    while (mstIndex < V - 1) {
        struct Edge nextEdge = edges[edgeIndex++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
 
        if (x != y) {
            mst[mstIndex++] = nextEdge;
            unionSets(subsets, x, y);
        }
    } 
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < mstIndex; i++) {
        printf("%d - %d\tWeight: %d\n", mst[i].src, mst[i].dest, mst[i].weight);
    } 
    free(mst);
    free(subsets);
}
int main() {
    int V = 4;  
    int E = 5; 
 
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
mstKruskal(edges, V, E);
return 0;
}
