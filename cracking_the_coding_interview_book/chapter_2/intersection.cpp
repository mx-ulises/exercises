#include <iostream>
#include <algorithm>
#include "LinkedList.cpp"

using namespace std;

Node* move(Node* root, int n) {
    Node* current = root;
    for (int i = 0; i < n; i++) {
        current = current->next;
    }
    return current;
}

Node* intersection (LinkedList* list_1, LinkedList* list_2) {
    if (list_1 == NULL || list_2 == NULL)
        return NULL;
    Node* root_1 = list_1->root;
    Node* root_2 = list_2->root;
    int delta = abs(list_1->size() - list_2->size());
    if(list_1->size() < list_2->size()) {
        root_2 = move(root_2, delta);
    } else {
        root_1 = move(root_1, delta);
    }
    while (root_1 != root_2) {
        root_1 = root_1->next;
        root_2 = root_2->next;
    }
    return root_1;
}

void insert_last(Node* root, Node* tail) {
    if (root == NULL) {
        return;
    }
    Node* current = root;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = tail;
}

LinkedList* new_list(int n, int k) {
    LinkedList* ll = new LinkedList();
    for (int i = 0; i < n; i++) {
        ll->insert(n - i + k);
    }
    return ll;
}

void test(LinkedList* list_1, LinkedList* list_2) {
    if(list_1->root != NULL) list_1->print();
    else cout << "NULL" << endl;
    if(list_2->root != NULL) list_2->print();
    else cout << "NULL" << endl;

    if (intersection(list_1, list_2) != NULL) {
        cout << "Intersect" << endl;
    } else {
        cout << "Not Intersect" << endl;
    }
    cout << "================================================" << endl << endl;
}

void test_tail(int n, int m) {
    LinkedList* list_1 = new_list(n, 0);
    LinkedList* list_2 = new_list(m, 100);
    insert_last(list_1->root, list_2->root);
    test(list_1, list_2);
}

void del(LinkedList* list) {
    Node* current = list->root;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    delete list;
}

void test_diff(int n, int m) {
    LinkedList* list_1 = new_list(n, 0);
    LinkedList* list_2 = new_list(m, 100);
    test(list_1, list_2);
}

int main() {
    test_tail(5, 19);
    test_tail(0, 19);
    test_tail(5, 0);
    test_diff(0, 0);
    test_diff(8, 5);
    test_diff(8, 10);
}
