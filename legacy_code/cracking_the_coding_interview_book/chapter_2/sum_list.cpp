#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int get_num(LinkedList* list) {
    int num = 0;
    int multiplier = 1;
    Node* current = list->root;
    while (current != NULL) {
        num += current->data * multiplier;
        multiplier *= 10;
        current = current->next;
    }
    return num;
}

LinkedList* get_list(int n) {
    Node* head = new Node(n % 10);
    n = n / 10;
    Node* current = head;
    while (0 < n) {
        current->next = new Node(n % 10);
        n = n / 10;
        current = current->next;
    }
    LinkedList* list = new LinkedList();
    list->root = head;
    return list;
}

LinkedList* sum_list(LinkedList* list_1, LinkedList* list_2) {
    int sum = get_num(list_1) + get_num(list_2);
    return get_list(sum);
}

void test(int n, int m) {
    LinkedList* list_1 = get_list(n);
    LinkedList* list_2 = get_list(m);
    list_1->print();
    list_2->print();
    LinkedList* list = sum_list(list_1, list_2);
    list->print();
    cout << endl;
}

int get_num_2(LinkedList* list) {
    Node* current = list->root;
    int num = 0;
    while (current != NULL) {
        num = num * 10 + current->data;
        current = current->next;
    }
    return num;
}

LinkedList* get_list_2(int n) {
    Node* head = new Node(n % 10);
    n = n / 10;
    while (0 < n) {
        Node* aux = new Node(n % 10);
        n = n / 10;
        aux->next = head;
        head = aux;
    }
    LinkedList* list = new LinkedList();
    list->root = head;
    return list;
}

LinkedList* sum_list_2(LinkedList* list_1, LinkedList* list_2) {
    int sum = get_num_2(list_1) + get_num_2(list_2);
    return get_list_2(sum);
}

void test_2(int n, int m) {
    LinkedList* list_1 = get_list_2(n);
    LinkedList* list_2 = get_list_2(m);
    list_1->print();
    list_2->print();
    LinkedList* list = sum_list_2(list_1, list_2);
    list->print();
    cout << endl;
}

int main() {
    test(0, 10);
    test(256, 3000);
    test(999, 1);
    test_2(0, 10);
    test_2(256, 3000);
    test_2(999, 1);
    return 0;
}
