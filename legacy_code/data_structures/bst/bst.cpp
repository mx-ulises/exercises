#include <iostream>

using namespace std;

template <class T> class Node {
    public:
        T data;
        Node<T>* left;
        Node<T>* right;

        Node<T>(T data) {
            this->data = data;
        }

        void insert(T data) {
            if (data < this->data) {
                if (left == NULL) left = new Node<T>(data);
                else left->insert(data);
            } else if (this->data < data) {
                if (right == NULL) right = new Node<T>(data);
                else right->insert(data);
            }
        }

        Node<T> find(T data) {
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

        Node<T> max() {
            Node<T>* current = this;
            while (current->right != NULL) {
                current = current->right;
            }
            return current;
        }

        Node<T> min() {
            Node<T>* current = this;
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
