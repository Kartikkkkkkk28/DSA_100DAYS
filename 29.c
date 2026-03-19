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

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0) return head;

    // Step 1: find length and tail
    int len = 1;
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    // Step 2: normalize k
    k = k % len;
    if (k == 0) return head;

    // Step 3: form circular list
    tail->next = head;

    // Step 4: find new tail at (len - k - 1) steps from head
    int steps = len - k - 1;
    struct Node* newTail = head;
    for (int i = 0; i < steps; i++)
        newTail = newTail->next;

    // Step 5: new head is next of new tail
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
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
    int n, val, k;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    scanf("%d", &k);
    head = rotateRight(head, k);
    traverse(head);
    freeList(head);
    return 0;
}