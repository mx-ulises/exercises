#include <iostream>
#include "LinkedList.cpp"

using namespace std;

Node* get_last_k(Node* root, int k) {
    Node* runner = root;
    Node* current = root;
    int i = 0;
    if (k <= 0 || root == NULL)
        return NULL;
    while (runner != NULL && i < k) {
        i++;
        runner = runner->next;
    }
    if (i < k)
        return NULL;
    while (runner != NULL) {
        runner = runner->next;
        current = current->next;
    }
    return current;
}

void test(Node* root, int k) {
    cout << "Looking for last " << k << endl;
    Node* node = get_last_k(root, k);
    if (node != NULL) {
        cout << "Found " << node->data << endl;
    } else {
        cout << "Not found" << endl;
    }
}

int main() {
    LinkedList ll;
    int n = 8;
    for (int i = 0; i < n; i++) {
        ll.insert(n - i);
    }
    ll.print();
    test(ll.root, 0);
    test(ll.root, 1);
    test(ll.root, 4);
    test(ll.root, 8);
    test(ll.root, 9);
}
