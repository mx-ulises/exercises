#include <iostream>

using namespace std;

class BST {
    private:
        BST* most_left() {
            if (left == NULL) {
                return this;
            } else {
                return left->most_left();
            }
        }

        BST* most_right() {
            if (right == NULL) {
                return this;
            } else {
                return right->most_right();
            }
        }

        BST* get_pred(BST* node) {
            if (right == node || left == node) return this;
            else if (node->data < data) {
                node->left->get_pred(node);
            } else {
                node->right->get_pred(node);
            }
        }

        void remove_node_link(BST* node) {
            BST* pred = get_pred(node);
            if (pred->left == node) {
                pred->left = NULL;
            } else {
                pred->right = NULL;
            }
            delete node;
        }

    public:
        int data;
        BST* left;
        BST* right;

        BST(int value) {
            data = value;
            left = NULL;
            right = NULL;
        }

        BST* find(int value) {
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
                    left = new BST(value);
                } else {
                    left->insert(value);
                }
            } else if (data < value) {
                if (right == NULL) {
                    right = new BST(value);
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

BST* first_common_ancestor(BST* root, BST* a, BST* b, bool* a_found, bool* b_found) {
    if (root == NULL)
        return NULL;
    bool left_a, left_b, right_a, right_b;
    left_a = false;
    left_b = false;
    right_a = false;
    right_b = false;
    BST* ca = first_common_ancestor(root->left, a, b, &left_a, &left_b);
    if (ca != NULL)
        return ca;
    ca = first_common_ancestor(root->right, a, b, &right_a, &right_b);
    if (ca != NULL)
        return ca;
    (*a_found) = (a == root) || left_a || right_a;
    (*b_found) = (b == root) || left_b || right_b;
    if ((*a_found) && (*b_found))
        return root;
    return NULL;
}

BST* first_common_ancestor(BST* root, BST* a, BST* b) {
    bool a_found = false;
    bool b_found = false;
    return first_common_ancestor(root, a, b, &a_found, &b_found);
}

void insert(BST* bst, int data) {
    bst->insert(data);
    cout << "Insert: " << data << endl;
}

void test(BST* bst, int a_val, int b_val) {
    BST* a = bst->find(a_val);
    BST* b = bst->find(b_val);
    cout << "Common ancestor of " << a_val << " and " << b_val << endl;
    BST* ca = first_common_ancestor(bst, a, b);
    if (ca == NULL)
        cout << "Not Found" << endl;
    else
        cout << "Is " << ca->data << endl;
    cout << "==========================" << endl;
}

int main() {
    BST bst(10);
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
    insert(&bst, 11);
    bst.print_tree(0);
    cout << "==========================" << endl;
    test(&bst, 10, 50);
    test(&bst, 50, 14);
    test(&bst, 14, 11);
    test(&bst, 4, 50);
    return 0;
}
