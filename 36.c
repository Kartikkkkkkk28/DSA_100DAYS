#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        // Queue Full (not needed here usually)
        return;
    }

    if (front == -1) { // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
}

// Dequeue
void dequeue() {
    if (front == -1) {
        return;
    }

    if (front == rear) { // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if (front == -1) return;

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    // number of elements
    scanf("%d", &n);

    // enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // number of dequeues
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}