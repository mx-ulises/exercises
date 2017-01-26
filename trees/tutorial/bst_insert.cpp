struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* new_node(int value) {
	Node* node = new node();
	node->data = value;
	node->right = NULL;
	node->left = NULL;
    return node;
}

Node* insert(Node* root, int value) {
	Node* node = new_node(value);
    if (root == NULL) {
        root = node;
    }
    Node* current = root;
    bool find = false;
    while (!find) {
        if (value < current->data) {
            if (current->left == NULL) {
                current->left = node;
                find = true;
            }
            current = current->left;
        } else if (current->data < value) {
            if (current->right == NULL) {
                current->right = node;
                find = true;
            }
            current = current->right;
        } else {
            find = true;
        }
    }
    return root;
}
