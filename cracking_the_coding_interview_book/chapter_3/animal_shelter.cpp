#include <queue>
#include <iostream>

#define DOG 1
#define CAT 2
#define ANY 3

using namespace std;

class AnimalShelter {
    private:
        queue<int> dogs;
        queue<int> cats;
        int last_time;

        void enqueue(queue<int>* q) {
            q->push(last_time);
            last_time++;
        }

    public:
        int get_cats() {
            return cats.size();
        }

        int get_dogs() {
            return dogs.size();
        }

        int get_animals() {
            return cats.size() + dogs.size();
        }

        void enqueue_dog() {
            enqueue(&dogs);
        }

        void enqueue_cat() {
            enqueue(&cats);
        }

        void dequeue_dog() {
            dogs.pop();
        }

        void dequeue_cat() {
            cats.pop();
        }

        void dequeue_any() {
            if (dogs.empty() || cats.front() < dogs.front()) {
                cats.pop();
            } else {
                dogs.pop();
            }
        }
};

void print_data(AnimalShelter* as) {
    cout << "Total cats: " << as->get_cats() << endl;
    cout << "Total dogs: " << as->get_dogs() << endl;
    cout << "Total animals: " << as->get_animals() << endl;
    cout << endl;
}

void insert(AnimalShelter* as, int type) {
    if (type == DOG) {
        as->enqueue_dog();
        cout << "Add new DOG" << endl;
    } else {
        as->enqueue_cat();
        cout << "Add new CAT" << endl;
    }
    print_data(as);
}

void remove(AnimalShelter* as, int type) {
    if (type == DOG) {
        as->dequeue_dog();
        cout << "Remove DOG" << endl;
    } else if (type == CAT) {
        as->dequeue_cat();
        cout << "Remove CAT" << endl;
    } else {
        as->dequeue_any();
        cout << "Remove ANY" << endl;
    }
    print_data(as);
}

int main() {
    AnimalShelter as;
    insert(&as, DOG);
    insert(&as, DOG);
    insert(&as, CAT);
    remove(&as, ANY);
    insert(&as, CAT);
    remove(&as, DOG);
    remove(&as, CAT);
    remove(&as, ANY);
    return 0;
}
