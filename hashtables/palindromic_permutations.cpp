#include <map>
#include <string>
#include <iostream>

using namespace std;

bool exist_palindromic_permutation(string str){
	map<char, int> char_count;
	for (int i = 0; i < str.length(); i++) {
		char c = str.at(i);
		if (char_count.find(c) == char_count.end()) {
			char_count[c] = 0;
		}
		char_count[c]++;
	}
	int fail_count = 0;
	for (map<char, int>::iterator it = char_count.begin(); it != char_count.end(); ++it) {
		if (it->second % 2 == 1) {
			fail_count++;
		}
	}
	if (fail_count > 1) return false;
	return true;
}

void print_result(string str) {
	cout << "Testing string '" << str << "', result: ";
	if (exist_palindromic_permutation(str)) {
		cout << "TRUE";
	} else {
		cout << "FALSE";
	}
	cout << endl;
}

int main() {
	print_result("abcdabcd");
	print_result("aabbaba");
	print_result("");
	print_result("adssfdfdhqwegf");
	print_result("aaaaaaaaa");
	print_result("aaaaaaaaabc");
	print_result("aaaaaaaaab");
	print_result("ab");
	return 0;
}

