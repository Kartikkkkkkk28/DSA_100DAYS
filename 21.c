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

void traverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->next != NULL)
            printf("%d ", current->data);
        else
            printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
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
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        append(&head, val);
    }

    traverse(head);
    freeList(head);
    return 0;
}