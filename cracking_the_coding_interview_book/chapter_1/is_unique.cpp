#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Optimal with memory usage
map<char, int>* get_character_count(string* s) {
    map<char, int>* char_count = new map<char, int>();
    for (int i = 0; i < s->size(); i++) {
        char c = s->at(i);
        (*char_count)[c]++;
    }
    return char_count;
}

bool check_single_elements(map<char, int>* char_count) {
    map<char, int>::iterator element = char_count->begin();
    while (element != char_count->end()) {
        if (element->second > 1) return false;
        element++;
    }
    return true;
}

bool is_unique(string s) {
    map<char, int>* character_count;
    character_count = get_character_count(&s);
    bool result = check_single_elements(character_count);
    delete character_count;
    return result;
}

// Brute force
bool is_unique_2(string s) {
    for (int i = 0; i < s.size(); i++) {
        char current = s.at(i);
        for (int j = i + 1; j < s.size(); j++) {
            char succesor = s.at(j);
            if (current == succesor)
                return false;
        }
    }
    return true;
}

// Sorting solution
vector<char>* get_vector(string* s) {
    vector<char>* s_vector = new vector<char>(s->size());
    for (int i = 0; i < s->size(); i++) {
        (*s_vector)[i] = s->at(i);
    }
    return s_vector;
}

bool check_single_element_2(vector<char>* s_vector) {
    for (int i = 1; i < s_vector->size(); i++) {
        if ((*s_vector)[i] == (*s_vector)[i - 1])
            return false;
    }
    return true;
}

bool is_unique_3(string s) {
    vector<char>* s_vector = get_vector(&s);
    sort(s_vector->begin(), s_vector->end());
    bool result = check_single_element_2(s_vector);
    delete s_vector;
    return result;
}

// Test code
int main() {
    string s = "abcd";
    cout << s << ": "<< is_unique(s) << endl;
    s = "";
    cout << s << ": "<< is_unique(s) << endl;
    s = "qqq";
    cout << s << ": "<< is_unique(s) << endl;
    s = "abcda";
    cout << s << ": "<< is_unique(s) << endl;
    return 0;
}
