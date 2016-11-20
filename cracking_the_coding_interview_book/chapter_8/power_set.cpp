#include <set>
#include <iostream>

using namespace std;

void add_new_sets(set<set<char>>* power_set, set<set<char>>* new_sets) {
    for (set<set<char>>::iterator ns = new_sets->begin(); ns != new_sets->end(); ns++) {
        power_set->insert((*ns));
    }
}

set<set<char>>* get_new_sets(char c, set<set<char>>* power_set) {
    set<set<char>>* new_sets = new set<set<char>>();
    for (set<set<char>>::iterator s = power_set->begin(); s != power_set->end(); s++) {
        set<char> ns = (*s);
        ns.insert(c);
        new_sets->insert(ns);
    }
    return new_sets;
}

set<set<char>> get_power_set(set<char> original) {
    set<set<char>> power_set;
    set<char> empty_set;
    power_set.insert(empty_set);
    for (set<char>::iterator c = original.begin(); c != original.end(); c++) {
        set<set<char>>* new_sets = get_new_sets((*c), &power_set);
        add_new_sets(&power_set, new_sets);
        delete new_sets;
    }
    return power_set;
}

void print_set(set<char> s) {
    cout << "'";
    for (set<char>::iterator c = s.begin(); c != s.end(); c++) {
        cout << (*c) << " ";
    }
    cout << "'" << endl;
}

void print_sets(set<set<char>>* power_set) {
    for (set<set<char>>::iterator s = power_set->begin(); s != power_set->end(); s++) {
        print_set((*s));
    }
}

int main() {
    set<char> original;
    original.insert('a');
    original.insert('b');
    original.insert('c');
    original.insert('d');
    set<set<char>> power_set = get_power_set(original);
    print_sets(&power_set);
}
