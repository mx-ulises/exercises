#include <iostream>
#include <vector>


using namespace std;

class BT {
    public:
        int data;
        BT* right;
        BT* left;

        BT(int data) {
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }

        void print_tree(int h) {
            for (int i = 0; i < h; i++) {
                cout << "   ";
            }
            cout << data << endl;
            if (left != NULL) {
                left->print_tree(h + 1);
            }
            if (right != NULL) {
                right->print_tree(h + 1);
            }
        }
};

int get_path(vector<int>* sums, int k, int n) {
    int path_count = 0;
    for (int i = 0; i < sums->size(); i++) {
        if ((k - (*sums)[i]) == n)
            path_count++;
    }
    return path_count;
}

int paths_with_sum(BT* root, vector<int>* sums, int n) {
    if (root == NULL)
        return 0;
    int d = sums->size() - 1;
    int k = (*sums)[d] + root->data;
    int path_count = get_path(sums, k, n);
    sums->push_back(k);
    path_count += paths_with_sum(root->left, sums, n);
    path_count += paths_with_sum(root->right, sums, n);
    sums->pop_back();
    return path_count;
}

int paths_with_sum(BT* root, int n) {
    vector<int>* sums = new vector<int>();
    sums->push_back(0);
    int path_count = paths_with_sum(root, sums, n);
    delete sums;
    return path_count;
}

BT* build_tree() {
    BT* node_1 = new BT(1);
    BT* node_2 = new BT(2);
    BT* node_3 = new BT(1);
    BT* node_4 = new BT(2);
    BT* node_5 = new BT(-1);
    BT* node_6 = new BT(3);
    BT* node_7 = new BT(0);
    BT* node_8 = new BT(-3);
    node_1->left = node_2;
    node_1->right = node_3;
    node_2->left = node_4;
    node_2->right = node_5;
    node_3->left = node_6;
    node_3->right = node_7;
    node_4->right = node_8;
    return node_1;
}

int main() {
    BT* root = build_tree();
    root->print_tree(0);
    cout << "Total sum(2): " << paths_with_sum(root, 2) << endl;
    cout << "Total sum(1): " << paths_with_sum(root, 1) << endl;
}
