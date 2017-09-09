#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StackPlates {
    private:
        vector<stack<int>> stacks;
        int stack_limit;

        void create_new_stack() {
            if (stacks.size() == 0 || stacks[0].size() == stack_limit) {
                stacks.push_back(stack<int>());
            }
        }

        void delete_stack() {
            while (!stacks.empty() && stacks[stacks.size() - 1].empty()) {
                stacks.pop_back();
            }
        }

    public:

        StackPlates(int limit) {
            stack_limit = limit;
        }

        void push(int data) {
            create_new_stack();
            int i = stacks.size() - 1;
            stacks[i].push(data);
        }

        int pop_at(int i) {
            int data = stacks[i].top();
            stacks[i].pop();
            delete_stack();
            return data;
        }

        int pop() {
            return pop_at(stacks.size() - 1);
        }
};

void insert(StackPlates* sp, int data) {
    sp->push(data);
    cout << "PUSH: " << data << endl;
}

void remove(StackPlates* sp) {
    cout << "POP: " << sp->pop() << endl;
}

void remove_at(StackPlates* sp, int i) {
    cout << "POP: " << sp->pop_at(i) << " AT: " << i << endl;
}

int main() {
    StackPlates sp(3);
    insert(&sp, 1);
    insert(&sp, 2);
    insert(&sp, 3);
    remove(&sp);
    insert(&sp, 4);
    insert(&sp, 5);
    remove_at(&sp, 0);
    insert(&sp, 6);
    remove(&sp);
    remove(&sp);
    remove(&sp);
    remove(&sp);
    return 0;
}
