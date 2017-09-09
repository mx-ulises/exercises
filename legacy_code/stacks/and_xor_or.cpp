#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int function(int m_1, int m_2) {
    int value = m_1 ^ m_2;
    return value;
}

int main() {
    stack<int> s;
    int t;
    int data;
    cin >> t;
    int max_val = 0;
    cin >> data;
    t--;
    s.push(data);
    for (int i = 0; i < t; i++) {
        cin >> data;
        while (!s.empty() && data < s.top()) {
            max_val = max(max_val, function(data, s.top()));
            s.pop();
        }
        if (!s.empty()) {
            max_val = max(max_val, function(data, s.top()));
        }
        if (s.empty() || s.top() < data) {
            s.push(data);
        }
    }
    cout << max_val << endl;
    return 0;
}
