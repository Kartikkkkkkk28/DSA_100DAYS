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

// Build actual intersection by linking l2's tail to matching node in l1
struct Node* buildIntersection(struct Node* l1, struct Node* l2) {
    struct Node* curr2 = l2;
    while (curr2->next != NULL)
        curr2 = curr2->next;

    struct Node* curr1 = l1;
    while (curr1 != NULL) {
        if (curr1->data == curr2->data) {
            // should not happen for tail, find common start
            break;
        }
        curr1 = curr1->next;
    }

    // Link l2's tail to l1's node with same value as l2's first common element
    curr2 = l2;
    while (curr2->next != NULL)
        curr2 = curr2->next;

    // Find node in l1 matching l2's first element that also exists in l1
    struct Node* intersectNode = NULL;
    struct Node* temp2 = l2;
    while (temp2 != NULL) {
        struct Node* temp1 = l1;
        while (temp1 != NULL) {
            if (temp1->data == temp2->data) {
                intersectNode = temp1;
                curr2->next = temp1;
                return intersectNode;
            }
            temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }
    return NULL;
}

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* l1, struct Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);

    // Advance the longer list
    while (len1 > len2) { l1 = l1->next; len1--; }
    while (len2 > len1) { l2 = l2->next; len2--; }

    // Move both until they meet
    while (l1 != NULL && l2 != NULL) {
        if (l1 == l2)
            return l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    return NULL;
}

void freeList(struct Node* head, struct Node* intersect) {
    struct Node* temp;
    while (head != NULL && head != intersect) {
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

    // Build real pointer-level intersection
    struct Node* intersectNode = buildIntersection(l1, l2);

    struct Node* result = findIntersection(l1, l2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    // Free only non-shared parts
    freeList(l1, intersectNode);
    freeList(l2, intersectNode);
    freeList(intersectNode, NULL);
    return 0;
}

