#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class BinarySearchTree {
    private:
        BinarySearchTree* most_left() {
            if (left == NULL) {
                return this;
            } else {
                return left->most_left();
            }
        }

        BinarySearchTree* most_right() {
            if (right == NULL) {
                return this;
            } else {
                return right->most_right();
            }
        }

        BinarySearchTree* get_pred(BinarySearchTree* node) {
            if (right == node || left == node) return this;
            else if (node->data < data) {
                node->left->get_pred(node);
            } else {
                node->right->get_pred(node);
            }
        }

        void remove_node_link(BinarySearchTree* node) {
            BinarySearchTree* pred = get_pred(node);
            if (pred->left == node) {
                pred->left = NULL;
            } else {
                pred->right = NULL;
            }
            delete node;
        }

    public:
        int data;
        BinarySearchTree* left;
        BinarySearchTree* right;

        BinarySearchTree(int value) {
            data = value;
            left = NULL;
            right = NULL;
        }

        BinarySearchTree* find(int value) {
            if (data == value) {
                return this;
            } else if (value < data && left != NULL) {
                return left->find(value);
            } else if (data < value && right != NULL) {
                return right->find(value);
            } else {
                return NULL;
            }
        }

        void insert(int value) {
            if (value < data) {
                if (left == NULL) {
                    left = new BinarySearchTree(value);
                } else {
                    left->insert(value);
                }
            } else if (data < value) {
                if (right == NULL) {
                    right = new BinarySearchTree(value);
                } else {
                    right->insert(value);
                }
            }
        }

        void print_tree(int h) {
            for (int i = 0; i < h; i++) {
                cout << "   ";
            }
            cout << data << endl;
            if (left != NULL) {
                left->print_tree(h + 1);
            }
            if (right != NULL) {
                right->print_tree(h + 1);
            }
        }

};

bool is_bst(BinarySearchTree* root, int minimal, int maximal) {
    if (root == NULL)
        return true;
    if (root->data < minimal || maximal < root->data)
        return false;
    return is_bst(root->left, minimal, root->data - 1) & is_bst(root->right, root->data + 1, maximal);
}

void insert(BinarySearchTree* bst, int data) {
    bst->insert(data);
    cout << "Insert: " << data << endl;
}

void validate(BinarySearchTree* bst) {
    int h = 0;
    cout << "Is BST: " << is_bst(bst, INT_MIN, INT_MAX) << endl;
}

int main() {
    BinarySearchTree bst(10);
    cout << "INIT: " << 10 << endl;
    insert(&bst, 2);
    insert(&bst, 3);
    insert(&bst, 4);
    insert(&bst, 1);
    insert(&bst, 21);
    insert(&bst, 12);
    insert(&bst, 14);
    insert(&bst, 40);
    insert(&bst, 50);
    cout << endl << "PRINT" << endl;
    bst.print_tree(0);
    validate(&bst);
    bst.data = 800;
    cout << endl << "PRINT" << endl;
    bst.print_tree(0);
    validate(&bst);
    return 0;
}
