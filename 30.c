#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp   = exp;
    newNode->next  = NULL;
    return newNode;
}

void append(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
}

void printPolynomial(struct Node* head) {
    while (head != NULL) {
        if (head->exp == 0)
            printf("%d", head->coeff);
        else if (head->exp == 1)
            printf("%dx", head->coeff);
        else
            printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL)
            printf(" + ");

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
    int n, coeff, exp;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        append(&head, coeff, exp);
    }

    printPolynomial(head);
    freeList(head);
    return 0;
}
