struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

Node* create_node(int data) {
    Node* node = new Node();
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    return node;
}

Node* SortedInsert(Node* head, int data) {
    Node* node = create_node(data);
    if (head == NULL) {
        return node;
    }
    if (node->data < head->data) {
        head->prev = node;
        node->next = head;
        return node;
    }
    Node* current = head->next;
    Node* prev = head;
    while (current != NULL && current->data < node->data) {
        prev = current;
        current = current->next;
    }
    prev->next = node;
    node->prev = prev;
    if (current != NULL) {
        current->prev = node;
        node->next = current;
    }
    return head;
}
