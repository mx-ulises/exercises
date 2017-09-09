#include "linked_list.cpp"

int main() {
    MyLinkedList<int> list = MyLinkedList<int>();
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.search(3);
    list.print_list();
    list.remove(3);
    list.print_list();
    list.remove(3);
    list.print_list();
    list.remove(5);
    list.print_list();
    list.search(1);
    list.search(3);
    list.search(6);
    list.search(2);
    return 0;
}
