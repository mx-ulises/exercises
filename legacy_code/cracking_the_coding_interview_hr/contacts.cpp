#include <iostream>
#include <map>

using namespace std;

class TrieNode {
    private:
        char c;
        int prefix_count;

    public:
        map<char, TrieNode*> children;

        TrieNode(char c) {
            this->c = c;
            this->prefix_count = 0;
        }

        bool exist_child(char c) {
            if (children.find(c) != children.end()) return true;
            return false;
        }

        bool is_word() {
            return exist_child('*');
        }

        void add_child(char c) {
            if (!exist_child(c)) {
                children[c] = new TrieNode(c);
            }
            prefix_count++;
        }

        void set_word() {
            add_child('*');
        }

        int count() {
            return prefix_count;
        }
};

class Trie {
    private:
        TrieNode* root;

    public:

        Trie() {
            root = new TrieNode('*');
        }

        bool exist_word(string word) {
            TrieNode* current = root;
            for (int i = 0; i < word.size(); i++) {
                char c = word.at(i);
                if (!current->exist_child(c)) {
                    return false;
                }
                current = current->children[c];
            }
            return current->is_word();
        }

        void insert(string word) {
            if (exist_word(word)) return;
            TrieNode* current = root;
            for (int i = 0; i < word.size(); i++) {
                char c = word.at(i);
                current->add_child(c);
                current = current->children[c];
            }
            current->set_word();
        }

        int prefix_count(string word) {
            TrieNode* current = root;
            for (int i = 0; i < word.size(); i++) {
                char c = word.at(i);
                if (!current->exist_child(c)) {
                    return 0;
                }
                current = current->children[c];
            }
            return current->count();
        }
};

int main(){
    int n;
    Trie t;
    cin >> n;
    for(int i = 0; i < n; i++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add") t.insert(contact);
        if (op == "find") cout << t.prefix_count(contact) << endl;
    }
    return 0;
}
