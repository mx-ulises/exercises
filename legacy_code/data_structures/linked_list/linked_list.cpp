#include <iostream>

using namespace std;

template <class T> class Node {
    public:
        T item;
        Node<T> *next;

        Node<T>(T item) {
            this->item = item;
            this->next = NULL;
        }
};

template <class T> class MyLinkedList {
    private:
        Node<T> *head;

        Node<T> *predecessor(T item) {
            if (this->head == NULL) {
                return NULL;
            }
            Node<T> *current = this->head;
            while (current->next != NULL){
                if (current->next->item == item) {
                    return current;
                }
                current = current->next;
            }
            return NULL;
        }

    public:

        MyLinkedList<T>() {
            this->head = NULL;
        }

        MyLinkedList<T>(Node<T> *initial) {
            this->head = initial;
        }

        Node<T> *front() {
            return this->head;
        }

        Node<T> *search(T item){
            cout << "[INFO] Searching item '" << item << "'" << endl;
            Node<T> *current = this->head;
            while (current != NULL) {
                if (current->item == item) {
                    cout << "[INFO] Item '" << item << "' found" << endl;
                    return current;
                }
                current = current->next;
            }
            cout << "[ERROR] Item '" << item << "' not found" << endl;
            return NULL;
        }

        void insert(T item) {
            cout << "[INFO] Inserting item '" << item << "'" << endl;
            Node<T> *new_node = new Node<T>(item);
            new_node->next = this->head;
            this->head = new_node;
        }

        void remove(T item) {
            cout << "[INFO] Removing item '" << item << "'" << endl;
            if (this->head->item == item) {
                Node<T> *successor = head->next;
                delete this->head;
                this->head = successor;
            } else {
                Node<T> *predecessor = this->predecessor(item);
                if (predecessor != NULL) {
                    Node<T> *successor = predecessor->next->next;
                    delete predecessor->next;
                    predecessor->next = successor;
                } else {
                    cout << "[ERROR] Item '" << item << "' not found" << endl;
                }
            }
        }

        void print_list() {
            cout << "[INFO] Printing list" << endl;
            Node<T> *current = this->head;
            while (current != NULL) {
                cout << current->item << " ";
                current = current->next;
            }
            cout << endl;
        }
};
