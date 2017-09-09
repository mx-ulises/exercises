#include <iostream>
#include <algorithm>

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

bool check_balance(BinarySearchTree* root, int* h) {
    if (root == NULL)
        return true;
    int left_h = 0;
    int right_h = 0;
    bool balanced = check_balance(root->left, &left_h) & check_balance(root->right, &right_h);
    int delta = left_h - right_h;
    if (delta < -1 || 1 < delta)
        balanced = false;
    (*h) = max(left_h, right_h) + 1;
    return balanced;
}

void insert(BinarySearchTree* bst, int data) {
    bst->insert(data);
    cout << "Insert: " << data << endl;
}

void balance(BinarySearchTree* bst) {
    int h = 0;
    cout << "Balance: " << check_balance(bst, &h) << endl;
    cout << "Height: " << h << endl;
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
    balance(&bst);
    insert(&bst, 60);
    cout << endl << "PRINT" << endl;
    bst.print_tree(0);
    balance(&bst);
    return 0;
}
