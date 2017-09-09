struct Node {
    int data;
    struct Node* next;
};

int CompareLists(Node* head_a, Node* head_b) {
    if (head_a == NULL && head_b == NULL)
        return 1;
    while (head_a != NULL && head_b != NULL) {
        if (head_a->data != head_b->data)
            return 0;
        head_a = head_a->next;
        head_b = head_b->next;
    }
    if (head_a != NULL || head_b != NULL)
        return 0;
    return 1;
}
