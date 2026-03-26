#include <stdio.h>
#include <stdlib.h>

// Tree Node
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

// Queue for tree construction
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

// Pair for BFS (node + HD)
struct Pair {
    struct Node* node;
    int hd;
};

struct Pair queue2[1000];
int f2 = 0, r2 = -1;

void push(struct Node* node, int hd) {
    queue2[++r2].node = node;
    queue2[r2].hd = hd;
}

struct Pair pop() {
    return queue2[f2++];
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // Range of HD
    int minHD = 0, maxHD = 0;

    // Storage
    int result[200][200];
    int count[200] = {0};

    // BFS
    f2 = 0; r2 = -1;
    push(root, 0);

    while (f2 <= r2) {
        struct Pair p = pop();
        struct Node* curr = p.node;
        int hd = p.hd;

        int index = hd + 100; // shift for negative

        result[index][count[index]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            push(curr->left, hd - 1);

        if (curr->right)
            push(curr->right, hd + 1);
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + 100;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", result[idx][j]);
        }
        printf("\n");
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

    verticalOrder(root);

    return 0;
}