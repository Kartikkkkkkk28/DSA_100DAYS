#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    // Initialize matrix with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int directed;
    printf("Enter 1 for Directed, 0 for Undirected: ");
    scanf("%d", &directed);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if (!directed) {
            adj[v][u] = 1;
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}