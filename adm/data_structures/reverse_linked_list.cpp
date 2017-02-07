#include <stack>
#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

Node* reverse(Node* root) {
    if (root == NULL)
        return NULL;
    stack<Node*> s;
    Node* current = root;
    while (current != NULL) {
        s.push(current);
        current = current->next;
    }
    root = s.top();
    s.pop();
    current = root;
    while (!s.empty()) {
        current->next = s.top();
        s.pop();
        current = current->next;
    }
    return root;
}

Node* create_node(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    cout << data << " ";
    return node;
}

void test(int* A, int n) {
    Node* root = create_node(A[0]);
    Node* current = root;
    for (int i = 1; i < n; i++) {
        current->next = create_node(A[i]);
        current = current->next;
    }
    cout << endl;
    root = reverse(root);
    current = root;
    for (int i = 0; i < n; i++) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int A[5] = {1, 2, 3, 4, 5};
    test(A, 5);
    return 0;
}
