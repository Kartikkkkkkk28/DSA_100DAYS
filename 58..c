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

// ── Find index of value in inorder array ──────────────────────
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

// ── Recursive build ───────────────────────────────────────────
//  preorder : full preorder array
//  preStart : current root index in preorder
//  inorder  : full inorder array
//  inStart  : left boundary of current subtree in inorder
//  inEnd    : right boundary of current subtree in inorder
Node* build(int* preorder, int preStart,
            int* inorder,  int inStart, int inEnd) {

    if (inStart > inEnd) return NULL;   // no elements left

    // 1. Root is always the current preorder element
    int rootVal = preorder[preStart];
    Node* root  = newNode(rootVal);

    // 2. Find root in inorder → splits left and right
    int inRoot  = findIndex(inorder, inStart, inEnd, rootVal);
    int leftSize = inRoot - inStart;   // number of nodes in left subtree

    // 3. Recurse
    //    Left  subtree preorder starts at preStart + 1
    //    Right subtree preorder starts at preStart + leftSize + 1
    root->left  = build(preorder, preStart + 1,
                        inorder,  inStart,       inRoot - 1);

    root->right = build(preorder, preStart + leftSize + 1,
                        inorder,  inRoot + 1,    inEnd);

    return root;
}

// ── Postorder: Left → Right → Root ───────────────────────────
void postorder(Node* root, int* first) {
    if (root == NULL) return;
    postorder(root->left,  first);
    postorder(root->right, first);
    if (*first) printf(" ");
    printf("%d", root->data);
    *first = 1;
}

// ── Main ──────────────────────────────────────────────────────
int main() {
    int n;
    scanf("%d", &n);

    int* pre = (int*)malloc(n * sizeof(int));
    int* in  = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    Node* root = build(pre, 0, in, 0, n - 1);

    int first = 0;
    postorder(root, &first);
    printf("\n");

    free(pre);
    free(in);
    return 0;
}