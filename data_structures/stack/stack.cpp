#include <exception>
using namespace std;

class StackException: public exception {

    virtual const char* what() const throw() {
        return "Stack exception";
    }

};

template <class T> class StackNode {
    public:
        T data;
        StackNode<T>* next;

        StackNode<T> (T data) {
            this->data = data;
            this->next = NULL;
        }

};

template <class T> class Stack {

    private:
        StackNode<T>* head;

    public:

        bool empty() {
            if (this->head == NULL) {
                return true;
            }
            return false;
        }

        T top() {
            if (this->empty()) {
                throw StackException();
            }
            return this->head->data;
        }

        T pop() {
            if (this->empty()) {
                throw StackException();
            }
            StackNode<T>* node = this->head;
            this->head = this->head->next;
            T data = node->data;
            delete node;
            return data;
        }

        void push(T data) {
            StackNode<T>* node = new StackNode<T>(data);
            node->next = this->head;
            this->head = node;
        }
};

