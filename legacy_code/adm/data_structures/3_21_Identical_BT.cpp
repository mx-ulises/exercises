// Check identical trees (ADM-3.21)

#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
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

};

bool identical_bst(Node* A, Node* B) {
	if (A == NULL && B == NULL) {
		return true;
	} else if (A == NULL || B == NULL) {
		return false;
	} else if (A->data != B->data) {
		return false;
	} else {
		return (identical_bst(A->left, B->left) && identical_bst(A->right, B->right));
	}
}
