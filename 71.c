#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];

void insert(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }
}

void search(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == EMPTY) {
            break;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    scanf("%d", &q);

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}