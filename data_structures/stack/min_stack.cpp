#include <iostream>
#include <stack>

using namespace std;

class MinStack {

    private:
        stack<int> s;
        stack<int> s_min;

    public:

        void push(int data) {
            s.push(data);
            if (s_min.empty() || data <= s_min.top()) {
                s_min.push(data);
            }
        }

        void pop() {
            int data = s.top();
            s.pop();
            if (data <= s_min.top()) {
                s_min.pop();
            }
        }

        int top() {
            return s.top();
        }

        int min() {
            return s_min.top();
        }
};

void push(MinStack* min_s, int item) {
    cout << "PUSHING: " << item << endl;
    min_s->push(item);
    cout << "TOP: "<< min_s->top() << " MIN: " << min_s->min() << endl << endl;
}

void pop(MinStack* min_s) {
    cout << "POPING: " << min_s->top() << endl;
    min_s->pop();
    cout << "TOP: "<< min_s->top() << " MIN: " << min_s->min() << endl << endl;
}

int main() {
    MinStack min_s;
    push(&min_s, 5);
    push(&min_s, 6);
    push(&min_s, 7);
    push(&min_s, 5);
    push(&min_s, 4);
    push(&min_s, 9);
    pop(&min_s);
    pop(&min_s);
    pop(&min_s);
    pop(&min_s);
    pop(&min_s);
    return 0;
}
