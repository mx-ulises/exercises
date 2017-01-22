struct Node {
    int data;
    Node* left;
    Node* right;
};

void print_left(Node* left) {
    if (left == NULL)
        return;
    print_left(left->left);
    cout << left->data << " ";
}

void print_right(Node* right) {
    if (right == NULL)
        return;
    cout << right->data << " ";
    print_right(right->right);
}

void top_view(Node* root) {
    if (root == NULL)
        return;
    print_left(root->left);
    cout << root->data << " ";
    print_right(root->right);
}
