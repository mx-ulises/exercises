#include <algorithm>
#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        int height;
        Node* left;
        Node* right;


        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
            height = 0;
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

class AVLTree {
    private:
        Node* head;

        int get_height(Node* root) {
            if (root == NULL) return -1;
            return root->height;
        }

        void calculate_height(Node* root) {
            int left_height = get_height(root->left);
            int right_height = get_height(root->right);
            root->height = (max(left_height, right_height) + 1);
        }

        Node* left_rotation(Node* root) {
            Node* aux = root->left;
            root->left = aux->right;
            aux->right = root;
            calculate_height(root);
            calculate_height(aux);
            return aux;
        }

        Node* right_rotation(Node* root) {
            Node* aux = root->right;
            root->right = aux->left;
            aux->left = root;
            calculate_height(root);
            calculate_height(aux);
            return aux;
        }

        int get_balance_factor(Node* root) {
            return get_height(root->left) - get_height(root->right);
        }

        Node* balance(Node* root) {
            int balance_factor = get_balance_factor(root);
            //cout << "balance: " << balance_factor << endl;
            if (balance_factor == 2) {
                if (get_balance_factor(root->left) == -1)
                    root->left = right_rotation(root->left);
                root = left_rotation(root);
            } else if (balance_factor == -2) {
                if (get_balance_factor(root->right) == 1)
                    root->right = left_rotation(root->right);
                root = right_rotation(root);
            }
            return root;
        }

    public:
        AVLTree(int data) {
            head = new Node(data);
        }

        void insert(int data) {
            head = insert(head, data);
            cout << "Insert: " << data << endl;
            cout << "New head: " << head->data << endl;
        }

        Node* insert(Node* node, int data) {
            if (data < node->data) {
                if (node->left == NULL) node->left = new Node(data);
                else node->left = insert(node->left, data);
            } else if (node->data < data) {
                if (node->right == NULL) node->right = new Node(data);
                else node->right = insert(node->right, data);
            }
            calculate_height(node);
            node = balance(node);
            return node;
        }

        void print_tree() {
            head->print_tree(0);
            cout << endl;
        }
};

int main() {
    AVLTree tree(1);
    cout << "INIT: " << 1 << endl;
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.insert(15);
    tree.print_tree();
    /**/
    return 0;
}
