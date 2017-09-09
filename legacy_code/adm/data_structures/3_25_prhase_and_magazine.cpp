// Search String and Magazine (ADM-3.25)

#include <map>
#include <iostream>

using namespace std;

map<char, int> count(string s) {
	map<char, int> char_count;
	for (int i = 0; i < s.size(); i++) {
		char c = s.at(i);
		char_count[c]++;
	}
	return char_count;
}

bool contains(map<char, int> A, map<char, int> B) {
	for(map<char, int>::iterator it = A.begin(); it != A.end(); it++) {
		char c = it->first;
		if (B.find(c) == B.end() || B[c] < A[c]) {
			cout << "Not enough '" << c << "' in magazine" << endl;
			return false;
		}
	}
	return true;
}

void test(string s, string magazine) {
	cout << "String: '" << s << "'" << endl;
	cout << "Magazine: '" << magazine << "'" << endl;
	map<char, int> char_count_s = count(s);
	map<char, int> char_count_magazine = count(magazine);
	if (contains(char_count_s, char_count_magazine))
		cout << "All characters in magazine" << endl;
	else
		cout << "Not all characters in magazine" << endl;
	cout << endl;
}

int main() {
	test("Hello", "Hello world");
	test("Hello world", "Hello world");
	test("Hello world", "world ");
	test("Hello world", "Hahahahaha");
}
