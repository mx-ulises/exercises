#include <map>
#include <iostream>

using namespace std;

class Trie {
    public:
        int character;
        map<char, Trie*>* children;

        Trie () {
            character = ' ';
            children = new map<char, Trie*>();
        }

        Trie (char c) {
            character = c;
            children = new map<char, Trie*>();
        }

        bool is_word(string* word, int i) {
            if (i == word->size())
                return (children->find('*') != children->end());
            char c = word->at(i);
            if (children->find(c) != children->end()) {
                return (*children)[c]->is_word(word, i + 1);
            } else {
                return false;
            }
        }

        bool is_word(string word) {
            return is_word(&word, 0);
        }

        void add_child(char c) {
            if (children->find(c) == children->end()) {
                (*children)[c] = new Trie(c);
            }
        }

        void set_word() {
            add_child('*');
        }

        void add_word(string* word, int i) {
            if (i == word->size()) {
                set_word();
            } else {
                char c = word->at(i);
                add_child(c);
                (*children)[c]->add_word(word, i + 1);
            }
        }

        void add_word(string word) {
            add_word(&word, 0);
        }
};

void add_word(Trie* t, string s) {
    t->add_word(s);
    cout << "Adding '" << s << "'" << endl;
}

void test_word(Trie* t, string s) {
    cout << "Word '" << s << "' is word: " << t->is_word(s) << endl;
}

int main() {
    Trie* t = new Trie();
    add_word(t, "books");
    test_word(t, "book");
    test_word(t, "books");
    test_word(t, "bookx");
    test_word(t, "boox");
    add_word(t, "book");
    test_word(t, "book");
    test_word(t, "books");
    test_word(t, "bookx");
    test_word(t, "boox");
    add_word(t, "");
    test_word(t, "");
    test_word(t, "book");
    test_word(t, "books");
    test_word(t, "bookx");
    test_word(t, "boox");
    return 0;
}
