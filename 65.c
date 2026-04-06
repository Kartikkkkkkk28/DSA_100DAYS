#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
int dfs(int node, int parent, int adj[MAX][MAX], int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node, adj, n)) {
                    return 1;  // cycle found
                }
            }
            else if (i != parent) {
                return 1;  // cycle found
            }
        }
    }
    return 0;
}

int hasCycle(int n, int adj[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, n)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n = 5;

    // Adjacency matrix
    int adj[MAX][MAX] = {0};

    // edges (undirected)
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[4][1] = adj[1][4] = 1; // creates a cycle

    if (hasCycle(n, adj)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}