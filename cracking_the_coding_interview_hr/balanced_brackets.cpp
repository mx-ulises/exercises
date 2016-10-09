#include <map>
#include <stack>
#include <iostream>

#define PUSH 1
#define POP 2

using namespace std;

map<char, int> operation;
map<char, char> poped_element;

void fill_globals() {
    operation['['] = operation['{'] = operation['('] = PUSH;
    operation[']'] = operation['}'] = operation[')'] = POP;
    poped_element[']'] = '[';
    poped_element['}'] = '{';
    poped_element[')'] = '(';
}

bool is_balanced(string s) {
    stack<char> checker;
    for (int i = 0; i < s.length(); i++) {
        char c = s.at(i);
        if (operation[c] == PUSH) {
            checker.push(c);
        } else if (operation[c] == POP) {
            if (checker.empty() || checker.top() != poped_element[c]) {
                return false;
            }
            checker.pop();
        } else {
            return false;
        }
    }
    return checker.empty();
}

int main(){
    fill_globals();
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string s;
        cin >> s;
        if (is_balanced(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
