/*
    Insert Node at the end of a linked list
    head pointer input could be NULL as well for empty list
    Node is defined as
*/

struct Node {
    int data;
    struct Node* next;
};

Node* Insert(Node* head, int data) {
    Node* new_head = new Node();
    new_head->data = data;
    new_head->next = head;
    return new_head;
}
