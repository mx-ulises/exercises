#include <stack>
#include <iostream>

using namespace std;

class MaxStack {
    private:
        stack<int> s;
        stack<int> s_max;

    public:
        void push(int data) {
            s.push(data);
            if (s_max.empty() || s_max.top() <= data) {
                s_max.push(data);
            }
        }

        void pop() {
            int data = s.top();
            s.pop();
            if (s_max.top() == data) {
                s_max.pop();
            }
        }

        int max() {
            return s_max.top();
        }
};

int main() {
    MaxStack s;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int data;
            cin >> data;
            s.push(data);
        } else if (op == 2) {
            s.pop();
        } else if (op == 3) {
            cout << s.max() << endl;
        }
    }
    return 0;
}
