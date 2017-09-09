struct Node {
    int data;
    struct Node* next;
};

Node* Reverse(Node *head) {
    if (head == NULL) return NULL;
    Node* prev = head;
    Node* current = head->next;
    prev->next = NULL;
    while (current != NULL) {
        Node* aux = current->next;
        current->next = prev;
        prev = current;
        current = aux;
    }
    return prev;
}
