#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue for building tree
struct Node* q[1000];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    q[++rear] = node;
}

struct Node* dequeue() {
    return q[front++];
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue();

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzag(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[1000];
    int f = 0, r = -1;

    queue[++r] = root;

    int leftToRight = 1;

    while (f <= r) {
        int size = r - f + 1;
        int level[1000];

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[f++];

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = curr->data;

            if (curr->left)
                queue[++r] = curr->left;

            if (curr->right)
                queue[++r] = curr->right;
        }

        // Print current level
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        // Toggle direction
        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzag(root);

    return 0;
}