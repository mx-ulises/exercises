#include <iostream>
#include <set>
#include "LinkedList.cpp"

using namespace std;

void remove_dups(LinkedList* list) {
    Node* current = list->root;
    if (current == NULL)
        return;
    Node* next = current->next;
    set<int> unique;
    unique.insert(current->data);
    while (next != NULL) {
        if (unique.find(next->data) != unique.end()) {
            current->next = next->next;
            delete next;
        } else {
            unique.insert(next->data);
            current = next;
        }
        next = current->next;
    }
}

void remove_all_dups(Node* root) {
    Node* current = root;
    Node* next = current->next;
    int k = current->data;
    while (next != NULL) {
        if (next->data == k) {
            current->next = next->next;
            delete next;
        } else {
            current = next;
        }
        next = current->next;
    }
}

void remove_dups_2(LinkedList* list) {
    Node* current = list->root;
    while (current != NULL) {
        remove_all_dups(current);
        current = current->next;
    }
}

void test(int* A, int n) {
    LinkedList* list = new LinkedList();
    for (int i = 0; i < n; i++) {
        list->insert(A[i]);
    }
    list->print();
    remove_dups(list);
    list->print();
    cout << endl;
}

void test_2(int* A, int n) {
    LinkedList* list = new LinkedList();
    for (int i = 0; i < n; i++) {
        list->insert(A[i]);
    }
    list->print();
    remove_dups_2(list);
    list->print();
    cout << endl;
}

int main() {
    int A[] = {1, 2, 3, 2, 1};
    test(A, 5);
    test_2(A, 5);
    int B[] = {};
    test(B, 0);
    test_2(B, 0);
    int C[] = {1, 2, 2, 1};
    test(C, 4);
    test_2(C, 4);
    int D[] = {1, 2, 3, 2};
    test(D, 4);
    test_2(D, 4);
    int E[]  = {1, 2, 3, 2, 1, 7};
    test(E, 6);
    test_2(E, 6);
    return 0;
}
