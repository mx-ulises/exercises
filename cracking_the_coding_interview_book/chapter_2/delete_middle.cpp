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
}

int main() {
    test(0);
    test(1);
    test(2);
    test(3);
    test(5);
    test(10);
    return 0;
}
