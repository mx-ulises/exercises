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

BinarySearchTree* add_node(BinarySearchTree* root, int data) {
    if (root == NULL)
        root = new BinarySearchTree(data);
    else
        root->insert(data);
    return root;
}

BinarySearchTree* fill_tree(BinarySearchTree* root, int* A, int begin, int end) {
    if (begin == end) {
        root = add_node(root, A[begin]);
    } else if (begin < end) {
        int mid = (begin + end) / 2;
        root = add_node(root, A[mid]);
        root = fill_tree(root, A, begin, mid - 1);
        root = fill_tree(root, A, mid + 1, end);
    }
    return root;
}

BinarySearchTree* fill_tree(int* A, int n) {
    BinarySearchTree* root = NULL;
    root = fill_tree(root, A, 0, n - 1);
    return root;
}

void test(int* A, int n) {
    cout << "List of nodes" << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl << endl;
    BinarySearchTree* root = fill_tree(A, n);
    cout << "Printing tree" << endl;
    root->print_tree(0);
    cout << endl << "----------------------------------" << endl;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    test(A, 5);
    int B[] = {1};
    test(B, 1);
    int C[] = {1, 2, 3, 4};
    test(C, 4);
    int D[] = {1, 2, 3, 4, 5, 6, 7};
    test(D, 7);
    return 0;
}
