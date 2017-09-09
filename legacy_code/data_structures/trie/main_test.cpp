#include <iostream>
#include "trie.cpp"

int main(){
    int n;
    Trie t;
    cin >> n;
    for(int i = 0; i < n; i++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add") t.insert(contact);
        if (op == "find") cout << t.exist_word(contact) << endl;
    }
    return 0;
}

