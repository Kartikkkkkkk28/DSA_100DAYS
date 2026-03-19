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
        newNode->next = *head;   // points to itself
        return;
    }
    struct Node* current = *head;
    while (current->next != *head)
        current = current->next;
    current->next = newNode;
    newNode->next = *head;       // last node points back to head
}

void traverse(struct Node* head) {
    if (head == NULL) return;
    struct Node* current = head;
    do {
        if (current->next != head)
            printf("%d ", current->data);
        else
            printf("%d", current->data);
        current = current->next;
    } while (current != head);   // stop when we reach head again
    printf("\n");
}

void freeList(struct Node* head) {
    if (head == NULL) return;
    struct Node* current = head->next;
    struct Node* temp;
    while (current != head) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    int n, val;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    traverse(head);
    freeList(head);
    return 0;
}