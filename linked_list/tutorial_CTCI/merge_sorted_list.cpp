struct Node {
    int data;
    struct Node* next;
};

Node* MergeLists(Node* head_a, Node* head_b) {
    if (head_a == NULL && head_b == NULL) {
        return NULL;
    }
    Node* head;
    if (head_b == NULL) {
        head = head_a;
        head_a = head_a->next;
    } else if (head_a == NULL) {
        head = head_b;
        head_b = head_b->next;
    } else if (head_a->data < head_b->data) {
        head = head_a;
        head_a = head_a->next;
    } else {
        head = head_b;
        head_b = head_b->next;
    }
    Node* current = head;
    while (head_a != NULL && head_b != NULL) {
        if (head_a->data < head_b->data) {
            current->next = head_a;
            head_a = head_a->next;
        } else {
            current->next = head_b;
            head_b = head_b->next;
        }
        current = current->next;
    }
    if (head_a == NULL) {
        current->next = head_b;
    }
    if (head_b == NULL) {
        current->next = head_a;
    }
    return head;
}
