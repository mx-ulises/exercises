#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* lca_2(Node* root, int a, int b) {
    if (root == NULL)
        return NULL;
    if (a == root->data || b == root->data)
        return root;
    else if (b < root->data)
        return lca_2(root->left, a, b);
    else if (root->data < a)
        return lca_2(root->right, a, b);
    else
        return root;
}

Node* lca(Node* root, int a,int b) {
    return lca_2(root, min(a, b), max(a, b));
}
