#include <stdio.h>
#include <stdlib.h>

// ── Node definition ──────────────────────────────────────────
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// ── Helper: create a new node ─────────────────────────────────
Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data  = val;
    n->left  = n->right = NULL;
    return n;
}

// ── Build tree from level-order input (-1 = NULL) ─────────────
Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, back = 0, i = 1;

    Node* root = newNode(arr[0]);
    queue[back++] = root;

    while (front < back && i < n) {
        Node* curr = queue[front++];

        // Left child
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[back++] = curr->left;
            }
            i++;
        }

        // Right child
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newNode(arr[i]);
                queue[back++] = curr->right;
            }
            i++;
        }
    }

    free(queue);
    return root;
}

// ── Mirror check: are trees A and B mirror images? ────────────
int isMirror(Node* a, Node* b) {
    if (a == NULL && b == NULL) return 1;   // both absent → OK
    if (a == NULL || b == NULL) return 0;   // one absent   → NOT OK
    
    return (a->data == b->data)             // values match
        && isMirror(a->left,  b->right)     // outer pair
        && isMirror(a->right, b->left);     // inner pair
}

// ── Symmetric = root's children are mirrors of each other ─────
int isSymmetric(Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}

// ── Main ──────────────────────────────────────────────────────
int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    printf("%s\n", isSymmetric(root) ? "YES" : "NO");

    free(arr);
    return 0;
}