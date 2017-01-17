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
    Node* tail = new Node();
    tail->data = data;
    tail->next = NULL;
    if (head == NULL) {
        return tail;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = tail;
    return head;
}
