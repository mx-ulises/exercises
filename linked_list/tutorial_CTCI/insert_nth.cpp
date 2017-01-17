struct Node {
    int data;
    struct Node* next;
};

Node* InsertNth(Node* head, int data, int position)
{
    Node* new_node = new Node();
    new_node->data = data;
    if (position == 0) {
        new_node->next = head;
        return new_node;
    }
    int i = 1;
    Node* current = head;
    while (i < position) {
        current = current->next;
        i++;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}
