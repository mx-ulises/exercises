#include <vector>
#include <iostream>

using namespace std;

class Node {
    private:
        int data;
        int rank;

    public:
        Node* right;
        Node* left;
        Node* parent;

    Node(int x) {
        right = NULL;
        left = NULL;
        parent = NULL;
        rank = 1;
        data = x;
    }

    void insert(int x) {
        if (x < data) {
            if (left == NULL) {
                left = new Node(x);
                left->parent = this;
            } else {
                left->insert(x);
            }
            rank++;
        } else if (x == data) {
            rank++;
        } else {
            if (right == NULL) {
                right = new Node(x);
                right->parent = this;
            } else {
                right->insert(x);
            }
        }
    }

    int get_rank(int x) {
        if (x == data) return (rank - 1);
        else if (x < data) {
            if (left == NULL)
                return 0;
            else
                return left->get_rank(x);
        } else {
            if (right == NULL)
                return rank;
            else
                return rank + right->get_rank(x);
        }
    }
};

void test(int x, Node* root) {
    cout << "Rank of "<< x << " is " << root->get_rank(x) << endl;
}

int main() {
    Node root(5);
    root.insert(1);
    root.insert(4);
    root.insert(4);
    root.insert(5);
    root.insert(9);
    root.insert(7);
    root.insert(13);
    root.insert(3);
    test(1, &root);
    test(3, &root);
    test(4, &root);
    test(13, &root);
    test(14, &root);
    return 0;
}
