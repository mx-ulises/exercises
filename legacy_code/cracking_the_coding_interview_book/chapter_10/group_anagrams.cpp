#include <iostream>
#include <vector>
#include <map>

using namespace std;

string get_key(string s) {
    map<char, int> count;
    for (int i = 0; i < s.size(); i++) {
        count[s.at(i)]++;
    }
    string key = "";
    for (char c = 'a'; c <= 'z'; c++) {
        if (count.find(c) != count.end()) {
            for (int i = 0; i < count[c]; i++) {
                key.push_back(c);
            }
        }
    }
    return key;
}

void group_anagrams(vector<string>* A) {
    map<string, vector<string>> count;
    for (int i = 0; i < A->size(); i++) {
        string key = get_key((*A)[i]);
        if (count.find(key) == count.end()) {
            count[key] = vector<string>();
        }
        count[key].push_back((*A)[i]);
    }
    int i = 0;
    for (map<string, vector<string>>::iterator it = count.begin(); it != count.end(); it++) {
        string key = it->first;
        for (int j = 0; j < count[key].size(); j++) {
            (*A)[i] = count[key][j];
            i++;
        }
    }
}

void print_array(vector<string> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << endl;
    }
    cout << "============================" << endl;
}

int main() {
    vector<string> A;
    A.push_back("a");
    A.push_back("aba");
    A.push_back("yz");
    A.push_back("x");
    A.push_back("zy");
    A.push_back("d");
    A.push_back("c");
    A.push_back("aab");
    A.push_back("baa");
    print_array(A);
    group_anagrams(&A);
    print_array(A);
    return 0;
}
