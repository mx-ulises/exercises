#include <iostream>

using namespace std;

class Student {
    private:
        vector<int> scores;
    public:
        void input() {
            for (int i = 0; i < 5; i++) {
                int aux;
                cin >> aux;
                this->scores.push_back(aux);
            }
        }

        int calculateTotalScore() {
            int scores = 0;
            for (int i = 0; i < this->scores.size(); i++) {
                scores += this->scores[i];
            }
            return scores;
        }
};

int main() {
    int n;
    cin >> n;
    Student *s = new Student[n];

    for(int i = 0; i < n; i++){
        s[i].input();
    }

    int kristen_score = s[0].calculateTotalScore();

    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    cout << count;

    return 0;
}
