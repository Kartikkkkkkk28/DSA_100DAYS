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

void deleteKey(struct Node** head, int key) {
    if (*head == NULL) return;

    // Case 1: head node is the key
    if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Case 2: search in rest of the list
    struct Node* prev = *head;
    struct Node* current = (*head)->next;

    while (current != NULL) {
        if (current->data == key) {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void traverse(struct Node* head) {
    while (head != NULL) {
        if (head->next != NULL)
            printf("%d ", head->data);
        else
            printf("%d", head->data);
        head = head->next;
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
    int n, val, key;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    scanf("%d", &key);
    deleteKey(&head, key);
    traverse(head);
    freeList(head);
    return 0;
}