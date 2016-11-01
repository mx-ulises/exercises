#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
        }

        void print() {
            Node* current = this;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

class LinkedList {
    private:
        int n;
    public:
        Node* root;

        void insert(int data) {
            if (root == NULL) {
                root = new Node(data);
            } else {
                Node* aux = root;
                root = new Node(data);
                root->next = aux;
            }
            n++;
        }

        int size() {
            return n;
        }

        void print() {
            if (root != NULL) {
                root->print();
            }
        }

        Node* search(int data) {
            if (root == NULL)
                return NULL;
            Node* current = root;
            while (current != NULL) {
                if (current->data == data)
                    return current;
                current = current->next;
            }
            return NULL;
        }

};
