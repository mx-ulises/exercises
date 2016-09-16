#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string normalize_path(string path) {
    vector<string> stack_path;
    string normalized;
    string word;
    stringstream stream(path);
    while( getline(stream, word, '/') ) {
        if (!word.compare("..")) {
            stack_path.pop_back();
        } else if (!word.compare(".") || !word.compare("")) {
            continue;
        } else {
            stack_path.push_back(word);
        }
    }
    for (int i = 0; i < stack_path.size(); i++) {
        normalized.append("/");
        normalized.append(stack_path[i]);
    }
    return normalized;
}

int main() {
    string s = "/hello/world/here/../I/come";
    cout << normalize_path(s) << endl;
}
