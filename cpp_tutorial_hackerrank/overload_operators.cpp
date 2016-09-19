#include<iostream>

using namespace std;

class Complex {
    public:
        int a, b;

        void input(string s) {
            int a = 0, b = 0, i = 0;
            while(s[i] != '+') {
                a = a * 10 + s[i] - '0';
                i++;
            }
            while(s[i] == ' ' || s[i] == '+' || s[i] == 'i') {
                i++;
            }
            while(i < s.length()) {
                b = b * 10 + s[i] - '0';
                i++;
            }
            this->a = a;
            this->b = b;
        }
};

Complex operator + (const Complex& X, const Complex& Y) {
    Complex result;
    result.a = X.a + Y.a;
    result.b = X.b + Y.b;
    return result;
}

ostream& operator << (ostream& os, const Complex& Y) {
    os << Y.a << "+i" << Y.b;
    return os;
}

int main() {
    Complex x, y;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z << endl;
}
