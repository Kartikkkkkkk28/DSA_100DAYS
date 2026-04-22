#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX   // Represents "no path exists"

void floydWarshall(long long dist[][MAX], int n) {
    // Try every vertex as an intermediate point
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Only update if both segments i->k and k->j are reachable
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    long long dist[MAX][MAX];

    // Build the initial distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);

            if (val == -1 && i != j) {
                dist[i][j] = INF;   // No direct edge
            } else {
                dist[i][j] = val;   // Direct edge weight (or 0 for diagonal)
            }
        }
    }

    floydWarshall(dist, n);

    // Print the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            if (dist[i][j] == INF)
                printf("-1");       // Still unreachable after all relaxations
            else
                printf("%lld", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}