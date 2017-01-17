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
