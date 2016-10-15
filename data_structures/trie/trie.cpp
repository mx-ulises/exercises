#include <map>

using namespace std;

class TrieNode {
    private:
        char c;

    public:
        map<char, TrieNode*> children;

        TrieNode(char c) {
            this->c = c;
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
        }

        void set_word() {
            add_child('*');
        }
};

class Trie {
    private:
        TrieNode* root;

    public:

        Trie() {
            root = new TrieNode('*');
        }

        void insert(string word) {
            TrieNode* current = root;
            for (int i = 0; i < word.size(); i++) {
                char c = word.at(i);
                current->add_child(c);
                current = current->children[c];
            }
            current->set_word();
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
};
