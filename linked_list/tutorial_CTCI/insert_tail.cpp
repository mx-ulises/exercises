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
