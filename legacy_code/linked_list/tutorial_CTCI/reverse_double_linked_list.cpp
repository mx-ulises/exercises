struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

Node* swap(Node* node) {
    Node* aux = node->next;
    node->next = node->prev;
    node->prev = aux;
    return node;
}

Node* Reverse(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* prev = head;
    Node* next = head->next;
    prev = swap(prev);
    while (next != NULL) {
        prev = next;
        next = next->next;
        prev = swap(prev);
    }
    return prev;
}
