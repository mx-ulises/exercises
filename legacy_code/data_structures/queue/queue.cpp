#include <exception>
using namespace std;

class QueueException: public exception {

    virtual const char* what() const throw() {
        return "Queue exception";
    }

};


template <class T> class QueueNode {
    public:
        T data;
        QueueNode<T>* next;

        QueueNode<T>(T data){
            this->data = data;
            this->next = NULL;
        }

};


template <class T> class Queue {

    private:
        QueueNode<T>* head;
        QueueNode<T>* tail;

    public:

        bool empty() {
            if (head == NULL) {
                return true;
            }
            return false;
        }

        void enqueue(T data) {
            QueueNode<T>* node = new QueueNode<T>(data);
            if (this->empty()) {
                this->head = node;
                this->tail = node;
            } else {
                this->tail->next = node;
                this->tail = node;
            }
        }

        T dequeue() {
            if (this->empty()) {
                throw QueueException();
            }
            QueueNode<T>* node = this->head;
            this->head = this->head->next;
            T data = node->data;
            delete node;
            if (this->head == NULL) {
                this->tail = NULL;
            }
            return data;
        }

        T front() {
            if (this->empty()) {
                throw QueueException();
            }
            return this->head->data;
        }

};
