#include <iostream>

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
        BinarySearchTree* parent;

        BinarySearchTree(int value) {
            data = value;
            left = NULL;
            right = NULL;
            parent = NULL;
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
                    left->parent = this;
                } else {
                    left->insert(value);
                }
            } else if (data < value) {
                if (right == NULL) {
                    right = new BinarySearchTree(value);
                    right->parent = this;
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

BinarySearchTree* most_left(BinarySearchTree* node) {
    BinarySearchTree* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

BinarySearchTree* bigger_parent(BinarySearchTree* node) {
    BinarySearchTree* current = node;
    while (current->parent != NULL && current->parent->right == current) {
        current = current->parent;
    }
    return current->parent;
}

BinarySearchTree* succesor(BinarySearchTree* node) {
    if (node->right != NULL)
        return most_left(node->right);
    return bigger_parent(node);
}

void insert(BinarySearchTree* bst, int data) {
    bst->insert(data);
    cout << "Insert: " << data << endl;
}

void test(BinarySearchTree* bst, int data) {
    BinarySearchTree* node = bst->find(data);
    BinarySearchTree* succ = succesor(node);
    if (succ != NULL)
        cout << "The node '" << data << "' successor is node '" << succ->data << "'" << endl;
    else
        cout << "The node '" << data << "' has NO successor" << endl;
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
    test(&bst, 10);
    test(&bst, 2);
    test(&bst, 3);
    test(&bst, 4);
    test(&bst, 1);
    test(&bst, 21);
    test(&bst, 12);
    test(&bst, 14);
    test(&bst, 40);
    test(&bst, 50);
    return 0;
}
