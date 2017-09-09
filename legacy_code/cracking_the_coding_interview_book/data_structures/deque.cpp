#include <iostream>

using namespace std;

class Node {
    public:
        Node* next;
        Node* prev;
        int data;

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class Deque {
    private:
        Node* head;
        Node* tail;

    public:
        Deque() {
            head = NULL;
            tail = NULL;
        }

        int front() {
            return head->data;
        }

        int top() {
            return tail->data;
        }

        void enqueue(int data) {
            if (head == NULL) {
                head = new Node(data);
                tail = head;
            } else {
                Node* aux = new Node(data);
                aux->next = head;
                head->prev = aux;
                head = aux;
            }
        }

        void push(int data) {
            if (tail == NULL) {
                tail = new Node(data);
                head = tail;
            } else {
                Node* aux = new Node(data);
                tail->next = aux;
                aux->prev = tail;
                tail = tail->next;
            }
        }

        int dequeue() {
            int exit_value = head->data;
            Node* aux = head;
            head = head->next;
            if (head == NULL) {
                tail = NULL;
            } else {
                head->prev = NULL;
            }
            delete aux;
            return exit_value;
        }

        int pop() {
            int exit_value = tail->data;
            Node* aux = tail;
            tail = tail->prev;
            if (tail == NULL) {
                head = NULL;
            } else {
                tail->next = NULL;
            }
            delete aux;
            return exit_value;
        }
};


void print(Deque* dq) {
    cout << "front: " << dq->front() << ", top: " << dq->top() << endl;
}

void push(Deque* dq, int data) {
    dq->push(data);
    print(dq);
}

void pop(Deque* dq) {
    dq->pop();
    print(dq);
}

void enqueue(Deque* dq, int data) {
    dq->enqueue(data);
    print(dq);
}

void dequeue(Deque* dq) {
    dq->dequeue();
    print(dq);
}

int main() {
    Deque* dq = new Deque();
    push(dq, 10);
    push(dq, 30);
    enqueue(dq, 5);
    enqueue(dq, 1);
    pop(dq);
    dequeue(dq);
    pop(dq);
    return 0;
}
