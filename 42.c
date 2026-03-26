#include <stdio.h>

#define MAX 1000

// Queue structure
int queue[MAX];
int front = 0, rear = -1;

// Stack structure
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);

    // Input queue elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue to stack
    while (front <= rear) {
        push(queue[front++]);
    }

    // Step 2: Pop from stack (reversed order)
    while (top != -1) {
        printf("%d ", pop());
    }

    return 0;
}