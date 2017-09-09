#include <iostream>
#include <vector>

using namespace std;

class BST {
    private:
        BST* most_left() {
            if (left == NULL) {
                return this;
            } else {
                return left->most_left();
            }
        }

        BST* most_right() {
            if (right == NULL) {
                return this;
            } else {
                return right->most_right();
            }
        }

        BST* get_pred(BST* node) {
            if (right == node || left == node) return this;
            else if (node->data < data) {
                node->left->get_pred(node);
            } else {
                node->right->get_pred(node);
            }
        }

        void remove_node_link(BST* node) {
            BST* pred = get_pred(node);
            if (pred->left == node) {
                pred->left = NULL;
            } else {
                pred->right = NULL;
            }
            delete node;
        }

    public:
        int data;
        BST* left;
        BST* right;

        BST(int value) {
            data = value;
            left = NULL;
            right = NULL;
        }

        BST* find(int value) {
            if (data == value) {
                return this;
            } else if (value < data && left != NULL) {
                return left->find(value);
            } else if (data < value && right != NULL) {
                return right->find(value);
            } else {
                return NULL;
            }
        }

        void insert(int value) {
            if (value < data) {
                if (left == NULL) {
                    left = new BST(value);
                } else {
                    left->insert(value);
                }
            } else if (data < value) {
                if (right == NULL) {
                    right = new BST(value);
                } else {
                    right->insert(value);
                }
            }
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

vector<int>* new_comb(BST* node, vector<int>* c_1, vector<int>* c_2) {
    vector<int>* c = new vector<int>();
    c->push_back(node->data);
    for (int i = 0; i < c_1->size(); i++)
        c->push_back((*c_1)[i]);
    for (int i = 0; i < c_2->size(); i++)
            c->push_back((*c_2)[i]);
    return c;
}

vector<int>* new_comb(BST* node, vector<int>* c_1) {
    vector<int>* c = new vector<int>();
    c->push_back(node->data);
    for (int i = 0; i < c_1->size(); i++)
        c->push_back((*c_1)[i]);
    return c;
}

vector<int>* new_comb(BST* node) {
    vector<int>* c = new vector<int>();
    c->push_back(node->data);
    return c;
}

void combine(BST* node, vector<vector<int>*>* combs, vector<vector<int>*>* pref, vector<vector<int>*>* sufix) {
    if (pref == NULL)
        return;
    for (int i = 0; i < pref->size(); i++) {
        if (sufix != NULL) {
            for (int j = 0; j < sufix->size(); j++) {
                vector<int>* c = new_comb(node, (*pref)[i], (*sufix)[j]);
                combs->push_back(c);
            }
        } else {
            vector<int>* c = new_comb(node, (*pref)[i]);
            combs->push_back(c);
        }
    }
}

vector<vector<int>*>* get_combinations(BST* root) {
    if (root == NULL) {
        return NULL;
    }
    vector<vector<int>*>* combs = new vector<vector<int>*>();
    vector<vector<int>*>* c_left = get_combinations(root->left);
    vector<vector<int>*>* c_right = get_combinations(root->right);
    combine(root, combs, c_left, c_right);
    combine(root, combs, c_right, c_left);
    if (c_left == NULL && c_right == NULL)
        combs->push_back(new_comb(root));
    delete c_left;
    delete c_right;
    return combs;
}


void insert(BST* bst, int data) {
    bst->insert(data);
    cout << "Insert: " << data << endl;
}

void print_comb(vector<int>* c) {
    for (int i = 0; i < c->size(); i++) {
        cout << (*c)[i] << " ";
    }
    cout << endl;
}

void test(BST* bst) {
    int h = 0;
    vector<vector<int>*>* combs = get_combinations(bst);
    for (int i = 0; i < combs->size(); i++) {
        print_comb((*combs)[i]);
    }
}

int main() {
    BST bst(10);
    cout << "INIT: " << 10 << endl;
    insert(&bst, 2);
    insert(&bst, 3);
    insert(&bst, 4);
    insert(&bst, 1);
    insert(&bst, 21);
    insert(&bst, 12);
    insert(&bst, 14);
    insert(&bst, 40);
    insert(&bst, 50);
    cout << endl << "PRINT" << endl;
    bst.print_tree(0);
    test(&bst);
    return 0;
}

