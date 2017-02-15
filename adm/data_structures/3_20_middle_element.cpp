// Middle Element in a Linked List (ADM-3.20)

#include <stack>
#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

Node* middle(Node* root) {
	Node* current = root;
	Node* runner = root;
	while (runner != NULL and runner->next != NULL) {
		current = current->next;
		runner = runner->next->next;
	}
	return current;
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
    Node* m =  middle(root);
    cout << m->data << endl << endl;
}

int main() {
    int A[5] = {1, 2, 3, 4, 5};
    test(A, 5);
    int B[4] = {1, 2, 3, 4};
    test(B, 4);
    int C[1] = {1};
    test(C, 1);
    return 0;
}
