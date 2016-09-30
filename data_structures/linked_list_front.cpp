#include <exception>
using namespace std;

class OutOfBoundException: public exception {

    virtual const char* what() const throw() {
        return "Out of bound exception";
    }

};

template <class T> class Node {
    public:
        T data;
        Node<T>* succesor;

        Node(T data) {
            this->data = data;
            this->succesor = NULL;
        }

};

template <class T> class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

    public:
        LinkedList() {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }

        bool is_empty() {
            if (this->head == NULL) {
                return true;
            }
            return false;
        }

        void insert(T data) {
            Node<T>* element = new Node<T>(data);
            if (this->head == NULL) {
                this->head = element;
                this->tail = element;
            } else {
                this->tail->succesor = element;
                this->tail = this->tail->succesor;
            }
            this->size++;
        }

        void remove(int index) {
            if (this->size == 0 || index < 0 || this->size <= index) {
                throw OutOfBoundException();
            } else {
                if (index > 1) {
                    Node<T>* prev = this->head;
                    Node<T>* current = prev->succesor;
                    while (index > 0) {
                        prev = current;
                        current = current->succesor;
                    }
                    prev->succesor = current->succesor;
                } else {
                    this->head = this->head->succesor;
                }
                if (this->size == 1) {
                    this->tail = NULL;
                }
                this->size--;
            }
        }

        void remove() {
            remove(0);
        }

        T front() {
            return this->head->data;
        }

        T top() {
            return this->tail->data;
        }

        void print_list() {
            Node<T>* element = this->head;
            while (element != NULL) {
                cout << element->data << " ";
            }
        }

};
