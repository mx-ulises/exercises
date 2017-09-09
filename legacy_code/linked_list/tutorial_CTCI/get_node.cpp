struct Node {
    int data;
    struct Node* next;
};

int size(Node* head) {
    int n = 0;
    Node* current = head;
    while (current != NULL) {
        current = current->next;
        n++;
    }
    return n;
}

int get_node(Node* head, int position_from_tail) {
    int position = size(head) - position_from_tail - 1;
    Node* current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current->data;
}
