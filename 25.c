#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            count++;
        current = current->next;
    }
    return count;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, val, key;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    scanf("%d", &key);
    printf("%d\n", countOccurrences(head, key));
    freeList(head);
    return 0;
}

