#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d", &n);   // number of vertices
    scanf("%d", &m);   // number of edges

    // Array of adjacency lists
    struct Node* adj[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add v to u's list
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // For undirected graph, also add u to v's list
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // Print adjacency list
    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}