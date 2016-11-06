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

class Stack {
    private:
        Node* top_node;

    public:
        Stack() {
            top_node == NULL;
        }

        void push(int data) {
            Node* aux = new Node(data);
            aux->next = top_node;
            top_node = aux;
        }

        int top() {
            if (top_node != NULL) {
                return top_node->data;
            }
            return -1;
        }

        int pop() {
            if (top_node != NULL) {
                int data = top_node->data;
                Node* aux = top_node->next;
                delete top_node;
                top_node = aux;
                return data;
            }
            return -1;
        }
};

void insert(Stack* s, int data) {
    s->push(data);
    cout << "PUSH: " << s->top() << endl;
}

void remove(Stack* s) {
    cout << "POP: " << s->pop() << endl;
}

int main() {
    Stack s;
    insert(&s, 1);
    insert(&s, 2);
    insert(&s, 3);
    remove(&s);
    insert(&s, 4);
    remove(&s);
    remove(&s);
    remove(&s);
    remove(&s);
    return 0;
}
