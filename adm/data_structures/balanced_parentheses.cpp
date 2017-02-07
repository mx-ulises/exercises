#include <stack>
#include <iostream>

using namespace std;

int is_balanced(string s) {
	stack<char> s_2;
	int i = 0;
	for (i = 0; i < s.size(); i++) {
		if (s.at(i) == '(')
			s_2.push('(');
		else if (s.at(i) != ')' || s_2.size() == 0) {
			return i;
		} else {
			s_2.pop();
		}

	}
	if (s_2.size() != 0)
		return i;
	return -1;
}

void test(string s) {
	int position = is_balanced(s);
	cout << "'" << s << "'" << endl;
	if (position == -1)
		cout << "String balanced" << endl;
	else
		cout << "Balanced lost at " << position << endl;
	cout << endl;
}

int main() {
	test("(()())");
	test("(()())()");
	test("()(()())");
	test("(())())");
	test(")(()())");
	test("");
	test("(");
	return 0;
}
