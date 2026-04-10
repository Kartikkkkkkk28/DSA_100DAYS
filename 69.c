#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
struct Node {
    int v, weight;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];

// Min Heap Node
struct HeapNode {
    int node, dist;
};

// Priority Queue (Min Heap)
struct HeapNode heap[MAX];
int size = 0;

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int i) {
    while (i && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

// Pop min
struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra
void dijkstra(int V, int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        struct HeapNode curr = pop();
        int u = curr.node;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("Node %d -> %d\n", i, dist[i]);
}

// Driver
int main() {
    int V = 5;

    addEdge(0,1,10);
    addEdge(0,4,5);
    addEdge(1,2,1);
    addEdge(4,1,3);
    addEdge(4,2,9);
    addEdge(4,3,2);
    addEdge(3,2,4);
    addEdge(2,3,6);

    dijkstra(V, 0);

    return 0;
}