// BST to Linked List (ADM-3.22)

#include <iostream>

using namespace std;

class LLNode{
    public:
        int data;
        LLNode* next;

        LLNode(int data) {
            this->data = data;
            this->next = NULL;
        }
};

LLNode* insert(LLNode* head, int data) {
    LLNode* new_head = new LLNode(data);
    new_head->next = head;
    return new_head;
}

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        void insert(int data) {
            if (data < this->data) {
                if (left == NULL) left = new Node(data);
                else left->insert(data);
            } else if (this->data < data) {
                if (right == NULL) right = new Node(data);
                else right->insert(data);
            }
        }

        Node* find(int data) {
            if (data == this->data) {
                return this;
            } else if (data < this->data) {
                if (left == NULL) return NULL;
                else return left->find(data);
            } else {
                if (right == NULL) return NULL;
                else return right->find(data);
            }
        }

        Node* max() {
            Node* current = this;
            while (current->right != NULL) {
                current = current->right;
            }
            return current;
        }

        Node* min() {
            Node* current = this;
            while (current->left != NULL) {
                current = current->left;
            }
            return current;
        }

        void inorder() {
            if (left != NULL) left->inorder();
            cout << data << " ";
            if (right != NULL) right->inorder();
        }

        void preorder() {
            cout << data << " ";
            if (left != NULL) left->preorder();
            if (right != NULL) right->preorder();
        }

        void posorder() {
            if (left != NULL) left->posorder();
            if (right != NULL) right->posorder();
            cout << data << " ";
        }

        void print(int h) {
            for (int i = 0; i < h; i++) {
                cout << " ";
            }
            cout << data << endl;
            if (left != NULL) left->print(h + 1);
            if (right != NULL) right->print(h + 1);
        }

};

LLNode* bst_to_ll(Node* root, LLNode* head) {
    if (root == NULL)
        return head;
    head = bst_to_ll(root->right, head);
    head = insert(head, root->data);
    head = bst_to_ll(root->left, head);
    return head;
}

void print_list(LLNode* head) {
    LLNode* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void test(int* A, int n) {
    Node root(A[0]);
    for (int i = 1; i < n; i++) {
        root.insert(A[i]);
    }
    root.print(0);
    LLNode* head = NULL;
    head = bst_to_ll(&root, head);
    print_list(head);
}

int main() {
    int A[] = {5, 6, 7, 1, 3, 8, 9, 2};
    test(A, 8);
    return 0;
}
