#include <iostream>
#include <algorithm>

using namespace std;

void count_letters(string a, char first, char last, int a_count[]) {
    int n = last - first + 1;
    for (int i = 0; i < a.size(); i++) {
        char c = a.at(i);
        a_count[c - first]++;
    }
}

int get_n_diff(int a_count[], int b_count[], char first, char last) {
    int n = last - first + 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += abs(a_count[i] - b_count[i]);
    }
    return count;
}

int number_needed(string a, string b) {
    char first = 'a';
    char last = 'z';
    int n = last - first + 1;
    int a_count[n] = {};
    int b_count[n] = {};
    count_letters(a, first, last, a_count);
    count_letters(b, first, last, b_count);
    return get_n_diff(a_count, b_count, first, last);
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
