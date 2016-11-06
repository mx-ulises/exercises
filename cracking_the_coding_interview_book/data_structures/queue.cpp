#include <iostream>

using namespace std;

class Node {
    public:
        Node* next;
        int data;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class Queue {
    private:
        Node* head;
        Node* tail;

    public:
        Queue() {
            head = NULL;
            tail = NULL;
        }

        int front() {
            if (head != NULL) {
                return head->data;
            }
            return -1;
        }

        void enqueue(int data) {
            Node* aux = new Node(data);
            if (head == NULL) {
                head = aux;
                tail = aux;
            } else {
                tail->next = aux;
                tail = tail->next;
            }
        }

        int dequeue() {
            if (tail == NULL) {
                return -1;
            }
            int data = head->data;
            Node* aux = head;
            if (head == tail) {
                tail = NULL;
                head = NULL;
            } else {
                head = head->next;
            }
            delete aux;
            return data;
        }
};

void insert(Queue* q, int data) {
    q->enqueue(data);
    cout << "ENQUEUE: " << data << ", FRONT: " << q->front() << endl;
}

void remove(Queue* q) {
    cout << "DEQUEUE: " << q->dequeue() << endl;
}

int main() {
    Queue q;
    insert(&q, 1);
    insert(&q, 2);
    insert(&q, 3);
    remove(&q);
    insert(&q, 4);
    remove(&q);
    remove(&q);
    remove(&q);
    remove(&q);
    return 0;
}
