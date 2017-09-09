#include <set>
#include "linked_list.cpp"

using namespace std;

// This is processing Efficient (O(n)) but memory inefficient (O(n))
template <class T> MyLinkedList<T> *remove_duplicates(MyLinkedList<T> *list) {
    set<T> unique;
    MyLinkedList<T> *new_list = new MyLinkedList<T>();
    Node<T> *current = list->front();
    while (current != NULL) {
        unique.insert(current->item);
        current = current->next;
    }
    for (typename set<T>::iterator it = unique.begin(); it != unique.end(); ++it) {
        new_list->insert(*it);
    }
    return new_list;
}

// This is Memory Efficient (O(1)) but processing inefficient (O(n^2))
template <class T> MyLinkedList<T> *remove_duplicates_2(MyLinkedList<T> *list) {
    MyLinkedList<T> *new_list = new MyLinkedList<T>();
    Node<T> *current = list->front();
    while (current != NULL) {
        if (new_list->search(current->item) == NULL) {
            new_list->insert(current->item);
        }
        current = current->next;
    }
    return new_list;
}

int main() {
    MyLinkedList<int> list = MyLinkedList<int>();
    list.insert(1);
    list.insert(2);
    list.insert(8);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(1);
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.insert(6);
    list.insert(6);
    list.insert(7);
    list.print_list();
    MyLinkedList<int> *new_list = remove_duplicates(&list);
    new_list->print_list();
    delete new_list;
    new_list = remove_duplicates_2(&list);
    new_list->print_list();
    return 0;
}
