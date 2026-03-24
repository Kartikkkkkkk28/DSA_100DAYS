#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert (keep array sorted)
void insert(int x) {
    if (size == MAX) return;

    int i = size - 1;

    // Shift elements to maintain sorted order
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

// Delete (remove highest priority → smallest element)
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    // Shift left
    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
}

// Peek (see highest priority)
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}