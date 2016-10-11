struct Node {
    int data;
    Node* left;
    Node* right;
};

bool check_BST_limit(Node* root, int minimal, int maximal) {
    if (root == NULL) return true;
    if (minimal < root->data && root->data < maximal){
        return check_BST_limit(root->left, minimal, root->data) &&
            check_BST_limit(root->right, root->data, maximal);
    }
    return false;
}

bool checkBST(Node* root) {
    return check_BST_limit(root, -1, 10001);
}
