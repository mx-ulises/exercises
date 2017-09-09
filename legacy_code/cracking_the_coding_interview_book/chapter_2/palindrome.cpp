#include <iostream>
#include <stack>
#include "LinkedList.cpp"

using namespace std;

bool palindrome(LinkedList* list) {
    stack<int> reverse;
    Node* current = list->root;
    while (current != NULL) {
        reverse.push(current->data);
        current = current->next;
    }
    current = list->root;
    while (current != NULL) {
        if (current->data != reverse.top())
            return false;
        reverse.pop();
        current = current->next;
    }
    return true;
}

void test(int* A, int n) {
    LinkedList* list = new LinkedList();
    for (int i = 0; i < n; i++) {
        list->insert(A[i]);
    }
    list->print();
    cout << "Palindrome: " << palindrome(list) << endl;
}

int main() {
    int A[] = {1, 2, 3, 2, 1};
    test(A, 5);
    int B[] = {};
    test(B, 0);
    int C[] = {1, 2, 2, 1};
    test(C, 4);
    int D[] = {1, 2, 3, 2};
    test(D, 4);
    int E[]  = {1, 2, 3, 2, 1, 7};
    test(E, 6);
    return 0;
}
