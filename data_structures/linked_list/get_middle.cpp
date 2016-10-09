#include "linked_list.cpp"

using namespace std;

template <class T> Node<T> *get_middle(MyLinkedList<T> *list) {
    Node<T>* current = list->front();
    Node<T>* runner = list->front();
    if (current == NULL) return NULL;
    while (runner->next != NULL && runner->next->next != NULL) {
        current = current->next;
        runner = runner->next->next;
    }
    return current;
}



void test_list(int k) {
	MyLinkedList<int> list = MyLinkedList<int>();
	while (k > 0) {
		list.insert(k);
		k--;
    }
	Node<int>* middle = get_middle(&list);
	int value = -1;
	if (middle != NULL) {
		value = middle->item;
	}
	cout << "MID VALUE: " << value << endl;
}

int main() {
	test_list(0);
	test_list(1);
	test_list(5);
	test_list(7);
	test_list(8);
	test_list(10);
	test_list(15);
    return 0;
}
