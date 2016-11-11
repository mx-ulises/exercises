#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class BinarySearchTree {
    private:
        BinarySearchTree* most_left() {
            if (left == NULL) {
                return this;
            } else {
                return left->most_left();
            }
        }

        BinarySearchTree* most_right() {
            if (right == NULL) {
                return this;
            } else {
                return right->most_right();
            }
        }

        BinarySearchTree* get_pred(BinarySearchTree* node) {
            if (right == node || left == node) return this;
            else if (node->data < data) {
                node->left->get_pred(node);
            } else {
                node->right->get_pred(node);
            }
        }

        void remove_node_link(BinarySearchTree* node) {
            BinarySearchTree* pred = get_pred(node);
            if (pred->left == node) {
                pred->left = NULL;
            } else {
                pred->right = NULL;
            }
            delete node;
        }

    public:
        int data;
        BinarySearchTree* left;
        BinarySearchTree* right;

        BinarySearchTree(int value) {
            data = value;
            left = NULL;
            right = NULL;
        }

        BinarySearchTree* find(int value) {
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
                    left = new BinarySearchTree(value);
                } else {
                    left->insert(value);
                }
            } else if (data < value) {
                if (right == NULL) {
                    right = new BinarySearchTree(value);
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

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }

        void print() {
            Node* current = this;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

class LinkedList {
    public:
        Node* root;

        void insert(int data) {
            if (root == NULL) {
                root = new Node(data);
            } else {
                Node* aux = root;
                root = new Node(data);
                root->next = aux;
            }
        }

        int size() {
            int n = 0;
            Node* current = root;
            while (current != NULL) {
                n++;
                current = current->next;
            }
            return n;
        }

        void print() {
            if (root != NULL) {
                root->print();
            }
        }

        Node* search(int data) {
            if (root == NULL)
                return NULL;
            Node* current = root;
            while (current != NULL) {
                if (current->data == data)
                    return current;
                current = current->next;
            }
            return NULL;
        }

};

void list_of_depths(map<int, LinkedList*>* lists, int h, BinarySearchTree* bst) {
    if (bst == NULL)
        return;
    if (lists->find(h) == lists->end())
        (*lists)[h] = new LinkedList();
    (*lists)[h]->insert(bst->data);
    list_of_depths(lists, h + 1, bst->right);
    list_of_depths(lists, h + 1, bst->left);
}

map<int, LinkedList*>* list_of_depths(BinarySearchTree* bst) {
    map<int, LinkedList*>* lists = new map<int, LinkedList*>();
    list_of_depths(lists, 0, bst);
    return lists;
}

void insert(BinarySearchTree* bst, int data) {
    bst->insert(data);
    cout << "Insert: " << data << endl;
}

void test(BinarySearchTree* bst) {
    map<int, LinkedList*>* lod = list_of_depths(bst);
    int i = 0;
    while (lod->find(i) != lod->end()) {
        (*lod)[i]->print();
        i++;
    }
}

int main() {
    BinarySearchTree bst(10);
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
