#include <queue>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void level_order(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node != NULL) {
            cout << node->data << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << endl;
}
