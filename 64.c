#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// enqueue
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// dequeue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

int main() {
    int n, i, j, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    int visited[MAX] = {0};

    // BFS
    enqueue(s);
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}