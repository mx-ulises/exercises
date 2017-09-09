#include <iostream>
#include "LinkedList.cpp"

using namespace std;

Node* get_cycle(LinkedList* list) {
    if (list->root == NULL)
        return NULL;
    Node* slow = list->root;
    Node* fast = slow->next;
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast)
            return slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return NULL;
}

Node* get_k(LinkedList* list, int k) {
    if (k < 0)
        return NULL;
    Node* node = list->root;
    int i = 0;
    while (i < k && node != NULL) {
        node = node->next;
        i++;
    }
    return node;
}

void test(int n, int k) {
    LinkedList* list = new LinkedList();
    for (int i = 0; i < n; i++) {
        list->insert(n - i);
    }
    list->print();
    Node* cycle_node = get_k(list, k);
    Node* tail = get_k(list, n - 1);
    if (tail != NULL) {
        tail->next = cycle_node;
        cout << "Set cycle at " << tail->data << endl;
    }
    cycle_node = get_cycle(list);
    if (cycle_node != NULL)
        cout << "Cycle detected at: " << cycle_node->data << endl;
    else
        cout << "No cycle detected" << endl;
    cout << endl;
}

int main() {
    test(0, -1);
    test(1, -1);
    test(1, 0);
    test(6, 4);
    test(6, 5);
    test(6, -1);
    test(7, 4);
    test(7, 5);
    test(7, -1);
    return 0;
}
