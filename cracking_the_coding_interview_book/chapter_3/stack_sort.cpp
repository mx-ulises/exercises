#include <stack>
#include <iostream>

using namespace std;

void put_max(stack<int>* s, stack<int>* aux, int c_max) {
    int count = 0;
    while (!s->empty()) {
        if (s->top() > c_max) {
            aux->push(c_max);
            c_max = s->top();
        } else {
            aux->push(s->top());
        }
        s->pop();
        count++;
    }
    for (int i = 0; i < count; i++) {
        s->push(aux->top());
        aux->pop();
    }
    aux->push(c_max);
}

stack<int>* stack_sort(stack<int>* s) {
    if (s->empty())
        return s;
    stack<int>* aux = new stack<int>();
    int current_max = s->top();
    s->pop();
    while (!s->empty()) {
        put_max(s, aux, current_max);
        current_max = s->top();
        s->pop();
    }
    aux->push(current_max);
    return aux;
}

void insert(stack<int>* s, int value) {
    cout << "Insertar " << value << endl;
    s->push(value);
}

int main() {
    stack<int>* s = new stack<int>();
    insert(s, 13);
    insert(s, 11);
    insert(s, 7);
    insert(s, 1);
    insert(s, 2);
    insert(s, 9);
    insert(s, 8);
    insert(s, 20);
    insert(s, 7);
    s = stack_sort(s);
    while (!s->empty()) {
        cout << s->top() << " ";
        s->pop();
    }
    cout << endl;
    return 0;
}
