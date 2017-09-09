// Reverse a Linked List (ADM-3.23)

#include <stack>
#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

Node* reverse(Node* root) {
    stack<Node*> s;
    Node* current = root;
    while (current != NULL) {
        s.push(current);
        current = current->next;
    }
    if (s.size() == 0)
        return NULL;
    root = s.top();
    s.pop();
    current = root;
    while (0 < s.size()) {
        current->next = s.top();
        s.pop();
        current = current->next;
    }
    current->next = NULL;
    return root;
}

Node* create_node(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

void print_list(Node* root) {
    Node* current = root;
    cout << "Original list: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void test(int* A, int n) {
    Node* root = NULL;
    Node* current = root;
    for (int i = 0; i < n; i++) {
        if (root == NULL) {
            root = create_node(A[i]);
            current = root;
        } else {
            current->next = create_node(A[i]);
            current = current->next;
        }
    }
    print_list(root);
    root = reverse(root);
    print_list(root);
    cout << endl;
}

int main() {
    int A[5] = {1, 2, 3, 4, 5};
    test(A, 5);
    int B[4] = {1, 2, 3, 4};
    test(B, 4);
    int C[1] = {1};
    test(C, 1);
    test(C, 0);
    return 0;
}
