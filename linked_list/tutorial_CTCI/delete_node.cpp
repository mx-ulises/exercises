struct Node {
    int data;
    struct Node* next;
};

Node* Delete(Node* head, int position) {
    if (position == 0) {
        Node* aux = head->next;
        delete head;
        return aux;
    }
    Node* prev = head;
    Node* current = head->next;
    while (1 < position) {
        prev = prev->next;
        current = current->next;
        position--;
    }
    prev->next = current->next;
    delete current;
    return head;
}
