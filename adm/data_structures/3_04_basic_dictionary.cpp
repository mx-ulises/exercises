// Basic dictionary (ADM-3.4)

#include <iostream>
#include <vector>

#define N 256
#define SEGMENT 16

using namespace std;

class LLNode{
    public:
        int data;
        LLNode* next;

        LLNode(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class BasicDictionary {
    private:
        vector<LLNode*> container;

        LLNode* insert_ll(LLNode* head, int data) {
            LLNode* new_head = new LLNode(data);
            new_head->next = head;
            return new_head;
        }

        void print_list(LLNode* head) {
            LLNode* current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
        }

    public:
        BasicDictionary() {
            for (int i = 0; i < SEGMENT; i++) {
                container.push_back(NULL);
            }
        }

        bool exist(int x) {
            int container_index = x % SEGMENT;
            while (container[container_index] != NULL) {
                if (container[container_index]->data == x)
                    return true;
            }
            return false;
        }

        void insert(int x) {
            if (!exist(x)) {
                int container_index = x % SEGMENT;
                container[container_index] = insert_ll(container[container_index], x);
            }
        }

        void print() {
            for (int i = 0; i < SEGMENT; i++) {
                print_list(container[i]);
            }
            cout << endl;
        }
};

void print_list(BasicDictionary dict) {
    cout << "Printring list" << endl;
    dict.print();
}

void look_up(BasicDictionary dict, int x) {
    if (dict.exist(x)) {
        cout << "Element " << x << " exists" << endl;
    } else {
        cout << "Element " << x << " doesn't exist" << endl;
    }
}

int main() {
    BasicDictionary dict;
    print_list(dict);
    look_up(dict, 10);
    dict.insert(10);
    print_list(dict);
    look_up(dict, 10);
    look_up(dict, 11);
    dict.insert(1);
    dict.insert(16);
    print_list(dict);
    dict.insert(255);
    print_list(dict);
}
