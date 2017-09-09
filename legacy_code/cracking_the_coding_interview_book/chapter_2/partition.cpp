#include <iostream>
#include "LinkedList.cpp"

using namespace std;

void partition(LinkedList* list, int k) {
    Node* head = list->root;
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data < k) {
            Node* aux = current->next;
            current->next = aux->next;
            aux->next = head;
            head = aux;
        } else {
            current = current->next;
        }
    }
    list->root = head;
}

void test(int* A, int n, int k) {
    LinkedList* list = new LinkedList();
    for (int i = 0; i < n; i++) {
        list->insert(A[i]);
    }
    list->print();
    cout << "Partition: " << k << endl;
    partition(list, k);
    list->print();
    cout << endl;
}

int main() {
    int A[] = {1, 2, 3, 2, 1};
    test(A, 5, 2);
    int B[] = {};
    test(B, 0, 0);
    int C[] = {1, 4, 2, 1};
    test(C, 4, 3);
    int D[] = {1, 2, 3, 5};
    test(D, 4, 5);
    int E[]  = {1, 2, 3, 2, 1, 7};
    test(E, 6, 8);
    return 0;
}
