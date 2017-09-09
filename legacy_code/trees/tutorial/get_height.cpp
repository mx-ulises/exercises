#include <iostream>
#include <cstddef>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }

};

Node* insert(Node* root, int data) {
    if(root == NULL)
        return new Node(data);
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int height(Node* root) {
    if (root == NULL)
        return -1;
    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    Node* root = NULL;
    int n;
    int data;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> data;
        root = insert(root, data);
    }
    cout << height(root);
    return 0;
}
