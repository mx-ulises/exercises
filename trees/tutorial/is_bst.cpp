struct Node {
    int data;
    Node* left;
    Node* right;
};

bool check_bst(Node* node, int a, int b) {
    if (node == NULL)
        return true;
    int data = node->data;
    if (a <  data && data < b) {
        bool left_bst = check_bst(node->left, a, data);
        bool right_bst = check_bst(node->right, data, b);
        return left_bst && right_bst;
    }
    return false;

}

bool checkBST(Node* root) {
    return check_bst(root, -1, 10001);
}
