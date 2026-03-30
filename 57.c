#include <stdio.h>
#include <stdlib.h>

// ── Node definition ───────────────────────────────────────────
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

        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[back++] = curr->left;
            }
            i++;
        }
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

// ── Mirror: swap left/right at every node (post-order) ────────
void mirror(Node* root) {
    if (root == NULL) return;

    mirror(root->left);          // process left subtree
    mirror(root->right);         // process right subtree

    // swap children
    Node* temp    = root->left;
    root->left    = root->right;
    root->right   = temp;
}

// ── Inorder traversal: Left → Root → Right ───────────────────
void inorder(Node* root, int* first) {
    if (root == NULL) return;
    inorder(root->left, first);
    if (*first) { printf(" "); }
    printf("%d", root->data);
    *first = 1;
    inorder(root->right, first);
}

// ── Main ──────────────────────────────────────────────────────
int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    mirror(root);

    int first = 0;
    inorder(root, &first);
    printf("\n");

    free(arr);
    return 0;
}