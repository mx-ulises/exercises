#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* right;
        Node* left;

        Node(int value) {
            data = value;
            right = NULL;
            left = NULL;
        }
};

bool match_tree(Node* bt_1, Node* bt_2) {
    if (bt_1 == NULL && bt_2 == NULL)
        return true;
    if (bt_1 == NULL || bt_2 == NULL)
        return false;
    if (bt_1->data != bt_2->data)
        return false;
    return (match_tree(bt_1->left, bt_2->left) && match_tree(bt_1->right, bt_2->right));
}

bool check_subtree(Node* bt_1, Node* bt_2) {
    if (bt_1 == NULL)
        return false;
    if (match_tree(bt_1, bt_2))
        return true;
    else
        return (check_subtree(bt_1->left, bt_2) || check_subtree(bt_1->right, bt_2));
}

bool contains(Node* bt_1, Node* bt_2) {
    if (bt_2 == NULL) return true;
    return check_subtree(bt_1, bt_2);
}
