#include <stack>
#include "linked_list.cpp"

using namespace std;

template <class T> Node<T> *return_last(MyLinkedList<T> *list, int k) {
    if (k <= 0) {
        return NULL;
    }
    stack<Node<T>*> s;
    Node<T> *current = list->front();
    while (current != NULL) {
        s.push(current);
        current = current->next;
    }
    while (!s.empty()) {
        k--;
        if (k == 0) {
            return s.top();
        }
        s.pop();
    }
    return NULL;
}


template <class T> Node<T> *return_last_runner(MyLinkedList<T> *list, int k) {
    if (k <= 0) {
        return NULL;
    }
    Node<T> *current = list->front();
    Node<T> *runner = list->front();
    while (runner != NULL && k > 0) {
        runner = runner->next;
        k--;
    }
    if (k > 0) {
        return NULL;
    }
    while (runner != NULL) {
        runner = runner->next;
        current = current->next;
    }
    return current;
}

template <class T> void print_last_k(MyLinkedList<T> *list, int k) {
    Node<T> *element = return_last_runner(list, k);
    cout << "Looking for last " << k << "th" << endl;
    if (element == NULL) {
        cout << "Invalid index" << endl;
    } else {
        cout << "Element found '" << element->item << "'" << endl;
    }
}

int main() {
    MyLinkedList<int> list = MyLinkedList<int>();
    list.insert(6);
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    list.print_list();
    print_last_k(&list, 1);
    print_last_k(&list, 0);
    print_last_k(&list, 6);
    print_last_k(&list, 7);
    print_last_k(&list, 100);
    print_last_k(&list, -1);
    print_last_k(&list, 2);
    return 0;
}
