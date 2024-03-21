#include <stdio.h>
#include <stdbool.h>
#define V 8  
+
int solutions = 0;  
int maxSolutions = 18; 

int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        solutions++;
        if (solutions > maxSolutions)
            return true;  
        printf("Solution %d:\n", solutions);
        for (int i = 0; i < V; i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
        printf("\n");
        return false;  
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }

    return false;
}

int graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("No more solutions found.\n");
        return false;
    }

    return true;
}

int main() {
    int graph[V][V];
    int m;

    // Taking input for the graph
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Taking input for the number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Taking input for the maximum number of solutions
    printf("Enter the maximum number of solutions: ");
    scanf("%d", &maxSolutions);

    graphColoring(graph, m);

    return 0;
}

