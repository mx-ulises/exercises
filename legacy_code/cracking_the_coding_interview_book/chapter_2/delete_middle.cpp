#include <iostream>
#include "LinkedList.cpp"

using namespace std;

bool is_more_than_two(LinkedList* list) {
    Node* current = list->root;
    for (int i = 0; i <=2; i++) {
        if (current == NULL)
            return false;
        current = current->next;
    }
    return true;
}

void delete_middle_node(LinkedList* list) {
    if (!is_more_than_two(list))
        return;
    Node* middle = list->root->next;
    list->root->next = middle->next;
}

void delete_middle_node_2(Node* root) {
    if (root == NULL || root->next == NULL)
        return;
    Node* aux = root->next;
    root->data = aux->data;
    root->next = aux->next;
    delete aux;
}

void test(int n) {
    LinkedList* list = new LinkedList();
    for (int i = 0; i < n; i++) {
        list->insert(i + 1);
    }
    cout << "Before Delete:" << endl;
    list->print();
    delete_middle_node(list);
    cout << "After Delete:" << endl;
    list->print();
    cout << endl;
}

Node* get_k(LinkedList* list, int k) {
    Node* node = list->root;
    int i = 0;
    while (i < k && node != NULL) {
        node = node->next;
        i++;
    }
    return node;
}

void test_2(int n, int k) {
    LinkedList* list = new LinkedList();
    for (int i = 0; i < n; i++) {
        list->insert(i + 1);
    }
    Node* node = get_k(list, k);
    if (node != NULL)
        cout << "DELETE: " << node->data << endl;
    cout << "Before Delete:" << endl;
    list->print();
    delete_middle_node_2(node);
    cout << "After Delete:" << endl;
    list->print();
    cout << endl;
}

int main() {
    test(0);
    test(1);
    test(2);
    test(3);
    test(5);
    test(10);
    test_2(0, 1);
    test_2(1, 1);
    test_2(2, 0);
    test_2(3, 2);
    test_2(5, 3);
    test_2(10, 7);
    return 0;
}
