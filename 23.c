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

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
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
    int n, m, val;
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&l1, val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        append(&l2, val);
    }

    struct Node* merged = mergeSorted(l1, l2);
    traverse(merged);
    freeList(merged);
    return 0;
}