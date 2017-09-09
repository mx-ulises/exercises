#include <iostream>
#include <stdlib.h>

using namespace std;

class BT {
    private:
        int n;

        int size(BT* node) {
            if (node == NULL)
                return 0;
            else
                return node->n;
        }

    public:
        int data;
        BT* left;
        BT* right;
        BT* parent;

        BT(int value) {
            data = value;
            parent = NULL;
            right = NULL;
            left = NULL;
            n = 1;
        }

        BT* random() {
            int value = (rand() % n);
            if (value < size(left))
                return left->random();
            if (value < (size(left) + size(right)))
                return right->random();
            else
                return this;
        }

        void insert(int data) {
            n++;
            if (left == NULL) {
                left = new BT(data);
                left->parent = this;
            } else if (right == NULL) {
                right = new BT(data);
                right->parent = this;
            } else if (size(left) < size(right))
                left->insert(data);
            else
                right->insert(data);
        }
};

void insert(BT* bt, int data) {
    cout << "Inserting " << data << endl;
    bt->insert(data);
}

void test(BT* bt) {
    int data = bt->random()->data;
    cout << "Random node: " << data << endl;
}

int main() {
    BT* bt = new BT(1);
    cout << "New BT with 1" << endl;
    for (int i = 1; i < 10; i++)
        insert(bt, i + 1);
    test(bt);
    test(bt);
    test(bt);
    test(bt);
    test(bt);
    return 0;
}
